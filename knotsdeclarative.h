#ifndef KNOTSDECLARATIVE_H
#define KNOTSDECLARATIVE_H

#include <QObject>
#include <QAbstractItemModel>
#include "profile.h"
#include "knotsdirectory.h"
#include "knotsplayerproperties.h"
#include "knotsplayer.h"

class Knots;

class ProfileList : public QAbstractListModel
{
    Q_OBJECT

public:
    enum ProfileRoles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };

    Q_PROPERTY( QString currentProfile READ getCurrentProfile WRITE setCurrentProfile )

public slots:
    void onProfilesChanged( ProfileListImpl* newProfileList );


public:

    explicit ProfileList(QObject *parent = 0);

    int rowCount ( const QModelIndex & parent = QModelIndex() ) const ;

    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

    QString getCurrentProfile() const;

    void setCurrentProfile( QString &newProfile );

private:

    Knots& _instance;
    QHash<int, QByteArray> _roles;
    ProfileListImpl *_profiles;
};


class KnotsDeclarative : public QObject
{
    Q_OBJECT
public:

    explicit KnotsDeclarative(QObject *parent = 0);

    Q_PROPERTY( QString currentSource READ getCurrentSource WRITE setCurrentSource NOTIFY sourceChanged )
    Q_PROPERTY( int duration READ getDuration NOTIFY durationChanged )
    Q_PROPERTY( int position READ getPosition NOTIFY positionChanged )
    Q_PROPERTY( QString serverName READ getServerName WRITE setServerName )
    Q_PROPERTY( KnotsDirectory *currentDirectory READ getDirectory NOTIFY directoryChanged )
    Q_PROPERTY( KnotsPlayer::PlayingState currentState READ getState NOTIFY stateChanged )
    Q_PROPERTY( QString formattedPosition READ getFormattedPosition NOTIFY formattedPositionChanged )

public slots:
    void taskSwitch();
    void onSourceChanged( QString &source );
    void backSelected();
    void stop( );
    void seek( float position );
    void onPropertiesUpdated(const KnotsPlayerProperties& newProperties );
    void onPlayerStateChange( KnotsPlayer::PlayingState newState );
    void search( QString searchTag );

signals:
    void currentPathChanged();
    void sourceChanged(QString &newSource );
    void durationChanged( int newDuration );
    void positionChanged( int newPosition );
    void directoryChanged( KnotsDirectory *newDirectory );
    void stateChanged( KnotsPlayer::PlayingState newState );
    void formattedPositionChanged( QString &newPos );


private:
    QString getCurrentSource();
    void setCurrentSource( QString &newSource );

    int getDuration();
    int getPosition();
    QString getFormattedPosition();

    KnotsPlayer::PlayingState getState() ;

    KnotsDirectory* getDirectory();

    QString getServerName();
    void setServerName( QString &newServer );

    Knots& _instance;
    QString _source;
    QString _serverName;
    float _duration;
    float _position;
    KnotsPlayer::PlayingState _playerState;

};

#endif // KNOTSDECLARATIVE_H
