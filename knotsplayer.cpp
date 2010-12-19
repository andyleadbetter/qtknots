
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
{
    _properties = new KnotsPlayerProperties;
    _propertiesUpdateTimer = new QTimer();
    _backlightTimer = new QTimer();

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


    _playRequest = _serverConnection.get(QNetworkRequest(url));
    _status = WaitingForPortInfo;


}


void KnotsPlayer::stop()
{
    QUrl url = Knots::instance().serverAddress();
    url.setPath( "/root/stop");
    url.addQueryItem("id",_playerId);

    _stopRequest = _serverConnection.get(QNetworkRequest(url));

}


void KnotsPlayer::seek( float newPosition )
{
    double percentage = 1.0  - ( duration() - newPosition ) / duration();

    QUrl url = Knots::instance().serverAddress();
    url.setPath( "/external/seek");
    url.addQueryItem("player_id", _playerId );
    url.addQueryItem("position", QString::number( percentage )  );


    _seekRequest = _serverConnection.get(QNetworkRequest(url));
    _status = Seeking;
}


float KnotsPlayer::duration()
{
    return _properties->_duration.toFloat()*1000;
}

void KnotsPlayer::requestFinished( QNetworkReply* reply)
{
    if( reply == _playRequest )
        startRequestFinished(reply);
    else if( reply == _stopRequest )
        stopRequestFinished(reply);


    updateTimeout();

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

    startBacklightKeepAlive();


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


void KnotsPlayer::startBacklightKeepAlive()
{
    _backlightTimer->start(5000);
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

void KnotsPlayer::seekRequestFinished(QNetworkReply* reply)
{

    //qWarning() << "Fetched from " << reply->url() ;
    //qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
    //qWarning() << reply->peek( reply->bytesAvailable());

    reply->deleteLater();

    _properties->updateStatus(_playerId,_password);
}


void KnotsPlayer::startObservingProperties()
{
    _properties->updateStatus(_playerId, _password);
    _propertiesUpdateTimer->start(60000);

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
        QString source(  _properties->_streamUrl.toString() );
        _status = Playing;
        startObservingProperties();
        emit stateChanged(_status);
        break;
       }
    default:
       // qWarning() << "Default State in properties update";
        break;
    };

    emit propertiesChanged(*_properties);
}

KnotsPlayerProperties& KnotsPlayer::properties()
{
    return *_properties;
}

void KnotsPlayer::updateTimeout()
{
    _properties->updateStatus(_playerId,_password);
}
