/****************************************************************************
** Meta object code from reading C++ file 'calibrate_trueb_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calibrate_trueb_dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calibrate_trueb_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_calibrate_trueb_dialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   45,   51,   51, 0x0a,
      52,   45,   51,   51, 0x0a,
      74,   51,   51,   51, 0x0a,
      98,   51,   51,   51, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_calibrate_trueb_dialog[] = {
    "calibrate_trueb_dialog\0setUpperBoundary(int)\0"
    "value\0\0setLowerBoundary(int)\0"
    "pushButtonHighPressed()\0pushButtonLowPressed()\0"
};

void calibrate_trueb_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        calibrate_trueb_dialog *_t = static_cast<calibrate_trueb_dialog *>(_o);
        switch (_id) {
        case 0: _t->setUpperBoundary((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setLowerBoundary((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->pushButtonHighPressed(); break;
        case 3: _t->pushButtonLowPressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData calibrate_trueb_dialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject calibrate_trueb_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_calibrate_trueb_dialog,
      qt_meta_data_calibrate_trueb_dialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &calibrate_trueb_dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *calibrate_trueb_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *calibrate_trueb_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_calibrate_trueb_dialog))
        return static_cast<void*>(const_cast< calibrate_trueb_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int calibrate_trueb_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
