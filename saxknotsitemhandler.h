#ifndef SAXKNOTSITEMHANDLER_H
#define SAXKNOTSITEMHANDLER_H


#include <QObject>
#include <QXmlDefaultHandler>
#include "knotsitem.h"

class SaxKnotsItemHandler : public QXmlDefaultHandler
{
private:
    enum CurrentState    {
        Idle,
        ParsingRoot,
        ParsingItems,
        ParsingItem,
        ParsingPage,
        Finished
    } _currentState;




public:
    SaxKnotsItemHandler(KnotsItemListImpl& profiles);

    bool startDocument();

    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &attributes);

    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);

    bool characters(const QString &str);

    bool fatalError(const QXmlParseException &exception);


private:
    int currentPage;
    int totalPages;

    KnotsItem* _currentItem;

    KnotsItemListImpl& _items;

    QString _currentText;

};

#endif // SAXKNOTSITEMHANDLER_H
