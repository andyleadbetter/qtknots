#include "knots.h"
#include "knotsplayerproperties.h"
#include <QDebug>

KnotsPlayerProperties::KnotsPlayerProperties(QObject *parent )
    : QObject( parent )
    , _position(0.0)    
    , _duration(0)
    , _currentDownload(0)

{
    _processingThread.start(QThread::LowPriority);

    moveToThread(&_processingThread);

    _xmlReader = new QXmlSimpleReader();
    _xmlReader->setContentHandler(this);


    connect(&Knots::instance().serverConnection(), SIGNAL(finished(QNetworkReply*)),
            this, SLOT(fetchFinished(QNetworkReply*)));
}

KnotsPlayerProperties::~KnotsPlayerProperties()
{

    delete _xmlSource; _xmlSource = 0;
    delete _xmlReader; _xmlReader = 0;
    disconnect(this);
}

void KnotsPlayerProperties::updateStatus(QString &playerId, QString &password)
{

    QUrl statusUrl = Knots::instance().serverAddress();
    statusUrl.setPath("/external/player_properties");
    statusUrl.addQueryItem("player_id",playerId);

    _playerId = playerId;
    _password = password;

    // If not waiting for properties then request new set
    if( _currentDownload == 0 )
    {
        _waitingForRequest.lock();
        QNetworkRequest request( statusUrl );
        _currentDownload = Knots::instance().serverConnection().get(request);
        _xmlSource = new QXmlInputSource( _currentDownload );
        _waitingForRequest.unlock();
    }
    // else wait for the existing request to finish.

}

void KnotsPlayerProperties::fetchFinished( QNetworkReply* reply )
{
    // qWarning() << "Fetched from " << reply->url() ;
    // qWarning() << "Read " << reply->bytesAvailable() << " Bytes";
    // qWarning() << reply->peek( 256 );

    if( reply == _currentDownload )
    {
        _waitingForRequest.lock();
        _xmlReader->parse(_xmlSource );

        reply->deleteLater();

        QUrl streamUrl;

        streamUrl.setScheme("http");
        streamUrl.setUserName(_playerId);
        streamUrl.setPassword(_password);
        streamUrl.setPort(_port.toInt());
        streamUrl.setHost( Knots::instance().serverAddress().host());
        streamUrl.setPath("/" + _stream);

        _streamUrl = streamUrl.toString();

        delete _xmlSource;
        _xmlSource=0;
        _currentDownload = 0;

        qDebug() << "Duration: " << this->_duration;
        qDebug() << "Position: " << this->_position;

        emit propertiesUpdated();
        _waitingForRequest.unlock();
    }
}



bool KnotsPlayerProperties::startDocument()
{
    return true;
}


bool KnotsPlayerProperties::startElement(const QString & /* namespaceURI */,
                                         const QString &/*localName*/,
                                         const QString &/*qName*/,
                                         const QXmlAttributes &/*attributes*/)
{
    _currentText.clear();


    return true;
}

bool KnotsPlayerProperties::endElement(const QString & /* namespaceURI */,
                                       const QString &localName ,
                                       const QString &/*qName*/)
{
    if( localName == "seekable" ) {
        _seekable = _currentText;
    } else if ( localName == "mediatype" ) {
        _mediatype = _currentText;
    } else if ( localName == "title" ) {
        _title = _currentText;
    } else if ( localName == "position" ) {
        _position = _currentText.toFloat();
    } else if ( localName == "media_id" ) {
        _media_id = _currentText;
    } else if ( localName == "playlistindex" ) {
        _playlistindex = _currentText;
    } else if ( localName == "playlist_length" ) {
        _playlist_length = _currentText;
    } else if ( localName == "currently_playing_filename" ) {
        _currently_playing_filename = _currentText;
    } else if ( localName == "video_width" ) {
        _video_width = _currentText;
    } else if ( localName == "video_height" ) {
        _video_height = _currentText;
    } else if ( localName == "mux" ) {
        _mux = _currentText;
    } else if ( localName == "stream" ) {
        _stream = _currentText;
    } else if ( localName == "port" ) {
        _port = _currentText;
    } else if ( localName == "buffer" ) {
        _buffer = _currentText;
    } else if ( localName == "address" ) {
        _address = _currentText;
    } else if ( localName == "looped" ) {
        _looped = _currentText;
    } else if ( localName == "duration") {
        _duration = _currentText.toInt();
    }


    return true;
}

bool KnotsPlayerProperties::characters(const QString &str)
{
    _currentText += str;
    return true;
}

bool KnotsPlayerProperties::fatalError(const QXmlParseException &/*exception*/)
{
    return false;
}
