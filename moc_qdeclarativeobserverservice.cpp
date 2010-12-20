/****************************************************************************
** Meta object code from reading C++ file 'qdeclarativeobserverservice.h'
**
** Created: Sun Dec 19 21:28:56 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/home/andy/QtSDK/QtCreator/share/qtcreator/qml/qmljsdebugger/include/qdeclarativeobserverservice.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdeclarativeobserverservice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QmlJSDebugger__QDeclarativeObserverService[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: signature, parameters, type, tag, flags
      63,   44,   43,   43, 0x05,
     100,   92,   43,   43, 0x05,
     152,  139,   43,   43, 0x05,
     184,   43,   43,   43, 0x05,
     202,   43,   43,   43, 0x05,
     224,   43,   43,   43, 0x05,
     253,   43,   43,   43, 0x05,
     273,   43,   43,   43, 0x05,
     328,  300,   43,   43, 0x05,
     409,  390,   43,   43, 0x25,
     480,  463,   43,   43, 0x05,
     535,  523,   43,   43, 0x05,
     589,  572,   43,   43, 0x05,
     618,   43,   43,   43, 0x05,

 // slots: signature, parameters, type, tag, flags
     655,  649,   43,   43, 0x0a,
     696,  684,   43,   43, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QmlJSDebugger__QDeclarativeObserverService[] = {
    "QmlJSDebugger::QDeclarativeObserverService\0"
    "\0hasDebuggingClient\0debuggingClientChanged(bool)\0"
    "objects\0currentObjectsChanged(QList<QObject*>)\0"
    "inDesignMode\0designModeBehaviorChanged(bool)\0"
    "reloadRequested()\0selectToolRequested()\0"
    "selectMarqueeToolRequested()\0"
    "zoomToolRequested()\0colorPickerToolRequested()\0"
    "qml,parent,imports,filename\0"
    "objectCreationRequested(QString,QObject*,QStringList,QString)\0"
    "qml,parent,imports\0"
    "objectCreationRequested(QString,QObject*,QStringList)\0"
    "object,newParent\0"
    "objectReparentRequested(QObject*,QObject*)\0"
    "speedFactor\0animationSpeedChangeRequested(qreal)\0"
    "contextPathIndex\0contextPathIndexChanged(int)\0"
    "clearComponentCacheRequested()\0color\0"
    "selectedColorChanged(QColor)\0contextPath\0"
    "contextPathUpdated(QStringList)\0"
};

const QMetaObject QmlJSDebugger::QDeclarativeObserverService::staticMetaObject = {
    { &QDeclarativeDebugService::staticMetaObject, qt_meta_stringdata_QmlJSDebugger__QDeclarativeObserverService,
      qt_meta_data_QmlJSDebugger__QDeclarativeObserverService, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QmlJSDebugger::QDeclarativeObserverService::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QmlJSDebugger::QDeclarativeObserverService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QmlJSDebugger::QDeclarativeObserverService::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QmlJSDebugger__QDeclarativeObserverService))
        return static_cast<void*>(const_cast< QDeclarativeObserverService*>(this));
    return QDeclarativeDebugService::qt_metacast(_clname);
}

int QmlJSDebugger::QDeclarativeObserverService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeDebugService::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: debuggingClientChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: currentObjectsChanged((*reinterpret_cast< const QList<QObject*>(*)>(_a[1]))); break;
        case 2: designModeBehaviorChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: reloadRequested(); break;
        case 4: selectToolRequested(); break;
        case 5: selectMarqueeToolRequested(); break;
        case 6: zoomToolRequested(); break;
        case 7: colorPickerToolRequested(); break;
        case 8: objectCreationRequested((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 9: objectCreationRequested((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3]))); break;
        case 10: objectReparentRequested((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2]))); break;
        case 11: animationSpeedChangeRequested((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 12: contextPathIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: clearComponentCacheRequested(); break;
        case 14: selectedColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 15: contextPathUpdated((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void QmlJSDebugger::QDeclarativeObserverService::debuggingClientChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QmlJSDebugger::QDeclarativeObserverService::currentObjectsChanged(const QList<QObject*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QmlJSDebugger::QDeclarativeObserverService::designModeBehaviorChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QmlJSDebugger::QDeclarativeObserverService::reloadRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QmlJSDebugger::QDeclarativeObserverService::selectToolRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QmlJSDebugger::QDeclarativeObserverService::selectMarqueeToolRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QmlJSDebugger::QDeclarativeObserverService::zoomToolRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void QmlJSDebugger::QDeclarativeObserverService::colorPickerToolRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void QmlJSDebugger::QDeclarativeObserverService::objectCreationRequested(const QString & _t1, QObject * _t2, const QStringList & _t3, const QString & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 10
void QmlJSDebugger::QDeclarativeObserverService::objectReparentRequested(QObject * _t1, QObject * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QmlJSDebugger::QDeclarativeObserverService::animationSpeedChangeRequested(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QmlJSDebugger::QDeclarativeObserverService::contextPathIndexChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QmlJSDebugger::QDeclarativeObserverService::clearComponentCacheRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}
QT_END_MOC_NAMESPACE
