/****************************************************************************
** Meta object code from reading C++ file 'knotsplayer.h'
**
** Created: Thu 4. Nov 22:13:53 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../knotsplayer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'knotsplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KnotsPlayer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   47,   12,   12, 0x0a,
      85,   12,   12,   12, 0x0a,
     107,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KnotsPlayer[] = {
    "KnotsPlayer\0\0newSource\0sourceChanged(QString&)\0"
    "reply\0requestFinished(QNetworkReply*)\0"
    "onPropertiesUpdated()\0positionChanged(qint64)\0"
};

const QMetaObject KnotsPlayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KnotsPlayer,
      qt_meta_data_KnotsPlayer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KnotsPlayer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KnotsPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KnotsPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KnotsPlayer))
        return static_cast<void*>(const_cast< KnotsPlayer*>(this));
    return QObject::qt_metacast(_clname);
}

int KnotsPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sourceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: requestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: onPropertiesUpdated(); break;
        case 3: positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void KnotsPlayer::sourceChanged(QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
