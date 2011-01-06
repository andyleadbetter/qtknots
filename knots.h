#ifndef KNOTS_H
#define KNOTS_H

#include <QObject>
#include <QStack>
#include <QXmlSimpleReader>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSettings>

#include <QDeclarativeNetworkAccessManagerFactory>

#include "profile.h"
#include "mainwindow.h"
#include "networkaccessmanager.h"

class ProfilesHandler;
class KnotsDirectory;


class Knots : public QObject
{
    Q_OBJECT
public:
    explicit Knots(QObject *parent = 0);
    ~Knots();

signals:
    void directoryChanged(KnotsDirectory* newItems);

public slots:

    void onDirectoryReady();

    void onPlayerStateChange( KnotsPlayer::PlayingState newState );

    void authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);

public:

    MainWindow* mainWindow();

    static Knots& instance();

    KnotsPlayer& player();

    QString profile() const;    

    void setProfile( QString &newProfile );

    QUrl  serverAddress() const;

    KnotsDirectory& currentDirectory();

    void setServerAddress( QUrl &newServerAddress );

    void browseByPath( QString &pathToBrowse );

    void browseRoot();

    void backSelected();

    void loadProfiles() ;

    QString currentPath() const;

    void loadDirectory(QString &newPath);

    void browseVirtual( QString &virtualPath );

    void loadSettings();

    void launch();

    void search( QString &searchTag );

    void browseCategory(QString &virtualPath);

    void browseTags(QString &tag);

    void setPlayer(KnotsPlayer *newPlayer);

    ProfilesHandler& profiles();

    QNetworkAccessManager& serverConnection();

    QString password();

    QString userName();

    void setUserName(QString newPass);

    void setPassword(QString newPass);

private:
    QString _profile;
    QUrl _serverAddress;
    QString _currentPath;
    QString _playerId;
    QString _userName;
    QString _password;

    NetworkAccessManager _serverConnection;
    QNetworkReply* currentDownload;


    QStack<QString> _pathHistory;

    ProfilesHandler* _handler;

    static Knots* _instance;

    ProfilesHandler* _profiles;
    KnotsDirectory* _currentDirectory;

    QSettings _settings;
    KnotsPlayer* _player;
    MainWindow* _mainWindow;


};




#endif // KNOTS_H
