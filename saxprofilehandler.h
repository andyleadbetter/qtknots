#ifndef SaxProfileHandler_H
#define SaxProfileHandler_H

#include <QObject>
#include <QXmlDefaultHandler>

#include "profile.h"

class SaxProfileHandler :  public QXmlDefaultHandler
{

public:
    SaxProfileHandler(ProfileListImpl& profiles);

    bool startDocument();

    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &attributes);

    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);

    bool characters(const QString &str);

    bool fatalError(const QXmlParseException &exception);


private:

    Profile* _currentItem;

    ProfileListImpl& _profiles;

    QString _currentText;

};

#endif // SaxProfileHandler_H
