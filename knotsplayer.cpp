
#include "knotsplayer.h"

#include <QDebug>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "knots.h"
#include "knotsplayerproperties.h"





KnotsPlayer::KnotsPlayer( QObject *parent )
    : QObject( parent )
    , _status( Stopped )
    , _tickPeriod( KOneSecond )
    , _tickCount( 0 )
    , _properties( 0 )
{
    _properties = new KnotsPlayerProperties;
    _propertiesUpdateTimer = new QTimer();
    _backlightTimer = new QTimer();

    Knots::instance().setPlayer( this );

    _propertiesUpdateTimer->setSingleShot(false);

    connect(_propertiesUpdateTimer, SIGNAL(timeout()), this, SLOT( updateTimeout()));

    connect(_backlightTimer, SIGNAL(timeout()), this, SLOT(onBacklightTimer()));

    connect( _properties, SIGNAL(propertiesUpdated()), this, SLOT(networkPropertiesUpdated()));

    connect( &Knots::instance().serverConnection(), SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));

    connect( this, SIGNAL(stateChanged(KnotsPlayer::PlayingState)), Knots::instance().mainWindow(), SLOT(onPlayerStateChange(KnotsPlayer::PlayingState)));

#if defined(Q_WS_MAEMO_5)
    _ossoContext = osso_initialize("QtKnots","1.0",true, 0);
#endif

}

KnotsPlayer::~KnotsPlayer()
{
#if defined(Q_WS_MAEMO_5)
    osso_deinitialize( _ossoContext );
#endif
    delete _properties;
}

void KnotsPlayer::play( QString& id )
{
    QUrl url = Knots::instance().serverAddress();
    url.setPath( "/external/play" );
    url.addQueryItem("profile",Knots::instance().profile());
    url.addQueryItem("id",id);

    _localPosition =_tickCount = 0;

    _playRequest = Knots::instance().serverConnection().get(QNetworkRequest(url));
    _status = WaitingForPortInfo;
}



void KnotsPlayer::startRequestFinished(QNetworkReply* reply)
{
    qWarning() << "Fetched from " << reply->url() ;
    qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
    qWarning() << reply->peek( reply->bytesAvailable());

    QString returnedData = reply->readAll();

    returnedData.remove("END_CONTENT");

    QStringList tokens = returnedData.split(':');
    _playerId = tokens[0];
    _password = tokens[1];

    reply->deleteLater();
    _playRequest = 0;

    _properties->updateStatus(_playerId, _password);
}

void KnotsPlayer::stop()
{
    QUrl url = Knots::instance().serverAddress();
    url.setPath( "/root/stop");
    url.addQueryItem("id",_playerId);

    _stopRequest = Knots::instance().serverConnection().get(QNetworkRequest(url));

}
void KnotsPlayer::stopRequestFinished(QNetworkReply* reply)
{

    qWarning() << "Fetched from " << reply->url() ;
    qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
    qWarning() << reply->peek( reply->bytesAvailable());

    QString returnedData = reply->readAll();

    _stopRequest = 0;

    reply->deleteLater();
    stopObservingProperties();
    _status = Stopped;
    emit stateChanged(_status);


    stopBacklightKeepAlive();

}



void KnotsPlayer::seek( int newPosition )
{

    float percentage = (float) newPosition / (float) _properties->_duration;

    _localPosition = newPosition;

    stopObservingProperties();

    QUrl url = Knots::instance().serverAddress();
    url.setPath( "/external/seek");
    url.addQueryItem("player_id", _playerId );
    url.addQueryItem("position", QString::number( percentage )  );


    _seekRequest = Knots::instance().serverConnection().get(QNetworkRequest(url));
    _status = Seeking;
    emit stateChanged(_status);
}

void KnotsPlayer::seekRequestFinished(QNetworkReply* reply)
{

    qWarning() << "Fetched from " << reply->url() ;
    //qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
    //qWarning() << reply->peek( reply->bytesAvailable());

    reply->deleteLater();
    _status = Playing;
    emit stateChanged(_status);

    startObservingProperties();
}


int KnotsPlayer::getDuration()
{
    return _properties->_duration;
}

void KnotsPlayer::requestFinished( QNetworkReply* reply)
{
    if( reply == _playRequest )
        startRequestFinished(reply);
    else if( reply == _stopRequest )
        stopRequestFinished(reply);
    else if( reply == _seekRequest )
        seekRequestFinished(reply);
}




void KnotsPlayer::startBacklightKeepAlive()
{
    _backlightTimer->start(20000);
}

void KnotsPlayer::stopBacklightKeepAlive()
{
    _backlightTimer->stop();
}

void KnotsPlayer::onBacklightTimer()
{
#if defined(Q_WS_MAEMO_5)
    osso_return_t err = osso_display_state_on(_ossoContext);
    qWarning() << "Turned on display for playback with result " << err;

    err = osso_display_blanking_pause( _ossoContext );
    qWarning() << "Request backlight result " << err ;
#endif
}



void KnotsPlayer::startObservingProperties()
{

    qDebug() << "Start observing with period " << _tickPeriod;

    // timer to tick every second, but only sync with server every 60
    _propertiesUpdateTimer->start(_tickPeriod);

}

void KnotsPlayer::stopObservingProperties()
{
    _propertiesUpdateTimer->stop();
}

void KnotsPlayer::onPropertiesUpdated()
{
    switch( _status )
    {
    case Playing:
    {
        QString newLabel = getFormattedPosition();
        emit formattedPositionChanged(newLabel);
        emit durationChanged(_properties->_duration);
        emit positionChanged( _localPosition );
        emit propertiesChanged(*_properties);
        break;
    }

    default:
        emit propertiesChanged(*_properties);       
        break;
    };

}

void KnotsPlayer::networkPropertiesUpdated()
{
    // when network properties retrieved,
    // first set if status is WaitingForPortInfo then
    // setup the source and url info,
    // the video.
    if( _status == WaitingForPortInfo )
    {
        // Do initial properties change while Waiting State so that initial slider change
        // does not trigger seek
        emit sourceChanged(_properties->_streamUrl);

        _localPosition = _properties->_duration * _properties->_position;

        // Now begin to play
        _status = Playing;
        emit stateChanged(_status);
    }

    // When the network properties are returned,
    // calculate the drift between server position
    // and local position and adjust timeout interval to
    // resync over the next 60 beats.
    float  drift = _localPosition - ( _properties->_duration * _properties->_position );

    // we count in MS for the local tick, so adjust the number of MS between ticks
    // to compensate for the drift, double the adjustment since we are compensating for
    // two periods

    _tickPeriod = 1000 - ( drift / KNetworkCadence );

    // restart observations with drift compensation.
    stopObservingProperties();
    startObservingProperties();

    onPropertiesUpdated();

}


KnotsPlayerProperties& KnotsPlayer::properties()
{
    return *_properties;
}

void KnotsPlayer::updateTimeout()
{
    // Once per minute goto network update
    if( ++_tickCount % KNetworkCadence == 0)
    {
        _properties->updateStatus(_playerId,_password);
    }
    else // Local update
    {
        _localPosition++;

        onPropertiesUpdated();
    }
}

QString KnotsPlayer::getFormattedPosition()
{
    int durationMins = _properties->_duration / 60;
    int durationSecs = _properties->_duration - ( durationMins * 60 );


    int positionMins = (int) _localPosition / 60;
    int positionSecs = (int) _localPosition % 60;

    QString timeLabel= QString( "%3:%4/%1:%2" )\
            .arg(QString::number(durationMins),2, '0')\
            .arg(QString::number(durationSecs),2, '0')\
            .arg(QString::number(positionMins),2, '0')\
            .arg(QString::number(positionSecs),2, '0');

    return timeLabel;
}

KnotsPlayer::PlayingState KnotsPlayer::getState()
{
    return _status;
}


QString KnotsPlayer::getCurrentSource()
{
    return _properties->_streamUrl;
}

int KnotsPlayer::getPosition()
{
    return _localPosition;
}

