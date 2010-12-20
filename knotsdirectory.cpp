#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <qdebug.h>
#include "knotsdirectory.h"


KnotsDirectory::~KnotsDirectory()
{
    delete _xmlReader;
    delete _xmlSource;
    delete _parser;
}


KnotsDirectory::KnotsDirectory( QObject *parent )
    : QAbstractListModel( parent )
    , _xmlReader(0)
    , _xmlSource(0)
    , _currentDownload(0)
    , _parser(0)
{
    _roles[IdRole] = "id";
    _roles[NameRole] = "name";
    _roles[ItemImageRole] = "thumbnail";

    setRoleNames(_roles);

    _parser = new SaxKnotsItemHandler();
    _parser->setItemHandler(this);

    connect(&_serverConnection, SIGNAL(finished(QNetworkReply*)),SLOT(onDirectoryFetchFinished(QNetworkReply*)));

}


void KnotsDirectory::onDirectoryFetchFinished( QNetworkReply* reply )
{
    if( reply == _currentDownload )
    {
        qWarning() << "Fetched from " << reply->url() ;
        qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
        qWarning() << reply->peek( 256 );

        int start = _items.count();

        _xmlReader->parse(_xmlSource );

        _currentDownload->deleteLater();

        emit directoryChanged();

        QUrl request( _basePath );

        if( ++_currentPage < _totalPages )
        {
            request.addQueryItem("page", QString::number(_currentPage ));
            loadPath( request );
        }
    }
}

void KnotsDirectory::browseByPath( QString &pathToLoad )
{
    _basePath = pathToLoad;
    _currentPage = 0;
    _totalPages = 1;
    beginRemoveRows(createIndex(0,0), 0, _items.count());
    qDeleteAll(_items.begin(), _items.end());
    _items.clear();
    endRemoveRows();
    reset();

    loadPath( _basePath );

}


void KnotsDirectory::loadPath(QUrl &pathToLoad)
{
    try {

        QNetworkRequest request( pathToLoad );

        _currentDownload = _serverConnection.get(request);

        _xmlSource = new QXmlInputSource( _currentDownload );
        _xmlReader = new QXmlSimpleReader();
        _xmlReader->setContentHandler(_parser);
    }

    catch(...)
    {
        qWarning() << "Failed to fetch path";
    }
}

int KnotsDirectory::getCurrentPage() const
{
    return _currentPage;
}

int KnotsDirectory::getTotalPages() const
{
    return _totalPages;
}

void KnotsDirectory::handlePages( int totalPages, int  currentPage)
{
    _currentPage = currentPage;
    _totalPages = totalPages;
}

void KnotsDirectory::handleNewItem(KnotsItem* newItem )
{
    QModelIndex parent;
    int start = _items.count();

    beginInsertRows(parent, start, start+1);

    _items.append(newItem);
    newItem->_modelIndex = start;

    endInsertRows();

    emit dataChanged(createIndex(start,0,0),createIndex(start+1,1,0));

}




int KnotsDirectory::rowCount ( const QModelIndex & /*parent*/) const
{
    int count = 0;
    count = _items.count();

    //qDebug() << "Directory has " << count << " entries";
    return count;
}

QVariant KnotsDirectory::data ( const QModelIndex & index, int role ) const
{

    if (!index.isValid())
        return QVariant(); // Return Null variant if index is invalid

    if (index.row() > (_items.count()) )
        return QVariant();

    KnotsItem *dobj = _items.at(index.row());

    if( dobj )
    {

        //qDebug() << "Qml asking item " << index.row() << "Name: " << dobj->getText() << "Id: " << dobj->getId() << "thumbnail" << dobj->getItemImage();

        switch (role) {
        case Qt::DisplayRole: // The default display role now displays the first name as well
        case IdRole:
            return QVariant::fromValue(dobj->_modelIndex);
        case NameRole:
            return QVariant::fromValue(dobj->getText());
        case ItemImageRole:
            return QVariant::fromValue(dobj->getItemImage().toString());

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
    KnotsItem* item = 0;

    item = _items.at(itemId.toInt());

    newState = item->itemSelected();

    return newState;
}


