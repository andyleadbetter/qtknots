#ifndef KNOTSDIRECTORY_H
#define KNOTSDIRECTORY_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QAbstractItemModel>
#include "knotsitem.h"
#include "saxknotsitemhandler.h"

class Knots;


class KnotsDirectory : public QAbstractListModel, public SaxKnotsItemHandlerParserObserver
{
    Q_OBJECT

    enum ProfileRoles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        ItemImageRole
    };

signals:

    void directoryChanged( );

public slots:

    QString itemSelected( QString itemId );
    void onDirectoryFetchFinished( QNetworkReply* reply );


public:
    virtual ~KnotsDirectory();

    explicit KnotsDirectory(QObject *parent = 0);

    void browseByPath( QString &pathToLoad );

    int getCurrentPage() const;

    int getTotalPages() const;

    int rowCount ( const QModelIndex & /*parent*/) const;

    QVariant data ( const QModelIndex & index, int role ) const;


protected:

    void handleNewItem(KnotsItem *item );

    void handlePages(int totalPages, int currentPage);

    void loadPath( QUrl &pathToLoad  );


private:


    QUrl _basePath;
    QXmlSimpleReader*    _xmlReader;
    QXmlInputSource*     _xmlSource;
    QNetworkReply* _currentDownload;
    SaxKnotsItemHandler* _parser;
    QNetworkAccessManager _serverConnection;
    QHash<int, QByteArray> _roles;
    int _totalPages;
    int _currentPage;
    KnotsItemListImpl _items;


};




#endif // KNOTSDIRECTORY_H
