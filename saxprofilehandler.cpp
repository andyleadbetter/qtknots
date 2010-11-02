#include <QVector>

#include "saxprofilehandler.h"
#include "profile.h"

SaxProfileHandler::SaxProfileHandler(ProfileListImpl& profiles )
    : _profiles( profiles )
{
}

bool SaxProfileHandler::startDocument()
{
    qDeleteAll(_profiles.begin(), _profiles.end());
    return true;
}


bool SaxProfileHandler::startElement(const QString & /* namespaceURI */,
                                     const QString & /* localName */,
                                     const QString &qName,
                                     const QXmlAttributes &/*attributes*/)
{
    if( qName == "item") {
        _currentItem = new Profile();
    }

    _currentText.clear();
    return true;
}

bool SaxProfileHandler::endElement(const QString & /* namespaceURI */,
                                   const QString &localName ,
                                   const QString &/*qName*/)
{
    if (localName =="id") {
        _currentItem->setId( _currentText);
    } else if( localName == "video_format") {
        _currentItem->setCodec(_currentText);
    } else if( localName == "video_bitrate") {
        _currentItem->setBitrate(_currentText);
    } else if( localName == "name") {
        _currentItem->setName(_currentText);
    } else if( localName == "item" )
        _profiles[_currentItem->getId()] = _currentItem;

    return true;
}

bool SaxProfileHandler::characters(const QString &str)
{
    _currentText += str;
    return true;
}

bool SaxProfileHandler::fatalError(const QXmlParseException &/*exception*/)
{
    return false;
}
