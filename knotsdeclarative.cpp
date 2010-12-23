
#include <qdebug.h>

#include "knotsdeclarative.h"
#include "knots.h"
#include "profile.h"
#include "knotsitem.h"
#include "knotsplayer.h"

#if defined(Q_WS_MAEMO_5)
    #include <QtDBus>
#endif

KnotsDeclarative::KnotsDeclarative(QObject *parent)
    : QObject(parent)
    , _instance( Knots::instance())
{    
    connect( &_instance, SIGNAL(directoryChanged(KnotsDirectory*)), SIGNAL(directoryChanged(KnotsDirectory*)));
}

KnotsDirectory* KnotsDeclarative::getDirectory()
{
    return _instance.currentDirectory();
}

void KnotsDeclarative::backSelected()
{
    _instance.backSelected();
}

QString KnotsDeclarative::getServerName()
{
    return _instance.serverAddress().toString();
}

void KnotsDeclarative::setServerName( QString &newServer )
{
    QUrl url(newServer);

    _instance.setServerAddress(url);
}

void KnotsDeclarative::search( QString searchTag )
{
    _instance.search(searchTag);
}

void KnotsDeclarative::taskSwitch()
{
#if defined(Q_WS_MAEMO_5)
    QDBusConnection connection = QDBusConnection::sessionBus();
    QDBusMessage message = QDBusMessage::createSignal("/","com.nokia.hildon_desktop","exit_app_view");
    connection.send(message);
#endif
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

    //qDebug() << "Profiles Model has " << _profiles->count() << " entries";
    return _profiles->count();
}

void ProfileList::onProfilesChanged( ProfileListImpl* newProfiles )
{
    _profiles = newProfiles;
    reset();
}

QVariant ProfileList::data ( const QModelIndex & index, int role ) const
{
    //qDebug() << "Qml asking for entry " << index.row();

    if( _profiles == 0 )
        return QVariant();
    if (!index.isValid())
        return QVariant(); // Return Null variant if index is invalid
    if (index.row() > (_profiles->count()) )
        return QVariant();

    Profile *dobj = _profiles->values().at(index.row());

    if( dobj )
    {
        //qDebug() << "Bitrate: " << dobj->getBitrate()
                // << "Name: " << dobj->getName()
                // << "Id: " << dobj->getId();

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

