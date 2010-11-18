#ifndef KNOTSPLAYER_H
#define KNOTSPLAYER_H


#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QtDBus/QtDBus>



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
    void sourceChanged(QString &newSource);
    void stateChanged( PlayingState newState );

public:
    explicit KnotsPlayer( QObject *parent = 0);

    void play( QString& id );

    void stop();

    void seek(float newPosition );

    float duration();

public slots:

    void requestFinished( QNetworkReply* reply);

    void onPropertiesUpdated();    

private:

    void startRequestFinished(QNetworkReply* reply);
    void stopRequestFinished(QNetworkReply* reply);
    void seekRequestFinished(QNetworkReply* reply);
    void startObservingProperties();



    QNetworkAccessManager _serverConnection;
    QNetworkReply* _stopRequest;
    QNetworkReply* _playRequest;
    QNetworkReply* _seekRequest;

    QString _playerId;
    QString _password;
    QMediaPlayer* _playerBackend;
    QVideoWidget* _videoWidget;
    KnotsPlayerProperties* _properties;

};

#endif // KNOTSPLAYER_H
