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

public:
    explicit KnotsPlayer( QObject *parent = 0);

    void play( QString& id );

    void stop();

    void seek();

    void setVideoRect(int x, int y, int width, int height );

public slots:

    void requestFinished( QNetworkReply* reply);

    void onPropertiesUpdated();

    void positionChanged(qint64);

private:

    void startRequestFinished(QNetworkReply* reply);
    void stopRequestFinished(QNetworkReply* reply);
    void seekRequestFinished(QNetworkReply* reply);
    void startObservingProperties();



    QNetworkAccessManager _serverConnection;
    QNetworkReply* _stopRequest;
    QNetworkReply* _playRequest;

    QString _playerId;
    QString _password;
    QMediaPlayer* _playerBackend;
    QVideoWidget* _videoWidget;
    KnotsPlayerProperties* _properties;

};

#endif // KNOTSPLAYER_H
