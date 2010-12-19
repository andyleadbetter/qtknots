/****************************************************************************
** Meta object code from reading C++ file 'knotsplayer.h'
**
** Created: Sat Dec 18 22:00:31 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "knotsplayer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'knotsplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KnotsPlayer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   13,   12,   12, 0x05,
      77,   68,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     117,   12,   12,   12, 0x0a,
     142,  136,   12,   12, 0x0a,
     174,   12,   12,   12, 0x0a,
     196,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KnotsPlayer[] = {
    "KnotsPlayer\0\0newProperties\0"
    "propertiesChanged(KnotsPlayerProperties)\0"
    "newState\0stateChanged(KnotsPlayer::PlayingState)\0"
    "onBacklightTimer()\0reply\0"
    "requestFinished(QNetworkReply*)\0"
    "onPropertiesUpdated()\0updateTimeout()\0"
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
        case 0: propertiesChanged((*reinterpret_cast< const KnotsPlayerProperties(*)>(_a[1]))); break;
        case 1: stateChanged((*reinterpret_cast< KnotsPlayer::PlayingState(*)>(_a[1]))); break;
        case 2: onBacklightTimer(); break;
        case 3: requestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: onPropertiesUpdated(); break;
        case 5: updateTimeout(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void KnotsPlayer::propertiesChanged(const KnotsPlayerProperties & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KnotsPlayer::stateChanged(KnotsPlayer::PlayingState _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
