#include <QVector>

#include "profileshandler.h"
#include "profile.h"
#include "knots.h"

ProfilesHandler::ProfilesHandler( QObject* parent )
    : QObject( parent )
{
    connect(&Knots::instance().serverConnection(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onProfilesFetched(QNetworkReply*)));
}

bool ProfilesHandler::startDocument()
{
    qDeleteAll(_profiles->begin(), _profiles->end());
    return true;
}


void ProfilesHandler::loadProfiles() {

    try {

        _profiles = new ProfileListImpl();

        QUrl requestAddress = Knots::instance().serverAddress();

        requestAddress.setPath(+ "/external/transcoding_profiles");

        QNetworkRequest request( requestAddress );

        _profileFetch = Knots::instance().serverConnection().get(request);



    }

    catch(...)
    {
        qWarning() << "Failed to fetch profiles";
    }
}

void ProfilesHandler::onProfilesFetched( QNetworkReply* reply )
{
    if( reply == _profileFetch )
    {
        _xmlSource = new QXmlInputSource( _profileFetch );
        _xmlReader = new QXmlSimpleReader;
        _xmlReader->setContentHandler(this);

        qWarning() << "Fetched from " << reply->url() ;
        qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
        qWarning() << reply->peek( 256 );


        _xmlReader->parse(_xmlSource );

        delete _xmlSource;
        delete _xmlReader;
        _xmlReader = 0;


        _profileFetch->deleteLater();

        emit profilesChanged(_profiles);
    }
}

bool ProfilesHandler::startElement(const QString & /* namespaceURI */,
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

bool ProfilesHandler::endElement(const QString & /* namespaceURI */,
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
       (*_profiles)[_currentItem->getId()] = _currentItem;

    return true;
}

bool ProfilesHandler::characters(const QString &str)
{
    _currentText += str;
    return true;
}

bool ProfilesHandler::fatalError(const QXmlParseException &/*exception*/)
{
    return false;
}

ProfileListImpl* ProfilesHandler::profiles()
{
    return _profiles;
}
