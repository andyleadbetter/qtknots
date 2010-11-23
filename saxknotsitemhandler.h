#ifndef SAXKNOTSITEMHANDLER_H
#define SAXKNOTSITEMHANDLER_H


#include <QObject>
#include <QXmlDefaultHandler>
#include "knotsitem.h"

class SaxKnotsItemHandler
        : public QObject
        , public QXmlDefaultHandler
{
    Q_OBJECT

    enum CurrentState    {
        Idle,
        ParsingRoot,
        ParsingItems,
        ParsingItem,
        ParsingPage,
        Finished
    } _currentState;


signals:
    void directoryPagesChanged( int currentPage, int totalPages );
    void itemsAdded();

public:


    explicit SaxKnotsItemHandler( QObject* parent = 0);

    void setItems( KnotsItemListImpl* items );

    bool startDocument();

    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &attributes);

    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);

    bool characters(const QString &str);

    bool fatalError(const QXmlParseException &exception);

private:
    int _currentPage;
    int _totalPages;
    int _numberItems;

    KnotsItem* _currentItem;

    KnotsItemListImpl* _items;

    QString _currentText;

};

#endif // SAXKNOTSITEMHANDLER_H
