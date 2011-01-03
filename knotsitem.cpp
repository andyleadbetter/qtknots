#include "knots.h"
#include "knotsplayer.h"
#include "knotsitem.h"
#include <QDebug>

KnotsItem::KnotsItem(QObject *parent)
    : QObject(parent)
    , _id("")
    , _mid("")

{
}


/**
 * @author andy
 * @desc Object to hold details of a knots item
 *
 * <item>
    <id>12</id>
    <name><![CDATA[101 - Death Has A Shadow]]></name>
    <path><![CDATA[C:/Users/andy/Videos/Family Guy/Season 1/101 - Death Has A Shadow.avi]]></path>
    <size>161716224</size>
    <duration><![CDATA[00:22:32]]></duration>
    <added><![CDATA[2010-08-21]]></added>
    <modified><![CDATA[2008-06-01]]></modified>
    <views>3</views>
    <position><![CDATA[00:00:00]]></position>
    <rating>0</rating>
    <info/>
    <last_viewed/>
    <directory_changed>2009-11-05T18:14:32+00:00</directory_changed>
    <video_format><![CDATA[mpeg4]]></video_format>
    <audio_format><![CDATA[tbr]]></audio_format>
    <audio_bitrate><![CDATA[2 channels]]></audio_bitrate>
    <aspect><![CDATA[4:3]]></aspect>
    <width>640</width>
    <height>480</height>
    <category>1</category>
    <active>1</active>
    <mediatype>0</mediatype>
    <params/><dreambox_url/>
    <tracks/>
    <mid>22</mid>
  </item>
 *
 */

KnotsItem::~KnotsItem(){
}

QString KnotsItem::getMediaType() {
    return _mediaType;
}
void KnotsItem::setMediaType(QString &mediaType) {
    _mediaType = mediaType;
}
QString KnotsItem::getMid() {
    return _mid;
}
void KnotsItem::setMid(QString& mid) {
    _mid = mid;
}
QString KnotsItem::getId() {
    return _id;
}
void KnotsItem::setId(QString & id) {
    _id = id;    
}
QString KnotsItem::getDirectoryId() {
    return _directoryId;
}
void KnotsItem::setDirectoryId(QString & directoryId) {
    _directoryId = directoryId;
}
QString KnotsItem::getText() {
    return _text;
}


int KnotsItem::getType() {

    QStringList types;
    types << "category" << "tag" << "value" << "name" << "dirname" << "virtual" << "server" << "button";

    for (int i = 0; i < types.length(); i++)
    {
        if (_fields.contains(types[types.length() - 1 - i]))
        {
            _text = _fields.value(types[types.length() - 1 - i]);
            _type = types.length() - 1 - i;
            break;
        }
    }
    return _type;
}


QUrl KnotsItem::getItemImage() {
    return _itemImage;
}

void KnotsItem::setItemImage() {

    if( _itemImage == QUrl() )
    {
        if( !( _mid == "" ) ) {
            _itemImage = Knots::instance().serverAddress();
            _itemImage.setPassword(Knots::instance().password());
            _itemImage.setUserName(Knots::instance().userName());
            _itemImage.addQueryItem("type","screenshot");
            _itemImage.addQueryItem("mid",_mid);
            _itemImage.addQueryItem("mediatype","0");
            _itemImage.setPath("/root/resource_file");
        } else {
            if( _type == DIR ) {
                _itemImage = "/qml/images/knots_dir.png";
            } else if ( _type == SERVER ) {
                _itemImage = "/qml/images/knots_item_server.png";
            } else if (_type == ITEM) {
                if( _mediaType == "" || _mediaType == "1" ) {
                    _itemImage = "/qml/images/knots_item_video.png";
                } else {
                    _itemImage = "/qml/images/knots_item_music.png";
                }
            } else if( _type == CATEGORY || _type == VIRTUAL || _type == TAG ) {
                _itemImage = "/qml/images/knots_dir.png";
            }
        }
    }
}

QHash<QString, QString>& KnotsItem::getFields() {
    return _fields;
}


void KnotsItem::retrieveData() {
    (void)getType();
    setItemImage();
}

QString KnotsItem::itemSelected()
{
    QString newState = "Browsing";
    switch( _type ) {

    case SERVER:
        /*
     * knots.get_connection().select_server(get_item_id());
     * knots.connect_server();
     * */
        break;

    case DIR:
        Knots::instance().browseByPath(_fields["dir"]);
        break;

    case VIRTUAL:
        Knots::instance().browseVirtual(_fields["search"]);
        break;

    case CATEGORY:
        Knots::instance().browseCategory(_id);
        break;

    case TAG:
        Knots::instance().browseTags(_id);
        break;
    case ITEM:
        newState = "Details";
        break;
    }
    return newState;
}


bool KnotsItem::operator ==(const KnotsItem& rhs )
{
    return _id==rhs._id;
}
