/****************************************************************************
** Meta object code from reading C++ file 'knotsplayerproperties.h'
**
** Created: Thu 4. Nov 22:13:53 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../knotsplayerproperties.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'knotsplayerproperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KnotsPlayerProperties[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   43,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KnotsPlayerProperties[] = {
    "KnotsPlayerProperties\0\0propertiesUpdated()\0"
    "reply\0fetchFinished(QNetworkReply*)\0"
};

const QMetaObject KnotsPlayerProperties::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KnotsPlayerProperties,
      qt_meta_data_KnotsPlayerProperties, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KnotsPlayerProperties::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KnotsPlayerProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KnotsPlayerProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KnotsPlayerProperties))
        return static_cast<void*>(const_cast< KnotsPlayerProperties*>(this));
    if (!strcmp(_clname, "QXmlDefaultHandler"))
        return static_cast< QXmlDefaultHandler*>(const_cast< KnotsPlayerProperties*>(this));
    return QObject::qt_metacast(_clname);
}

int KnotsPlayerProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: propertiesUpdated(); break;
        case 1: fetchFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void KnotsPlayerProperties::propertiesUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
