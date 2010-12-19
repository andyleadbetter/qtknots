/****************************************************************************
** Meta object code from reading C++ file 'knotsdirectory.h'
**
** Created: Sun Dec 19 09:32:11 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "knotsdirectory.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'knotsdirectory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KnotsDirectory[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   43,   35,   15, 0x0a,
      78,   72,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KnotsDirectory[] = {
    "KnotsDirectory\0\0directoryChanged()\0"
    "QString\0itemId\0itemSelected(QString)\0"
    "reply\0onDirectoryFetchFinished(QNetworkReply*)\0"
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
    if (!strcmp(_clname, "SaxKnotsItemHandlerParserObserver"))
        return static_cast< SaxKnotsItemHandlerParserObserver*>(const_cast< KnotsDirectory*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int KnotsDirectory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: directoryChanged(); break;
        case 1: { QString _r = itemSelected((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: onDirectoryFetchFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void KnotsDirectory::directoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
