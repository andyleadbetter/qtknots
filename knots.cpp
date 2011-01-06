#include <QtDebug>
#include <QtOpenGL/QGLWidget>
#include <qdeclarative.h>
#include <QMainWindow>
#include <QAuthenticator>

#include "knots.h"
#include "profile.h"
#include "profileshandler.h"
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
    , _player(0)
{  


}

void Knots::launch()
{    
    connect( &_serverConnection, SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)), SLOT(authenticationRequired(QNetworkReply*,QAuthenticator*)));

    loadSettings();

    loadProfiles();

    _currentDirectory = new KnotsDirectory(this);

    connect( _currentDirectory , SIGNAL(directoryChanged()), this, SLOT(onDirectoryReady()));

    browseRoot();

    _mainWindow = new MainWindow;

    _mainWindow->launch();

}

KnotsPlayer& Knots::player()
{
    return *_player;
}

void Knots::loadSettings()
{
    _serverAddress = _settings.value( "ServerAddress", QString("Http://192.168.0.28:1978")).toString();
            //QString("http://192.168.2.14:1978");
    _profile = _settings.value( "DefaultProfileId", QString( "6") ).toString();
    _password = _settings.value( "Password", QString( "juno") ).toString();
    _userName = _settings.value( "Username", QString( "andy") ).toString();
}

QString Knots::profile() const
{
    return _profile;
}

void Knots::setProfile( QString &newProfile )
{
    Profile *profile = _profiles->profiles()->values().at(newProfile.toInt());

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
    loadProfiles();
    browseRoot();
}



void Knots::loadProfiles()
{
    _profiles = new ProfilesHandler(this);
    _profiles->loadProfiles();
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
    delete _currentDirectory;
}

KnotsDirectory& Knots::currentDirectory() {
    return *_currentDirectory;
}

ProfilesHandler& Knots::profiles()
{
    return *_profiles;
}

void Knots::search( QString &searchTag )
{
    QString qualifiedDir = "/external/browse?search=" + searchTag + " &order=added DESC&limit=10000";
    _currentPath = qualifiedDir ;
    loadDirectory(qualifiedDir);
}

MainWindow* Knots::mainWindow()
{
    return _mainWindow;
}

void Knots::setPlayer( KnotsPlayer* newPlayer )
{

    _player = newPlayer;
}

void Knots::authenticationRequired ( QNetworkReply * /*reply*/, QAuthenticator * authenticator )
{

    authenticator->setPassword(_password);
    authenticator->setUser(_userName);

}

QNetworkAccessManager& Knots::serverConnection()
{
    return _serverConnection;
}


QString Knots::password()
{
    return _password;
}

void Knots::setUserName( QString newUser )
{
    _userName = newUser;
}


void Knots::setPassword(QString newPass )
{
    _password = newPass;
}

QString Knots::userName()
{
    return _userName;
}


