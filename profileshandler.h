#ifndef SaxProfileHandler_H
#define SaxProfileHandler_H

#include <QObject>
#include <QXmlDefaultHandler>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "profile.h"

class ProfilesHandler :  public QObject
                      ,  public QXmlDefaultHandler
{
    Q_OBJECT

public slots:
    void onProfilesFetched(QNetworkReply *reply);

signals:
    void profilesChanged(ProfileListImpl* profiles );

public:

    explicit ProfilesHandler(QObject* parent = 0);

    bool startDocument();

    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &attributes);

    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);

    bool characters(const QString &str);

    bool fatalError(const QXmlParseException &exception);    

    void loadProfiles();

    ProfileListImpl* profiles();

private:

    Profile* _currentItem;

    QString _currentText;

    QNetworkReply* _profileFetch;

    ProfileListImpl* _profiles;

    QXmlSimpleReader* _xmlReader;

    QXmlInputSource  *_xmlSource;
};

#endif // SaxProfileHandler_H
