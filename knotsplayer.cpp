
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
//    _playerBackend = new QMediaPlayer;
//    connect(_playerBackend, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));

//    _playerBackend->setVolume(50);

//    _videoWidget = new QVideoWidget(parent);
//    _playerBackend->setVideoOutput(_videoWidget);




    connect( _properties, SIGNAL(propertiesUpdated()), this, SLOT(onPropertiesUpdated()));
    connect( &_serverConnection, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
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


void KnotsPlayer::seek()
{

}

void KnotsPlayer::requestFinished( QNetworkReply* reply)
{
    if( reply == _playRequest )
        startRequestFinished(reply);
    else if( reply == _stopRequest )
        stopRequestFinished(reply);

    startObservingProperties();

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

}

void KnotsPlayer::stopRequestFinished(QNetworkReply* reply)
{

    qWarning() << "Fetched from " << reply->url() ;
    qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
    qWarning() << reply->peek( reply->bytesAvailable());

    QString returnedData = reply->readAll();

    _stopRequest = 0;

    reply->deleteLater();

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

}

void KnotsPlayer::onPropertiesUpdated()
{
    switch( _status )
    {
    case WaitingForPortInfo:        
//        _playerBackend->setMedia(_properties->_streamUrl);
//        _playerBackend->play();
        QString source(  _properties->_streamUrl.toString() );
        emit sourceChanged(source);

         _status = Playing;
        break;

    };
}

void KnotsPlayer::positionChanged( qint64 newPosition)
{
}

void  KnotsPlayer::setVideoRect(int x, int y, int width, int height )
{
    QRect geometry(x,y,width, height);
    _videoWidget->setGeometry(geometry);
    _videoWidget->show();
}

