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

    Q_PROPERTY( QString serverName READ getServerName WRITE setServerName )
    Q_PROPERTY( KnotsDirectory *currentDirectory READ getDirectory NOTIFY directoryChanged )


public slots:
    void taskSwitch();
    void backSelected();
    void search( QString searchTag );

signals:
    void currentPathChanged();
    void directoryChanged( KnotsDirectory *newDirectory );

private:

    KnotsDirectory* getDirectory();

    QString getServerName();
    void setServerName( QString &newServer );

    Knots& _instance;
    QString _serverName;

};

#endif // KNOTSDECLARATIVE_H
