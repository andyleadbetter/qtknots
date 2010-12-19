/****************************************************************************
** Meta object code from reading C++ file 'qmltoolbar.h'
**
** Created: Sat Dec 18 17:56:22 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/home/andy/QtSDK/QtCreator/share/qtcreator/qml/qmljsdebugger/editor/qmltoolbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmltoolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QmlJSDebugger__QmlToolbar[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      42,   27,   26,   26, 0x05,
      71,   26,   26,   26, 0x25,
     108,   95,   26,   26, 0x05,
     140,   26,   26,   26, 0x05,
     162,   26,   26,   26, 0x05,
     183,   26,   26,   26, 0x05,
     211,   26,   26,   26, 0x05,
     230,   26,   26,   26, 0x05,
     262,   26,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
     296,   95,   26,   26, 0x0a,
     330,  324,   26,   26, 0x0a,
     355,   26,   26,   26, 0x0a,
     377,   26,   26,   26, 0x0a,
     398,   26,   26,   26, 0x0a,
     426,   26,   26,   26, 0x0a,
     441,   27,   26,   26, 0x0a,
     466,   26,   26,   26, 0x2a,
     486,   95,   26,   26, 0x08,
     521,   26,   26,   26, 0x08,
     543,   26,   26,   26, 0x08,
     572,   26,   26,   26, 0x08,
     600,   26,   26,   26, 0x08,
     635,   26,   26,   26, 0x08,
     657,   26,   26,   26, 0x08,
     675,   26,   26,   26, 0x08,
     691,   26,   26,   26, 0x08,
     718,   26,   26,   26, 0x08,
     742,   26,   26,   26, 0x08,
     768,   26,   26,   26, 0x08,
     794,   26,   26,   26, 0x08,
     819,   26,   26,   26, 0x08,
     838,   26,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QmlJSDebugger__QmlToolbar[] = {
    "QmlJSDebugger::QmlToolbar\0\0slowdownFactor\0"
    "animationSpeedChanged(qreal)\0"
    "animationSpeedChanged()\0inDesignMode\0"
    "designModeBehaviorChanged(bool)\0"
    "colorPickerSelected()\0selectToolSelected()\0"
    "marqueeSelectToolSelected()\0"
    "zoomToolSelected()\0applyChangesToQmlFileSelected()\0"
    "applyChangesFromQmlFileSelected()\0"
    "setDesignModeBehavior(bool)\0color\0"
    "setColorBoxColor(QColor)\0activateColorPicker()\0"
    "activateSelectTool()\0activateMarqueeSelectTool()\0"
    "activateZoom()\0setAnimationSpeed(qreal)\0"
    "setAnimationSpeed()\0"
    "setDesignModeBehaviorOnClick(bool)\0"
    "activatePlayOnClick()\0"
    "activateColorPickerOnClick()\0"
    "activateSelectToolOnClick()\0"
    "activateMarqueeSelectToolOnClick()\0"
    "activateZoomOnClick()\0activateFromQml()\0"
    "activateToQml()\0changeToDefaultAnimSpeed()\0"
    "changeToHalfAnimSpeed()\0"
    "changeToFourthAnimSpeed()\0"
    "changeToEighthAnimSpeed()\0"
    "changeToTenthAnimSpeed()\0updatePlayAction()\0"
    "updatePauseAction()\0"
};

const QMetaObject QmlJSDebugger::QmlToolbar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_QmlJSDebugger__QmlToolbar,
      qt_meta_data_QmlJSDebugger__QmlToolbar, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QmlJSDebugger::QmlToolbar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QmlJSDebugger::QmlToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QmlJSDebugger::QmlToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QmlJSDebugger__QmlToolbar))
        return static_cast<void*>(const_cast< QmlToolbar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int QmlJSDebugger::QmlToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: animationSpeedChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: animationSpeedChanged(); break;
        case 2: designModeBehaviorChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: colorPickerSelected(); break;
        case 4: selectToolSelected(); break;
        case 5: marqueeSelectToolSelected(); break;
        case 6: zoomToolSelected(); break;
        case 7: applyChangesToQmlFileSelected(); break;
        case 8: applyChangesFromQmlFileSelected(); break;
        case 9: setDesignModeBehavior((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: setColorBoxColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 11: activateColorPicker(); break;
        case 12: activateSelectTool(); break;
        case 13: activateMarqueeSelectTool(); break;
        case 14: activateZoom(); break;
        case 15: setAnimationSpeed((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 16: setAnimationSpeed(); break;
        case 17: setDesignModeBehaviorOnClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: activatePlayOnClick(); break;
        case 19: activateColorPickerOnClick(); break;
        case 20: activateSelectToolOnClick(); break;
        case 21: activateMarqueeSelectToolOnClick(); break;
        case 22: activateZoomOnClick(); break;
        case 23: activateFromQml(); break;
        case 24: activateToQml(); break;
        case 25: changeToDefaultAnimSpeed(); break;
        case 26: changeToHalfAnimSpeed(); break;
        case 27: changeToFourthAnimSpeed(); break;
        case 28: changeToEighthAnimSpeed(); break;
        case 29: changeToTenthAnimSpeed(); break;
        case 30: updatePlayAction(); break;
        case 31: updatePauseAction(); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void QmlJSDebugger::QmlToolbar::animationSpeedChanged(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void QmlJSDebugger::QmlToolbar::designModeBehaviorChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QmlJSDebugger::QmlToolbar::colorPickerSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QmlJSDebugger::QmlToolbar::selectToolSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QmlJSDebugger::QmlToolbar::marqueeSelectToolSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QmlJSDebugger::QmlToolbar::zoomToolSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void QmlJSDebugger::QmlToolbar::applyChangesToQmlFileSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void QmlJSDebugger::QmlToolbar::applyChangesFromQmlFileSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
