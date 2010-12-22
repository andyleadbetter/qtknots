#ifndef KNOTSPLAYERPROPERTIES_H
#define KNOTSPLAYERPROPERTIES_H
#include <QObject>
#include <QXmlDefaultHandler>
#include <QNetworkAccessManager>
#include "QUrl"
#include <QThread>
#include <QMutex>


class KnotsPlayerProperties
        : public QObject
        , public QXmlDefaultHandler
{
    Q_OBJECT
public:

    explicit KnotsPlayerProperties(QObject *parent = 0);

private:
    enum CurrentState    {
        Idle,
        ParsingRoot,
        ParsingItems,
        ParsingItem,
        ParsingPage,
        Finished
    } _currentState;


public slots:
    void fetchFinished( QNetworkReply* reply );

signals:
    void propertiesUpdated();

public:
    void updateStatus(QString &playerId, QString &password);

    bool startDocument();

    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &attributes);

    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);

    bool characters(const QString &str);

    bool fatalError(const QXmlParseException &exception);

    ~KnotsPlayerProperties();

public:

    QString _seekable;
    QString _mediatype;
    QString _title;
    QString _position;
    QString _duration;
    QString _media_id;
    QString _playlistindex;
    QString _playlist_length;
    QString _currently_playing_filename;
    QString _video_width;
    QString _video_height;
    QString _mux;
    QString _stream;
    QString _port;
    QString _buffer;
    QString _address;
    QString _looped;
    QUrl _streamUrl;
    QString _playerId;
    QString _password;



private:

    QNetworkAccessManager _serverConnection;
    QNetworkReply* _currentDownload;
    QXmlSimpleReader*    _xmlReader;
    QXmlInputSource*     _xmlSource;
    QString _currentText;
    QMutex _waitingForRequest;

    QThread _processingThread;
};

#if 0
<?xml version='1.0' encoding='UTF-8' ?>
                                       <root>
                                       <items>
                                       <item>
                                       <seekable><![CDATA[true]]></seekable>
                                       <mediatype><![CDATA[0]]></mediatype>
                                       <title><![CDATA[6family.guy.606.hdtv-lol]]></title>
                                       <position><![CDATA[0.06948]]></position>
                                       <duration><![CDATA[1255]]></duration>
                                       <media_id><![CDATA[47]]></media_id>
                                       <playlistindex><![CDATA[1]]></playlistindex>
                                       <playlist_length><![CDATA[1]]></playlist_length>
                                       <currently_playing_filename><![CDATA[C:\Users\andy\Videos\Family Guy\Season 6\6family.guy.606.hdtv-lol.avi]]></currently_playing_filename>
                                       <video_width><![CDATA[480]]></video_width>
                                       <video_height><![CDATA[320]]></video_height>
                                       <mux><![CDATA[ffmpeg{mux=flv}]]></mux>
                                       <stream><![CDATA[stream.flv]]></stream>
                                       <port><![CDATA[19880]]></port>
                                       <buffer><![CDATA[1]]></buffer>
                                       <address><![CDATA[]]>
                                       </address>
                                       <looped><![CDATA[false]]></looped>
                                       </item>
                                       </items>
                                       </root>
                                       #endif



                                       #endif // KNOTSPLAYERPROPERTIES_H
