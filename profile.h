#ifndef PROFILE_H
#define PROFILE_H

#include <QObject>
#include <QList>
#include <QAbstractItemModel>

class Profile : public QObject
{
    Q_OBJECT
public:


    explicit Profile(QObject *parent = 0);

    Q_PROPERTY( QString id READ getId );
    Q_PROPERTY( QString name READ getName );

    QString getId() const;

    void setId(QString &id) ;

    QString getName() const ;

    void setName(QString &name);

    QString getCodec() const;

    void setCodec(QString &codec) ;

    QString getBitrate() const ;

    void setBitrate(QString &bitrate) ;

private:
    QString _id;
    QString _name;
    QString _codec;
    QString _bitrate;

public:

signals:

public slots:

};

typedef QMap<QString,Profile*> ProfileListImpl;



#endif // PROFILE_H
