#include "saxknotsitemhandler.h"
#include "knotsitem.h"

SaxKnotsItemHandler::SaxKnotsItemHandler(  )
{
}

void SaxKnotsItemHandler::setItemHandler( SaxKnotsItemHandlerParserObserver* observer )
{
    _observer = observer;
}

bool SaxKnotsItemHandler::startDocument()
{
    _numberItems = 0;

    return true;
}


bool SaxKnotsItemHandler::startElement(const QString & /* namespaceURI */,
                                       const QString &localName,
                                       const QString &/*qName*/,
                                       const QXmlAttributes &/*attributes*/)
{
    if( localName == "item") {
        _currentItem = new KnotsItem();
        _currentState = ParsingItem;
    } else if( localName == "pages" ) {
            _currentState = ParsingPage;
    } else if( localName == "items" ) {
        _currentState = ParsingItems;
    }

    _currentText.clear();

    return true;
}

bool SaxKnotsItemHandler::endElement(const QString & /* namespaceURI */,
                                     const QString &localName ,
                                     const QString &/*qName*/)
{
    if( _currentState == ParsingItem ) {

        if( localName == "dir" ) {
            _currentItem->setDirectoryId(_currentText);
        } else if ( localName == "id" ) {
            _currentItem->setId(_currentText);
        } else if ( localName == "mediatype" ) {
            _currentItem->setMediaType(_currentText);
        } else if ( localName == "mid" ) {
            _currentItem->setMid(_currentText);
        }

        // While parsing the item element, add each field to the hash table, its used later when fetching media from server.
        if( localName != "item" ) {
            // Store this data to the item hash fields.
            _currentItem->getFields().insert(localName,_currentText);
        }

        //if this is the end of the item element, then call retrieveData to pull info about this item
        if( localName == "item" ) {
            _currentItem->retrieveData();            
            _observer->handleNewItem(_currentItem);
        }


    } else if( _currentState == ParsingPage ) {
        if(localName == "current"){
            _currentPage = _currentText.toInt();
        } else if( localName == "total") {
            _totalPages = _currentText.toInt();
        } else if( localName == "pages" )
        {
            _observer->handlePages(_totalPages, _currentPage );
        }
    }

    return true;
}

bool SaxKnotsItemHandler::characters(const QString &str)
{
    _currentText += str;
    return true;
}

bool SaxKnotsItemHandler::fatalError(const QXmlParseException &/*exception*/)
{
    return false;
}
