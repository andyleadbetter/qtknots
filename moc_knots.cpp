/****************************************************************************
** Meta object code from reading C++ file 'knots.h'
**
** Created: Sun Dec 19 21:59:54 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "knots.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'knots.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Knots[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,    7,    6,    6, 0x05,
      59,   50,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      99,   93,    6,    6, 0x0a,
     133,    6,    6,    6, 0x0a,
     161,  152,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Knots[] = {
    "Knots\0\0newItems\0directoryChanged(KnotsDirectory*)\0"
    "profiles\0profilesChanged(ProfileListImpl*)\0"
    "reply\0onProfilesFetched(QNetworkReply*)\0"
    "onDirectoryReady()\0newState\0"
    "onPlayerStateChange(KnotsPlayer::PlayingState)\0"
};

const QMetaObject Knots::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Knots,
      qt_meta_data_Knots, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Knots::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Knots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Knots::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Knots))
        return static_cast<void*>(const_cast< Knots*>(this));
    return QObject::qt_metacast(_clname);
}

int Knots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: directoryChanged((*reinterpret_cast< KnotsDirectory*(*)>(_a[1]))); break;
        case 1: profilesChanged((*reinterpret_cast< ProfileListImpl*(*)>(_a[1]))); break;
        case 2: onProfilesFetched((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: onDirectoryReady(); break;
        case 4: onPlayerStateChange((*reinterpret_cast< KnotsPlayer::PlayingState(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Knots::directoryChanged(KnotsDirectory * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Knots::profilesChanged(ProfileListImpl * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
