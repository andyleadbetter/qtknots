#ifndef KNOTSDECLARATIVE_H
#define KNOTSDECLARATIVE_H

#include <QObject>
#include <QAbstractItemModel>
#include "profile.h"
#include "knotsdirectory.h"
#include "knotsplayerproperties.h"

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
    Q_PROPERTY( float duration READ getDuration NOTIFY durationChanged )
    Q_PROPERTY( float position READ getPosition NOTIFY positionChanged )
    Q_PROPERTY( QString serverName READ getServerName WRITE setServerName )

 public slots:
    void onSourceChanged( QString &source );
    void backSelected();
    void stop( );
    void seek( float position );
    void onPropertiesUpdated(const KnotsPlayerProperties& newProperties );

signals:
    void currentPathChanged();
    void sourceChanged(QString &newSource );
    void durationChanged( float newDuration );
    void positionChanged( float newPosition );

private:
    QString getCurrentSource();
    void setCurrentSource( QString &newSource );

    float getDuration();
    float getPosition();

    QString getServerName();
    void setServerName( QString &newServer );

    Knots& _instance;
    QString _source;
    QString _serverName;
    float _duration;
    float _position;

};


class KnotsDirectory : public QAbstractListModel
{
    Q_OBJECT
public:

    enum ProfileRoles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        ItemImageRole
    };




    explicit KnotsDirectory(QObject *parent = 0);

public slots:
    void onDirectoryChanged(KnotsDirectoryImpl* newDirectory);
    QString itemSelected( QString itemId );
public:

    int rowCount ( const QModelIndex & /*parent*/) const;

    QVariant data ( const QModelIndex & index, int role ) const;

private:
    Knots& _instance;
    KnotsDirectoryImpl* _items;
    QHash<int, QByteArray> _roles;
};

#endif // KNOTSDECLARATIVE_H
