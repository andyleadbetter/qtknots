#ifndef KNOTSPLAYER_H
#define KNOTSPLAYER_H


#include <QObject>
#include <QString>
#include <QNetworkAccessManager>

#if defined(Q_WS_MAEMO_5)
#include <libosso.h>
#endif

#include <QtDBus/QtDBus>

const int KOneSecond = 1000;

class KnotsPlayerProperties;

class KnotsPlayer : public QObject
{
    Q_OBJECT

public:
    Q_ENUMS(PlayingState)
    enum PlayingState
    {
        WaitingForPortInfo, // 0
        Playing,            // 1
        Paused,             // 2
        Seeking,            // 3
        Stopped             // 4
    } _status;


signals:
    void propertiesChanged(const KnotsPlayerProperties &newProperties );
    void stateChanged( KnotsPlayer::PlayingState newState );

public:
    explicit KnotsPlayer( QObject *parent = 0);

    void play( QString& id );

    void stop();

    void seek(float newPosition );

    float duration();

    ~KnotsPlayer();

    KnotsPlayerProperties& properties();


    void startBacklightKeepAlive();
    void stopBacklightKeepAlive();

public slots:
    void onBacklightTimer();

    void requestFinished( QNetworkReply* reply);

    void onPropertiesUpdated();    

    void updateTimeout();

private:

    void startRequestFinished(QNetworkReply* reply);
    void stopRequestFinished(QNetworkReply* reply);
    void seekRequestFinished(QNetworkReply* reply);
    void startObservingProperties();
    void stopObservingProperties();



    QNetworkAccessManager _serverConnection;
    QNetworkReply* _stopRequest;
    QNetworkReply* _playRequest;
    QNetworkReply* _seekRequest;

    QString _playerId;
    QString _password;

    QTimer* _propertiesUpdateTimer;
    QTimer* _backlightTimer;
    KnotsPlayerProperties* _properties;


#if defined(Q_WS_MAEMO_5)
    osso_context_t* _ossoContext;
#endif


};

#endif // KNOTSPLAYER_H
