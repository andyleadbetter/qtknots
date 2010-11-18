#include <QtDebug>
#include <QtOpenGL/QGLWidget>
#include <qdeclarative.h>



#include "knots.h"
#include "profile.h"
#include "saxprofilehandler.h"
#include "knotsdirectory.h"
#include "knotsitem.h"
#include "knotsplayer.h"
#include "knotsdeclarative.h"


Knots* Knots::_instance;

Knots& Knots::instance()
{
    if( Knots::_instance == 0 )
        Knots::_instance = new Knots();

    return *Knots::_instance;
}

Knots::Knots(QObject *parent)
    : QObject(parent)
    , _serverAddress("")
    , _currentPath("")
    , _currentDirectory(0)
    , _settings("AndyLeadbetter", "QtKnots")
    , _navigator( 0, true )
    , _videoPlayer( 0, false)
{  
    qmlRegisterType<KnotsDeclarative>("Knots", 1, 0, "Knots");

    qmlRegisterType<ProfileList>("ProfilesList", 1, 0,"ProfilesList");

    qmlRegisterType<KnotsDirectory>("KnotsDirectory", 1, 0,"KnotsDirectory");

    _navigator.setOrientation(QmlApplicationViewer::Auto);
    _videoPlayer.setOrientation(QmlApplicationViewer::Auto);

    _navigator.setMainQmlFile("qrc:///qml/QKnots.qml");

    _videoPlayer.setMainQmlFile("qrc://qml/common/PlayingView.qml");

    _navigator.show();

    loadSettings();

    loadProfiles();

    browseRoot();

    _player = new KnotsPlayer( this );

    connect( _player, SIGNAL(stateChanged(PlayingState)), this, SLOT(onPlayerStateChange(KnotsPlayer::PlayingState)));

}

KnotsPlayer& Knots::player()
{
    return *_player;
}

void Knots::loadSettings()
{
    _serverAddress = _settings.value( "ServerAddress", QString("Http://192.168.0.28:1978")).toString();
    _profile = _settings.value( "DefaultProfileId", QString( "6") ).toString();
}

QString Knots::profile() const
{
    return _profile;
}

void Knots::setProfile( QString &newProfile )
{

    Profile *profile = _profiles->values().at(newProfile.toInt());

    if( profile )
        _profile = profile->getId();

    _settings.setValue("DefaultProfileId", _profile );

}

QUrl Knots::serverAddress() const
{
    return _serverAddress;
}

void Knots::setServerAddress( QUrl &newServerAddress )
{
    _serverAddress = newServerAddress;
    browseRoot();
}



void Knots::loadProfiles() {

    try {

        _profiles = new ProfileListImpl();

        handler = new SaxProfileHandler(*_profiles);

        QUrl requestAddress = _serverAddress;

        requestAddress.setPath(+ "/external/transcoding_profiles");

        QNetworkRequest request( requestAddress );

        currentDownload = serverConnection.get(request);

        _xmlSource = new QXmlInputSource( currentDownload );

        _xmlReader.setContentHandler(handler);

        connect(&serverConnection, SIGNAL(finished(QNetworkReply*)),
                 this, SLOT(onProfilesFetched(QNetworkReply*)));
    }

    catch(...)
    {
        qWarning() << "Failed to fetch profiles";
    }
}

void Knots::onProfilesFetched( QNetworkReply* reply )
{
    qWarning() << "Fetched from " << reply->url() ;
    qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
    qWarning() << reply->peek( 256 );


    _xmlReader.parse(_xmlSource );

    delete _xmlSource;


    currentDownload->deleteLater();

    emit profilesChanged(_profiles);
}

void Knots::browseRoot()
{
    _currentPath = "/external/browse";
    loadDirectory(_currentPath);
    emit directoryChanged(_currentDirectory);
}

void Knots::browseByPath( QString &pathToBrowse )
{
    QString qualifiedDir;

    qualifiedDir = "/external/browse?limit=10000&path=" + pathToBrowse;
    _pathHistory.push(_currentPath);
    _currentPath = qualifiedDir ;
    loadDirectory(qualifiedDir);
    emit directoryChanged(_currentDirectory);
}

void Knots::browseVirtual( QString &virtualPath )
{
    QString qualifiedDir("/external/browse?limit=10000&virtual=");
    qualifiedDir += virtualPath ;

    _pathHistory.push(_currentPath);
    _currentPath = qualifiedDir ;
    loadDirectory(qualifiedDir);
    emit directoryChanged(_currentDirectory);
}




QString Knots::currentPath() const
{
    return _serverAddress.toString() + _currentPath;
}

void Knots::backSelected()
{
    if(! _pathHistory.isEmpty() ) {
        _currentPath = _pathHistory.pop();
        loadDirectory(_currentPath);
    } else {
        browseRoot();
    }
}

void Knots::loadDirectory(QString &newPath)
{
    QString request;

    request=_serverAddress.toString();
    request += newPath;
    KnotsDirectoryImpl* newDir = KnotsDirectoryImpl::browseByPath(request);

    if( newDir )
    {
        connect( newDir, SIGNAL(directoryChanged()), this, SLOT(onDirectoryReady()));

        delete _currentDirectory;
        _currentDirectory = newDir;
    }
}


void Knots::onDirectoryReady()
{
    emit directoryChanged( _currentDirectory );
}


void Knots::onPlayerStateChange( KnotsPlayer::PlayingState newState )
{
    if( KnotsPlayer::Playing == newState )
    {
        _videoPlayer.show();
        _navigator.hide();
    } else {
        _videoPlayer.show();
        _navigator.hide();
    }


}
