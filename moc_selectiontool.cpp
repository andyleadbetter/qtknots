/****************************************************************************
** Meta object code from reading C++ file 'selectiontool.h'
**
** Created: Sun Dec 19 21:28:56 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/home/andy/QtSDK/QtCreator/share/qtcreator/qml/qmljsdebugger/editor/selectiontool.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectiontool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QmlJSDebugger__SelectionTool[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x08,
      66,   59,   29,   29, 0x08,
     102,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QmlJSDebugger__SelectionTool[] = {
    "QmlJSDebugger::SelectionTool\0\0"
    "contextMenuElementSelected()\0action\0"
    "contextMenuElementHovered(QAction*)\0"
    "repaintBoundingRects()\0"
};

const QMetaObject QmlJSDebugger::SelectionTool::staticMetaObject = {
    { &AbstractFormEditorTool::staticMetaObject, qt_meta_stringdata_QmlJSDebugger__SelectionTool,
      qt_meta_data_QmlJSDebugger__SelectionTool, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QmlJSDebugger::SelectionTool::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QmlJSDebugger::SelectionTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QmlJSDebugger::SelectionTool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QmlJSDebugger__SelectionTool))
        return static_cast<void*>(const_cast< SelectionTool*>(this));
    return AbstractFormEditorTool::qt_metacast(_clname);
}

int QmlJSDebugger::SelectionTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractFormEditorTool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: contextMenuElementSelected(); break;
        case 1: contextMenuElementHovered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: repaintBoundingRects(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
