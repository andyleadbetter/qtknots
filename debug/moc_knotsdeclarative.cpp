/****************************************************************************
** Meta object code from reading C++ file 'knotsdeclarative.h'
**
** Created: Thu 4. Nov 22:13:47 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../knotsdeclarative.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'knotsdeclarative.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
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
       7,   14, // methods
       1,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      49,   39,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      80,   73,   17,   17, 0x0a,
     106,   17,   17,   17, 0x0a,
     121,   17,   17,   17, 0x0a,
     140,   17,   17,   17, 0x0a,
     164,  147,   17,   17, 0x0a,

 // properties: name, type, flags
     202,  194, 0x0a495103,

 // properties: notify_signal_id
       1,

       0        // eod
};

static const char qt_meta_stringdata_KnotsDeclarative[] = {
    "KnotsDeclarative\0\0currentPathChanged()\0"
    "newSource\0sourceChanged(QString&)\0"
    "source\0onSourceChanged(QString&)\0"
    "backSelected()\0toggleFullscreen()\0"
    "stop()\0x,y,width,height\0"
    "setVideoRect(int,int,int,int)\0QString\0"
    "currentSource\0"
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
        case 2: onSourceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: backSelected(); break;
        case 4: toggleFullscreen(); break;
        case 5: stop(); break;
        case 6: setVideoRect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getCurrentSource(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCurrentSource(*reinterpret_cast< QString*>(_v)); break;
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
static const uint qt_meta_data_KnotsDirectory[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      29,   16,   15,   15, 0x0a,
      84,   77,   69,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KnotsDirectory[] = {
    "KnotsDirectory\0\0newDirectory\0"
    "onDirectoryChanged(KnotsDirectoryImpl*)\0"
    "QString\0itemId\0itemSelected(QString)\0"
};

const QMetaObject KnotsDirectory::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_KnotsDirectory,
      qt_meta_data_KnotsDirectory, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KnotsDirectory::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KnotsDirectory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KnotsDirectory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KnotsDirectory))
        return static_cast<void*>(const_cast< KnotsDirectory*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int KnotsDirectory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onDirectoryChanged((*reinterpret_cast< KnotsDirectoryImpl*(*)>(_a[1]))); break;
        case 1: { QString _r = itemSelected((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
