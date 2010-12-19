/****************************************************************************
** Meta object code from reading C++ file 'subcomponenteditortool.h'
**
** Created: Sat Dec 18 17:56:22 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/home/andy/QtSDK/QtCreator/share/qtcreator/qml/qmljsdebugger/editor/subcomponenteditortool.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'subcomponenteditortool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QmlJSDebugger__SubcomponentEditorTool[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      39,   38,   38,   38, 0x05,
      62,   38,   38,   38, 0x05,
      85,   72,   38,   38, 0x05,
     108,   38,   38,   38, 0x05,
     129,  124,   38,   38, 0x05,

 // slots: signature, parameters, type, tag, flags
     161,   38,   38,   38, 0x08,
     179,  171,   38,   38, 0x08,
     206,   38,   38,   38, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QmlJSDebugger__SubcomponentEditorTool[] = {
    "QmlJSDebugger::SubcomponentEditorTool\0"
    "\0exitContextRequested()\0cleared()\0"
    "contextTitle\0contextPushed(QString)\0"
    "contextPopped()\0path\0"
    "contextPathChanged(QStringList)\0"
    "animate()\0context\0contextDestroyed(QObject*)\0"
    "resizeMask()\0"
};

const QMetaObject QmlJSDebugger::SubcomponentEditorTool::staticMetaObject = {
    { &AbstractFormEditorTool::staticMetaObject, qt_meta_stringdata_QmlJSDebugger__SubcomponentEditorTool,
      qt_meta_data_QmlJSDebugger__SubcomponentEditorTool, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QmlJSDebugger::SubcomponentEditorTool::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QmlJSDebugger::SubcomponentEditorTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QmlJSDebugger::SubcomponentEditorTool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QmlJSDebugger__SubcomponentEditorTool))
        return static_cast<void*>(const_cast< SubcomponentEditorTool*>(this));
    return AbstractFormEditorTool::qt_metacast(_clname);
}

int QmlJSDebugger::SubcomponentEditorTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractFormEditorTool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: exitContextRequested(); break;
        case 1: cleared(); break;
        case 2: contextPushed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: contextPopped(); break;
        case 4: contextPathChanged((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 5: animate(); break;
        case 6: contextDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 7: resizeMask(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QmlJSDebugger::SubcomponentEditorTool::exitContextRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QmlJSDebugger::SubcomponentEditorTool::cleared()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QmlJSDebugger::SubcomponentEditorTool::contextPushed(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QmlJSDebugger::SubcomponentEditorTool::contextPopped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QmlJSDebugger::SubcomponentEditorTool::contextPathChanged(const QStringList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
