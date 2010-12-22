#include <QtDebug>
#include <QtOpenGL/QGLWidget>
#include <qdeclarative.h>
#include <QMainWindow>


#include "knots.h"
#include "profile.h"
#include "saxprofilehandler.h"
#include "knotsdirectory.h"
#include "knotsitem.h"
#include "knotsplayer.h"
#include "knotsdeclarative.h"


Knots* Knots::_instance = 0;

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
{  

    loadSettings();

    loadProfiles();


    _player = new KnotsPlayer( this );
    _currentDirectory = new KnotsDirectory(this);

    connect( _currentDirectory , SIGNAL(directoryChanged()), this, SLOT(onDirectoryReady()));

}

void Knots::launch()
{
    browseRoot();

    _mainWindow = new MainWindow;

    _mainWindow->launch();

    connect( _player, SIGNAL(stateChanged(KnotsPlayer::PlayingState)), this, SLOT(onPlayerStateChange(KnotsPlayer::PlayingState)));
    connect( _player, SIGNAL(stateChanged(KnotsPlayer::PlayingState)), _mainWindow, SLOT(onPlayerStateChange(KnotsPlayer::PlayingState)));
    connect(&serverConnection, SIGNAL(finished(QNetworkReply*)), this, SLOT(onProfilesFetched(QNetworkReply*)));
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
    _settings.setValue( "ServerAddress", _serverAddress);
    delete _profiles;
    delete handler;
    loadProfiles();
    browseRoot();
}



void Knots::loadProfiles() {

    try {

        _profiles = new ProfileListImpl();

        handler = new SaxProfileHandler(*_profiles);

        QUrl requestAddress = _serverAddress;

        requestAddress.setPath(+ "/external/transcoding_profiles");

        QNetworkRequest request( requestAddress );

        _profileFetch = serverConnection.get(request);

    }

    catch(...)
    {
        qWarning() << "Failed to fetch profiles";
    }
}

void Knots::onProfilesFetched( QNetworkReply* reply )
{
    if( reply == _profileFetch )
    {
        _xmlSource = new QXmlInputSource( _profileFetch );
        _xmlReader = new QXmlSimpleReader;
        _xmlReader->setContentHandler(handler);

        qWarning() << "Fetched from " << reply->url() ;
        qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
        qWarning() << reply->peek( 256 );


        _xmlReader->parse(_xmlSource );

        delete _xmlSource;
        delete _xmlReader;
        _xmlReader = 0;


        _profileFetch->deleteLater();

        emit profilesChanged(_profiles);
    }
}

void Knots::browseRoot()
{
    _currentPath = "/external/browse";
    loadDirectory(_currentPath);    
}

void Knots::browseByPath( QString &pathToBrowse )
{
    QString qualifiedDir;

    qualifiedDir = "/external/browse?path=" + pathToBrowse;
    _pathHistory.push(_currentPath);
    _currentPath = qualifiedDir ;
    loadDirectory(qualifiedDir);
}

void Knots::browseVirtual( QString &virtualPath )
{
    QString qualifiedDir("/external/browse?virtual=");
    qualifiedDir += virtualPath ;

    _pathHistory.push(_currentPath);
    _currentPath = qualifiedDir ;
    loadDirectory(qualifiedDir);    
}


void Knots::browseTags( QString &tag )
{

    QString qualifiedDir;
    qualifiedDir = _currentPath + "&tag=" + tag;

    _pathHistory.push(_currentPath);
    _currentPath = qualifiedDir ;
    loadDirectory(qualifiedDir);
}


void Knots::browseCategory( QString &virtualPath )
{
    QString qualifiedDir("/external/browse?category=");
    qualifiedDir += virtualPath ;

    _pathHistory.push(_currentPath);
    _currentPath = qualifiedDir ;
    loadDirectory(qualifiedDir);
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
    _currentDirectory->browseByPath(request);

}


void Knots::onDirectoryReady()
{
    emit directoryChanged( _currentDirectory );
}


void Knots::onPlayerStateChange( KnotsPlayer::PlayingState /*newState */)
{
}

Knots::~Knots()
{
    delete _player;
    delete _currentDirectory;
}

KnotsDirectory* Knots::currentDirectory() {
    return _currentDirectory;
}

void Knots::search( QString &searchTag )
{
    QString qualifiedDir = "/external/browse?search=" + searchTag + " &order=added DESC&limit=10000";
    _currentPath = qualifiedDir ;
    loadDirectory(qualifiedDir);
}
