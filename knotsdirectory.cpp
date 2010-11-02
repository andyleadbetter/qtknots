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

void KnotsDirectoryImpl::directoryFetchFinished( QNetworkReply* reply )
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

        _parser = new SaxKnotsItemHandler(*_items);

        QNetworkRequest request( pathToLoad );

        _currentDownload = _serverConnection.get(request);

        _xmlSource = new QXmlInputSource( _currentDownload );
        _xmlReader = new QXmlSimpleReader();

        _xmlReader->setContentHandler(_parser);

        connect(&_serverConnection, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(directoryFetchFinished(QNetworkReply*)));
    }

    catch(...)
    {
        qWarning() << "Failed to fetch path";
    }
}

