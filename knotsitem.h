#ifndef KNOTSITEM_H
#define KNOTSITEM_H

#include <QObject>
#include <QUrl>
#include <QMap>

class KnotsItem : public QObject
{
    Q_OBJECT
public:
    explicit KnotsItem(QObject *parent = 0);

signals:

public slots:



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




public:

    enum Types {
        CATEGORY = 0,
        TAG = 1,
        VALUE = 2,
        ITEM = 3,
        DIR = 4,
        VIRTUAL = 5,
        SERVER = 6,
        BUTTON = 7
    };

    virtual ~KnotsItem();

    int getIntId();

    QString getMediaType() ;

    void setMediaType(QString & mediaType);

    QString getMid();

    void setMid(QString & mid);

    QString getId();

    void setId(QString & id) ;

    QString getDirectoryId();

    void setDirectoryId(QString & directoryId);

    QString getText();

    int getType();

    QUrl getItemImage();

    void setItemImage();

    QHash<QString, QString>& getFields() ;

    void retrieveData();

    QString itemSelected();


    /**
      *
      */
    QString _mid;
    QString _id;
    QString _directoryId;
    QString _text;
    int _type;
    QUrl _itemImage;
    QHash<QString,QString> _fields;
    QString _mediaType;
    int _intId;

};

typedef QMap<QString, KnotsItem*> KnotsItemListImpl;

#endif // KNOTSITEM_H
