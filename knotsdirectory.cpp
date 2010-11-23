#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <qdebug.h>
#include "knotsdirectory.h"


KnotsDirectoryImpl::~KnotsDirectoryImpl()
{
    delete _xmlReader;
    delete _xmlSource;

    qDeleteAll( _items->begin(), _items->end());

}


KnotsDirectoryImpl::KnotsDirectoryImpl( QObject *parent )
    : QObject( parent )
    , _xmlReader(0)
    , _xmlSource(0)
    , _currentDownload(0)
    , _items(0)
    , _parser(0)
{
    _items = new KnotsItemListImpl();
}

KnotsItemListImpl& KnotsDirectoryImpl::items()
{
    return *_items;
}

void KnotsDirectoryImpl::onDirectoryFetchFinished( QNetworkReply* reply )
{
    qWarning() << "Fetched from " << reply->url() ;
    qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
    qWarning() << reply->peek( 256 );


    _xmlReader->parse(_xmlSource );

    delete _xmlSource;
    _xmlSource = 0;

    delete _xmlReader;
    _xmlReader = 0;

    _currentDownload->deleteLater();

    emit directoryChanged();
}

KnotsDirectoryImpl* KnotsDirectoryImpl::browseByPath( QString &pathToLoad )
{
    KnotsDirectoryImpl* _this = new KnotsDirectoryImpl();

    _this->loadPath( pathToLoad );

    return _this;
}


void KnotsDirectoryImpl::loadPath(QString &pathToLoad)
{
    try {

        _parser = new SaxKnotsItemHandler(0);
        _parser->setItems(_items);


        QNetworkRequest request( pathToLoad );

        _currentDownload = _serverConnection.get(request);

        _xmlSource = new QXmlInputSource( _currentDownload );
        _xmlReader = new QXmlSimpleReader();

        _xmlReader->setContentHandler(_parser);

        connect(_parser, SIGNAL(directoryPagesChanged(int,int)),SLOT(onDirectoryPagesChanged(int,int)));
        connect(&_serverConnection, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(onDirectoryFetchFinished(QNetworkReply*)));
        connect( _parser, SIGNAL(itemsAdded()), SLOT(itemsAdded()));

    }

    catch(...)
    {
        qWarning() << "Failed to fetch path";
    }
}

int KnotsDirectoryImpl::getCurrentPage() const
{
    return _currentPage;
}

int KnotsDirectoryImpl::getTotalPages() const
{
    return _totalPages;
}

void KnotsDirectoryImpl::onDirectoryPagesChanged( int currentPage, int totalPages )
{
    _currentPage = currentPage;
    _totalPages = totalPages;

    if( currentPage < totalPages )
    {
        qDebug() << "Got " << totalPages << "pages to retrieve";
    }
}

void KnotsDirectoryImpl::itemsAdded()
{
    emit directoryChanged();
}
