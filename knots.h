#ifndef KNOTS_H
#define KNOTS_H

#include <QObject>
#include <QStack>
#include <QXmlSimpleReader>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSettings>

#include "profile.h"
#include "mainwindow.h"

class SaxProfileHandler;
class KnotsDirectory;


class Knots : public QObject
{
    Q_OBJECT
public:
    explicit Knots(QObject *parent = 0);
    ~Knots();

signals:
    void directoryChanged(KnotsDirectory* newItems);

    void profilesChanged(ProfileListImpl* profiles );

public slots:

    void onProfilesFetched( QNetworkReply* reply );

    void onDirectoryReady();

    void onPlayerStateChange( KnotsPlayer::PlayingState newState );

public:

    MainWindow* mainWindow();

    static Knots& instance();

    KnotsPlayer& player();

    QString profile() const;    

    void setProfile( QString &newProfile );

    QUrl  serverAddress() const;

    KnotsDirectory* currentDirectory();

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
private:
    QString _profile;
    QUrl _serverAddress;
    QString _currentPath;
    QString _playerId;

    QXmlSimpleReader* _xmlReader;
    QXmlInputSource  *_xmlSource;


    QNetworkAccessManager serverConnection;
    QNetworkReply* currentDownload;
    QNetworkReply* _profileFetch;

    QStack<QString> _pathHistory;

    SaxProfileHandler* handler;

    static Knots* _instance;

    ProfileListImpl* _profiles;
    KnotsDirectory* _currentDirectory;

    QSettings _settings;
    KnotsPlayer* _player;
    MainWindow* _mainWindow;


};




#endif // KNOTS_H
