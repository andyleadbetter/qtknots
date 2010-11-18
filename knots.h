#ifndef KNOTS_H
#define KNOTS_H

#include <QObject>
#include <QStack>
#include <QXmlSimpleReader>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSettings>

#include "qmlapplicationviewer.h"
#include "knotsplayer.h"
#include "profile.h"

class SaxProfileHandler;
class KnotsDirectoryImpl;



class Knots : public QObject
{
    Q_OBJECT
public:
    explicit Knots(QObject *parent = 0);

signals:
    void directoryChanged(KnotsDirectoryImpl* newItems);

    void profilesChanged(ProfileListImpl* profiles );

public slots:

    void onProfilesFetched( QNetworkReply* reply );

    void onDirectoryReady();

    void onPlayerStateChange( KnotsPlayer::PlayingState newState );

public:

    static Knots& instance();

    KnotsPlayer& player();

    QString profile() const;    

    void setProfile( QString &newProfile );

    QUrl  serverAddress() const;

    void setServerAddress( QUrl &newServerAddress );

    void browseByPath( QString &pathToBrowse );

    void browseRoot();

    void backSelected();

    void loadProfiles() ;

    QString currentPath() const;

    void loadDirectory(QString &newPath);

    void browseVirtual( QString &virtualPath );

    void loadSettings();

private:
    QString _profile;
    QUrl _serverAddress;
    QString _currentPath;
    QString _playerId;

    QXmlSimpleReader _xmlReader;
    QXmlInputSource  *_xmlSource;


    QNetworkAccessManager serverConnection;
    QNetworkReply* currentDownload;

    QStack<QString> _pathHistory;

    SaxProfileHandler* handler;

    static Knots* _instance;

    ProfileListImpl* _profiles;
    KnotsDirectoryImpl* _currentDirectory;
    KnotsPlayer* _player;
    QSettings _settings;

    QmlApplicationViewer _navigator;
    QmlApplicationViewer _videoPlayer;


};




#endif // KNOTS_H
