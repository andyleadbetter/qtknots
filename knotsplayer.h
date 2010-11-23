#ifndef KNOTSPLAYER_H
#define KNOTSPLAYER_H


#include <QObject>
#include <QString>
#include <QNetworkAccessManager>

#include <QtDBus/QtDBus>

const int KOneSecond = 1000;

class KnotsPlayerProperties;

class KnotsPlayer : public QObject
{
    Q_OBJECT

public:
    enum PlayingState
    {
        WaitingForPortInfo,
        Playing,
        Paused,
        Seeking,
        Stopped
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


public slots:

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

    KnotsPlayerProperties* _properties;

};

#endif // KNOTSPLAYER_H
