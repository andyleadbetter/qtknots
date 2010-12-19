/****************************************************************************
** Meta object code from reading C++ file 'qdeclarativeviewobserver.h'
**
** Created: Sat Dec 18 17:56:21 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/home/andy/QtSDK/QtCreator/share/qtcreator/qml/qmljsdebugger/include/qdeclarativeviewobserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdeclarativeviewobserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QmlJSDebugger__QDeclarativeViewObserver[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: signature, parameters, type, tag, flags
      54,   41,   40,   40, 0x05,
      86,   40,   40,   40, 0x05,
     104,   40,   40,   40, 0x05,
     133,   40,   40,   40, 0x05,
     155,   40,   40,   40, 0x05,
     175,   40,   40,   40, 0x05,
     204,  198,   40,   40, 0x05,
     248,  233,   40,   40, 0x05,
     272,   40,   40,   40, 0x05,
     290,   40,   40,   40, 0x05,
     329,  316,   40,   40, 0x05,
     361,   40,   40,   40, 0x05,

 // slots: signature, parameters, type, tag, flags
     392,  386,   40,   40, 0x0a,
     425,   40,  420,   40, 0x0a,
     446,  233,   40,   40, 0x0a,
     474,  233,   40,   40, 0x0a,
     499,   40,   40,   40, 0x2a,
     519,   40,   40,   40, 0x0a,
     549,  536,   40,   40, 0x0a,
     573,   40,   40,   40, 0x08,
     589,   40,   40,   40, 0x08,
     634,   40,   40,   40, 0x08,
     678,   40,   40,   40, 0x08,
     710,  706,   40,   40, 0x08,
     769,  767,   40,   40, 0x08,
     809,   40,   40,   40, 0x08,
     839,   40,   40,   40, 0x08,
     870,   40,   40,   40, 0x08,
     892,   40,   40,   40, 0x08,
     927,  921,   40,   40, 0x08,
     958,   40,   40,   40, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QmlJSDebugger__QDeclarativeViewObserver[] = {
    "QmlJSDebugger::QDeclarativeViewObserver\0"
    "\0inDesignMode\0designModeBehaviorChanged(bool)\0"
    "reloadRequested()\0marqueeSelectToolActivated()\0"
    "selectToolActivated()\0zoomToolActivated()\0"
    "colorPickerActivated()\0color\0"
    "selectedColorChanged(QColor)\0"
    "slowdownFactor\0executionStarted(qreal)\0"
    "executionPaused()\0inspectorContextCleared()\0"
    "contextTitle\0inspectorContextPushed(QString)\0"
    "inspectorContextPopped()\0value\0"
    "setDesignModeBehavior(bool)\0bool\0"
    "designModeBehavior()\0changeAnimationSpeed(qreal)\0"
    "continueExecution(qreal)\0continueExecution()\0"
    "pauseExecution()\0contextIndex\0"
    "setObserverContext(int)\0_q_reloadView()\0"
    "_q_onStatusChanged(QDeclarativeView::Status)\0"
    "_q_onCurrentObjectsChanged(QList<QObject*>)\0"
    "_q_applyChangesFromClient()\0,,,\0"
    "_q_createQmlObject(QString,QObject*,QStringList,QString)\0"
    ",\0_q_reparentQmlObject(QObject*,QObject*)\0"
    "_q_changeToSingleSelectTool()\0"
    "_q_changeToMarqueeSelectTool()\0"
    "_q_changeToZoomTool()\0"
    "_q_changeToColorPickerTool()\0index\0"
    "_q_changeContextPathIndex(int)\0"
    "_q_clearComponentCache()\0"
};

const QMetaObject QmlJSDebugger::QDeclarativeViewObserver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QmlJSDebugger__QDeclarativeViewObserver,
      qt_meta_data_QmlJSDebugger__QDeclarativeViewObserver, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QmlJSDebugger::QDeclarativeViewObserver::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QmlJSDebugger::QDeclarativeViewObserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QmlJSDebugger::QDeclarativeViewObserver::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QmlJSDebugger__QDeclarativeViewObserver))
        return static_cast<void*>(const_cast< QDeclarativeViewObserver*>(this));
    return QObject::qt_metacast(_clname);
}

int QmlJSDebugger::QDeclarativeViewObserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: designModeBehaviorChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: reloadRequested(); break;
        case 2: marqueeSelectToolActivated(); break;
        case 3: selectToolActivated(); break;
        case 4: zoomToolActivated(); break;
        case 5: colorPickerActivated(); break;
        case 6: selectedColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 7: executionStarted((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 8: executionPaused(); break;
        case 9: inspectorContextCleared(); break;
        case 10: inspectorContextPushed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: inspectorContextPopped(); break;
        case 12: setDesignModeBehavior((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: { bool _r = designModeBehavior();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: changeAnimationSpeed((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 15: continueExecution((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 16: continueExecution(); break;
        case 17: pauseExecution(); break;
        case 18: setObserverContext((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: d_func()->_q_reloadView(); break;
        case 20: d_func()->_q_onStatusChanged((*reinterpret_cast< QDeclarativeView::Status(*)>(_a[1]))); break;
        case 21: d_func()->_q_onCurrentObjectsChanged((*reinterpret_cast< QList<QObject*>(*)>(_a[1]))); break;
        case 22: d_func()->_q_applyChangesFromClient(); break;
        case 23: d_func()->_q_createQmlObject((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 24: d_func()->_q_reparentQmlObject((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2]))); break;
        case 25: d_func()->_q_changeToSingleSelectTool(); break;
        case 26: d_func()->_q_changeToMarqueeSelectTool(); break;
        case 27: d_func()->_q_changeToZoomTool(); break;
        case 28: d_func()->_q_changeToColorPickerTool(); break;
        case 29: d_func()->_q_changeContextPathIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: d_func()->_q_clearComponentCache(); break;
        default: ;
        }
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void QmlJSDebugger::QDeclarativeViewObserver::designModeBehaviorChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QmlJSDebugger::QDeclarativeViewObserver::reloadRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QmlJSDebugger::QDeclarativeViewObserver::marqueeSelectToolActivated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QmlJSDebugger::QDeclarativeViewObserver::selectToolActivated()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QmlJSDebugger::QDeclarativeViewObserver::zoomToolActivated()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QmlJSDebugger::QDeclarativeViewObserver::colorPickerActivated()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QmlJSDebugger::QDeclarativeViewObserver::selectedColorChanged(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QmlJSDebugger::QDeclarativeViewObserver::executionStarted(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QmlJSDebugger::QDeclarativeViewObserver::executionPaused()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void QmlJSDebugger::QDeclarativeViewObserver::inspectorContextCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void QmlJSDebugger::QDeclarativeViewObserver::inspectorContextPushed(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QmlJSDebugger::QDeclarativeViewObserver::inspectorContextPopped()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}
QT_END_MOC_NAMESPACE
