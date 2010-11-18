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
 *  <item>
 *    <dirname><![CDATA[Magnum Force]]></dirname>
 *    <dir><![CDATA[1,1]]></dir>
 *    <id>0</id>
 *  </item>
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
            _itemImage.addQueryItem("type","screenshot");
            _itemImage.addQueryItem("mid",_mid);
            _itemImage.addQueryItem("mediatype","0");
            _itemImage.setPath("/root/resource_file");
            qDebug() << _itemImage.toString();
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
            }
        }
    }
}

QHash<QString, QString>& KnotsItem::getFields() {
    return _fields;
}


void KnotsItem::retrieveData() {
    int local_type = getType();
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

    case ITEM:
        Knots::instance().player().play(_id);
        newState = "Playing";
        break;
    }
    return newState;
}


bool KnotsItem::operator ==(const KnotsItem& rhs )
{
    return _id==rhs._id;
}
