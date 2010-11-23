
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

    connect(_propertiesUpdateTimer, SIGNAL(timeout()), this, SLOT( updateTimeout()));
    connect( _properties, SIGNAL(propertiesUpdated()), this, SLOT(onPropertiesUpdated()));
    connect( &_serverConnection, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
}

KnotsPlayer::~KnotsPlayer()
{
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


    startObservingProperties();

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

}

void KnotsPlayer::seekRequestFinished(QNetworkReply* reply)
{

    qWarning() << "Fetched from " << reply->url() ;
    qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
    qWarning() << reply->peek( reply->bytesAvailable());

    reply->deleteLater();
}


void KnotsPlayer::startObservingProperties()
{
    _properties->updateStatus(_playerId, _password);
    _propertiesUpdateTimer->start(10000);

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
        emit stateChanged(_status);
        break;
       }
    default:
        qWarning() << "Default State in properties update";
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
