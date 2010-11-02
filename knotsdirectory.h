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

    void directoryChanged();

public slots:

    void directoryFetchFinished( QNetworkReply* reply );

public:
    virtual ~KnotsDirectoryImpl();

    static KnotsDirectoryImpl* browseByPath( QString &pathToLoad );

    KnotsItemListImpl& items();

private:

    void loadPath( QString &pathToLoad  );

    explicit KnotsDirectoryImpl(QObject *parent = 0);

    SaxKnotsItemHandler* _parser;
    QXmlSimpleReader*    _xmlReader;
    QXmlInputSource*     _xmlSource;

    QNetworkAccessManager _serverConnection;
    QNetworkReply* _currentDownload;

    KnotsItemListImpl* _items;


};




#endif // KNOTSDIRECTORY_H
