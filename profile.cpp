#include <QObject>
#include <QString>
#include "profile.h"

Profile::Profile(QObject *parent) :
    QObject(parent)
{
}

QString Profile::getId() const
{
    return _id;
}

void Profile::setId(QString &id) {
    _id = id;
}

QString Profile::getName() const {
    return _name;
}

void Profile::setName(QString &name)
{
    _name = name;
}

QString Profile::getCodec() const
{
    return _codec;
}

void Profile::setCodec(QString &codec) {
    _codec = codec;
}

QString Profile::getBitrate() const {
    return _bitrate;
}

void Profile::setBitrate(QString &bitrate) {
    _bitrate = bitrate;
}



