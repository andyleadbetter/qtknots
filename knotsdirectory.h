#ifndef KNOTSDIRECTORY_H
#define KNOTSDIRECTORY_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QAbstractItemModel>
#include "knotsitem.h"
#include "saxknotsitemhandler.h"

class Knots;


class KnotsDirectoryImpl : public QObject
{
    Q_OBJECT

signals:

    void directoryChanged( );

public slots:

    void onDirectoryFetchFinished( QNetworkReply* reply );
    void onDirectoryPagesChanged( int currentPage, int totalPages );
    void itemsAdded();

public:
    virtual ~KnotsDirectoryImpl();

    static KnotsDirectoryImpl* browseByPath( QString &pathToLoad );

    KnotsItemListImpl& items();

    int getCurrentPage() const;
    int getTotalPages() const;

private:

    void loadPath( QString &pathToLoad  );

    explicit KnotsDirectoryImpl(QObject *parent = 0);



    QXmlSimpleReader*    _xmlReader;
    QXmlInputSource*     _xmlSource;
    QNetworkReply* _currentDownload;
    KnotsItemListImpl* _items;
    SaxKnotsItemHandler* _parser;



    QNetworkAccessManager _serverConnection;



    int _totalPages;
    int _currentPage;


};




#endif // KNOTSDIRECTORY_H
