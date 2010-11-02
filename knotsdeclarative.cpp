
#include <qdebug.h>

#include "knotsdeclarative.h"
#include "knots.h"
#include "profile.h"
#include "knotsitem.h"
#include "knotsplayer.h"

KnotsDeclarative::KnotsDeclarative(QObject *parent)
    : QObject(parent)
    , _instance( Knots::instance())
{
    connect( &_instance.player(), SIGNAL(sourceChanged(QString&)), this, SLOT(onSourceChanged(QString&)));
}

void KnotsDeclarative::backSelected()
{
    _instance.backSelected();
}

void KnotsDeclarative::stop()
{
    _instance.player().stop();
}

void KnotsDeclarative::toggleFullscreen()
{
    //_instance.player().fullScreen();
}

void KnotsDeclarative::setVideoRect(int x, int y, int width, int height )
{
    _instance.player().setVideoRect( x,y,width,height);
}

QString KnotsDeclarative::getCurrentSource()
{
    return _source;
}

void KnotsDeclarative::setCurrentSource( QString &newSource )
{
    _source = "";
}

void KnotsDeclarative::onSourceChanged(QString &source)
{
    _source = source;
    emit sourceChanged(_source);
}




ProfileList::ProfileList( QObject *parent )
    : QAbstractListModel( parent )
    , _instance( Knots::instance())
    , _profiles( 0 )
{    
    _roles[IdRole] = "id";
    _roles[NameRole] = "name";
    setRoleNames(_roles);
    connect( &_instance, SIGNAL( profilesChanged(ProfileListImpl*)), this, SLOT(onProfilesChanged(ProfileListImpl*)));
}

void ProfileList::setCurrentProfile(QString &newProfile)
{
    _instance.setProfile(newProfile);
}

QString ProfileList::getCurrentProfile() const
{
    return _instance.profile();
}



int ProfileList::rowCount ( const QModelIndex & /*parent*/) const
{
    if( _profiles == 0 )
        return 0;

    qDebug() << "Profiles Model has " << _profiles->count() << " entries";
    return _profiles->count();
}

void ProfileList::onProfilesChanged( ProfileListImpl* newProfiles )
{
    _profiles = newProfiles;
    reset();
}

QVariant ProfileList::data ( const QModelIndex & index, int role ) const
{
    qDebug() << "Qml asking for entry " << index.row();

    if( _profiles == 0 )
        return QVariant();
    if (!index.isValid())
        return QVariant(); // Return Null variant if index is invalid
    if (index.row() > (_profiles->count()) )
        return QVariant();

    Profile *dobj = _profiles->values().at(index.row());

    if( dobj )
    {
        qDebug() << "Bitrate: " << dobj->getBitrate()
                 << "Name: " << dobj->getName()
                 << "Id: " << dobj->getId();

        switch (role) {
        case Qt::DisplayRole: // The default display role now displays the first name as well
        case IdRole:
            return QVariant::fromValue(dobj->getId());
        case NameRole:
            return QVariant::fromValue(dobj->getName());
        default:
            return QVariant();
        }
    } else {
        return QVariant();
    }

}



KnotsDirectory::KnotsDirectory( QObject *parent )
    : QAbstractListModel( parent )
    , _instance( Knots::instance() )
    , _items(0)
{
    _roles[IdRole] = "id";
    _roles[NameRole] = "name";
    _roles[ItemImageRole] = "thumbnail";
    setRoleNames(_roles);

    connect( &_instance, SIGNAL(directoryChanged(KnotsDirectoryImpl*)), SLOT(onDirectoryChanged(KnotsDirectoryImpl*)));
}

void KnotsDirectory::onDirectoryChanged( KnotsDirectoryImpl* newDirectory )
{
    _items = newDirectory;
    reset();
}

int KnotsDirectory::rowCount ( const QModelIndex & /*parent*/) const
{
    int count = 0;

    if( _items )
    {
        count = _items->items().count();
    }
    qDebug() << "Directory has " << count << " entries";
    return count;
}


QVariant KnotsDirectory::data ( const QModelIndex & index, int role ) const
{
    qDebug() << "Qml asking item " << index.row();

    if( _items == 0 )
        return QVariant();

    if (!index.isValid())
        return QVariant(); // Return Null variant if index is invalid

    if (index.row() > (_items->items().count()) )
        return QVariant();

    KnotsItem *dobj = _items->items().values().at(index.row());

    if( dobj )
    {
        qDebug() << "Name: " << dobj->getText()
                 << "Id: " << dobj->getId()
                 << "thumbnail" << dobj->getItemImage();

        switch (role) {
        case Qt::DisplayRole: // The default display role now displays the first name as well
        case IdRole:
            return QVariant::fromValue(dobj->getId());
        case NameRole:
            return QVariant::fromValue(dobj->getText());
        case ItemImageRole:
            return QVariant::fromValue(dobj->getItemImage());

        default:
            return QVariant();
        }
    } else {
        return QVariant();
    }

}


QString KnotsDirectory::itemSelected( QString itemId )
{
    QString newState = "Browsing";

    KnotsItem* item = _items->items()[itemId];
    if( item )
        newState = item->itemSelected();

    return newState;

}
