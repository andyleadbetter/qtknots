
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
    , _tickCount( 0 )
{
    _properties = new KnotsPlayerProperties;
    _propertiesUpdateTimer = new QTimer();
    _backlightTimer = new QTimer();

    _propertiesUpdateTimer->setSingleShot(false);

    connect(_propertiesUpdateTimer, SIGNAL(timeout()), this, SLOT( updateTimeout()));

    connect(_backlightTimer, SIGNAL(timeout()), this, SLOT(onBacklightTimer()));

    connect( _properties, SIGNAL(propertiesUpdated()), this, SLOT(onPropertiesUpdated()));
    connect( &_serverConnection, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));

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
    _tickCount = 0;

    _playRequest = _serverConnection.get(QNetworkRequest(url));
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

    _stopRequest = _serverConnection.get(QNetworkRequest(url));

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



void KnotsPlayer::seek( float newPosition )
{

    double percentage = 1.0  - ( duration() - newPosition ) / duration();

    stopObservingProperties();


    unsigned int seekChange = 100 * ( percentage - _properties->_position.toFloat() );

    if( seekChange == 0 )
    {
        return;
    }

    QUrl url = Knots::instance().serverAddress();
    url.setPath( "/external/seek");
    url.addQueryItem("player_id", _playerId );
    url.addQueryItem("position", QString::number( percentage )  );


    _seekRequest = _serverConnection.get(QNetworkRequest(url));
    _status = Seeking;
}

void KnotsPlayer::seekRequestFinished(QNetworkReply* reply)
{

    //qWarning() << "Fetched from " << reply->url() ;
    //qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
    //qWarning() << reply->peek( reply->bytesAvailable());

    reply->deleteLater();
    _status = Playing;
    emit stateChanged(_status);

    startObservingProperties();
}


int KnotsPlayer::duration()
{
    return _properties->_duration.toInt();
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
    _properties->updateStatus(_playerId, _password);

    // timer to tick every second, but only sync with server every 60
    _propertiesUpdateTimer->start(1000);

}

void KnotsPlayer::stopObservingProperties()
{
    _propertiesUpdateTimer->stop();
}

void KnotsPlayer::onPropertiesUpdated()
{
    switch( _status )
    {
    case WaitingForPortInfo:        
        {
        // Do initial properties change while Waiting State so that initial slider change
        // does not trigger seek
        emit propertiesChanged(*_properties);
        // Let declarative update
        startObservingProperties();

        // Now begin to play
        _status = Playing;
        emit stateChanged(_status);

        break;
       }
    default:
        emit propertiesChanged(*_properties);
       // qWarning() << "Default State in properties update";
        break;
    };
}

KnotsPlayerProperties& KnotsPlayer::properties()
{
    return *_properties;
}

void KnotsPlayer::updateTimeout()
{
    // Once per minute goto network update
    if( ++_tickCount % 10 == 0)
        _properties->updateStatus(_playerId,_password);
    else // Local update
    {
        float duration = _properties->_duration.toFloat() ;
        float position = duration * _properties->_position.toFloat();

        position += 1.0;

        position = 1.0 - ( duration - position ) / duration  ;

        _properties->_position = QString::number(position);

        onPropertiesUpdated();
    }
}
