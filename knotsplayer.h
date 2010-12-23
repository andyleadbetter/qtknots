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
const int KNetworkCadence = 10;
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

    Q_PROPERTY( KnotsPlayer::PlayingState currentState READ getState NOTIFY stateChanged )
    Q_PROPERTY( QString formattedPosition READ getFormattedPosition NOTIFY formattedPositionChanged )
    Q_PROPERTY( QString currentSource READ getCurrentSource NOTIFY sourceChanged )
    Q_PROPERTY( int duration READ getDuration NOTIFY durationChanged )
    Q_PROPERTY( int position READ getPosition NOTIFY positionChanged )


signals:
    void propertiesChanged(const KnotsPlayerProperties &newProperties );    
    void sourceChanged(QString &newSource );
    void durationChanged( int newDuration );
    void positionChanged( int newPosition );
    void stateChanged( KnotsPlayer::PlayingState newState );
    void formattedPositionChanged( QString &newPos );

public slots:
    void play( QString& id );

    void stop( );

    void seek(int newPosition );

    void networkPropertiesUpdated();

public:

    explicit KnotsPlayer( QObject *parent = 0);

    ~KnotsPlayer();

    KnotsPlayerProperties& properties();


protected:


    void onPropertiesUpdated();


    QString getCurrentSource();

    void setCurrentSource( QString &newSource );

    int getDuration();

    int getPosition();

    QString getFormattedPosition();

    PlayingState getState() ;

protected slots:

    void onBacklightTimer();

    void requestFinished( QNetworkReply* reply);

    void updateTimeout();

private: // Methods

    void startRequestFinished(QNetworkReply* reply);

    void stopRequestFinished(QNetworkReply* reply);

    void seekRequestFinished(QNetworkReply* reply);

    void startObservingProperties();

    void stopObservingProperties();

    void startBacklightKeepAlive();

    void stopBacklightKeepAlive();

private: // Data

    QNetworkAccessManager _serverConnection;
    QNetworkReply* _stopRequest;
    QNetworkReply* _playRequest;
    QNetworkReply* _seekRequest;

    QString _playerId;
    QString _password;
    QString _source;

    QTimer* _propertiesUpdateTimer;
    QTimer* _backlightTimer;

    KnotsPlayerProperties* _properties;

    int _tickPeriod;
    int _tickCount;
    int _localPosition;

#if defined(Q_WS_MAEMO_5)
    osso_context_t* _ossoContext;
#endif

};

#endif // KNOTSPLAYER_H
