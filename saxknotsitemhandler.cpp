#include "saxknotsitemhandler.h"
#include "knotsitem.h"

SaxKnotsItemHandler::SaxKnotsItemHandler(KnotsItemListImpl& items )
    : _items( items )
{
}

bool SaxKnotsItemHandler::startDocument()
{
    _numberItems = 0;
    qDeleteAll( _items.begin(), _items.end());
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
        /*  } else if( localName == "pages" ) {
            currentPage = new KnotsPage();
            _currentState = ParsingPage;*/
    } else if( localName == "items" ) {
        _currentState = ParsingItems;
    }

    _currentText.clear();

#if 0
    if( localName.equals("item")) {
        currentItem = new KnotsItem();
        status = CurrentState.ParsingItem;
    } else if( localName.equals("pages")) {
        currentPage = new KnotsPage();
        status = CurrentState.ParsingPage;
    } else if( localName.equals("items")) {
        status = CurrentState.ParsingItems;
    }
#endif

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
            _currentItem->_modelIndex = _numberItems++;
            _items.append(_currentItem);
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
