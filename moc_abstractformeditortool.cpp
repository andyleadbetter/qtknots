/****************************************************************************
** Meta object code from reading C++ file 'abstractformeditortool.h'
**
** Created: Sat Dec 18 17:56:21 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/home/andy/QtSDK/QtCreator/share/qtcreator/qml/qmljsdebugger/editor/abstractformeditortool.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstractformeditortool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QmlJSDebugger__AbstractFormEditorTool[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_QmlJSDebugger__AbstractFormEditorTool[] = {
    "QmlJSDebugger::AbstractFormEditorTool\0"
};

const QMetaObject QmlJSDebugger::AbstractFormEditorTool::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QmlJSDebugger__AbstractFormEditorTool,
      qt_meta_data_QmlJSDebugger__AbstractFormEditorTool, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QmlJSDebugger::AbstractFormEditorTool::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QmlJSDebugger::AbstractFormEditorTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QmlJSDebugger::AbstractFormEditorTool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QmlJSDebugger__AbstractFormEditorTool))
        return static_cast<void*>(const_cast< AbstractFormEditorTool*>(this));
    return QObject::qt_metacast(_clname);
}

int QmlJSDebugger::AbstractFormEditorTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
