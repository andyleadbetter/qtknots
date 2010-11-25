#ifndef SAXKNOTSITEMHANDLER_H
#define SAXKNOTSITEMHANDLER_H


#include <QObject>
#include <QXmlDefaultHandler>
#include "knotsitem.h"

class SaxKnotsItemHandlerParserObserver
{
public:
    virtual void handleNewItem(KnotsItem* item ) = 0;
    virtual void handlePages( int totalPages, int currentPage ) = 0;
};


class SaxKnotsItemHandler :
        public QXmlDefaultHandler
{

    enum CurrentState    {
        Idle,
        ParsingRoot,
        ParsingItems,
        ParsingItem,
        ParsingPage,
        Finished
    } _currentState;



public:


    SaxKnotsItemHandler();

    void setItemHandler( SaxKnotsItemHandlerParserObserver* observer );

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

    SaxKnotsItemHandlerParserObserver* _observer;
    KnotsItem* _currentItem;

    QString _currentText;

};

#endif // SAXKNOTSITEMHANDLER_H
