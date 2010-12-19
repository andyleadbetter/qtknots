/****************************************************************************
** Meta object code from reading C++ file 'knotsdeclarative.h'
**
** Created: Sun Dec 19 09:32:06 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "knotsdeclarative.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'knotsdeclarative.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProfileList[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   19, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   13,   12,   12, 0x0a,

 // properties: name, type, flags
      72,   64, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_ProfileList[] = {
    "ProfileList\0\0newProfileList\0"
    "onProfilesChanged(ProfileListImpl*)\0"
    "QString\0currentProfile\0"
};

const QMetaObject ProfileList::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_ProfileList,
      qt_meta_data_ProfileList, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProfileList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProfileList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProfileList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProfileList))
        return static_cast<void*>(const_cast< ProfileList*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int ProfileList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onProfilesChanged((*reinterpret_cast< ProfileListImpl*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getCurrentProfile(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCurrentProfile(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
static const uint qt_meta_data_KnotsDeclarative[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       5,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      49,   39,   17,   17, 0x05,
      85,   73,   17,   17, 0x05,
     120,  108,   17,   17, 0x05,
     156,  143,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     190,   17,   17,   17, 0x0a,
     210,  203,   17,   17, 0x0a,
     236,   17,   17,   17, 0x0a,
     251,   17,   17,   17, 0x0a,
     267,  258,   17,   17, 0x0a,
     293,  279,   17,   17, 0x0a,
     346,  336,   17,   17, 0x0a,

 // properties: name, type, flags
     370,  362, 0x0a495103,
     390,  384, 0x87495001,
     258,  384, 0x87495001,
     399,  362, 0x0a095103,
     426,  410, 0x00495009,

 // properties: notify_signal_id
       1,
       2,
       3,
       0,
       4,

       0        // eod
};

static const char qt_meta_stringdata_KnotsDeclarative[] = {
    "KnotsDeclarative\0\0currentPathChanged()\0"
    "newSource\0sourceChanged(QString&)\0"
    "newDuration\0durationChanged(float)\0"
    "newPosition\0positionChanged(float)\0"
    "newDirectory\0directoryChanged(KnotsDirectory*)\0"
    "taskSwitch()\0source\0onSourceChanged(QString&)\0"
    "backSelected()\0stop()\0position\0"
    "seek(float)\0newProperties\0"
    "onPropertiesUpdated(KnotsPlayerProperties)\0"
    "searchTag\0search(QString)\0QString\0"
    "currentSource\0float\0duration\0serverName\0"
    "KnotsDirectory*\0currentDirectory\0"
};

const QMetaObject KnotsDeclarative::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KnotsDeclarative,
      qt_meta_data_KnotsDeclarative, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KnotsDeclarative::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KnotsDeclarative::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KnotsDeclarative::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KnotsDeclarative))
        return static_cast<void*>(const_cast< KnotsDeclarative*>(this));
    return QObject::qt_metacast(_clname);
}

int KnotsDeclarative::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: currentPathChanged(); break;
        case 1: sourceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: durationChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: positionChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: directoryChanged((*reinterpret_cast< KnotsDirectory*(*)>(_a[1]))); break;
        case 5: taskSwitch(); break;
        case 6: onSourceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: backSelected(); break;
        case 8: stop(); break;
        case 9: seek((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: onPropertiesUpdated((*reinterpret_cast< const KnotsPlayerProperties(*)>(_a[1]))); break;
        case 11: search((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getCurrentSource(); break;
        case 1: *reinterpret_cast< float*>(_v) = getDuration(); break;
        case 2: *reinterpret_cast< float*>(_v) = getPosition(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getServerName(); break;
        case 4: *reinterpret_cast< KnotsDirectory**>(_v) = getDirectory(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCurrentSource(*reinterpret_cast< QString*>(_v)); break;
        case 3: setServerName(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void KnotsDeclarative::currentPathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void KnotsDeclarative::sourceChanged(QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KnotsDeclarative::durationChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KnotsDeclarative::positionChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KnotsDeclarative::directoryChanged(KnotsDirectory * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
