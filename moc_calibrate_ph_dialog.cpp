/****************************************************************************
** Meta object code from reading C++ file 'calibrate_ph_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calibrate_ph_dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calibrate_ph_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Calibrate_PH_dialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   39,   45,   45, 0x05,
      46,   39,   45,   45, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   39,   45,   45, 0x0a,
      81,   39,   45,   45, 0x0a,
      97,   45,   45,   45, 0x0a,
     110,   45,   45,   45, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Calibrate_PH_dialog[] = {
    "Calibrate_PH_dialog\0ph7Changed(double)\0"
    "value\0\0ph4Changed(double)\0setTextPH7(int)\0"
    "setTextPH4(int)\0pH7Pressed()\0pH4Pressed()\0"
};

void Calibrate_PH_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Calibrate_PH_dialog *_t = static_cast<Calibrate_PH_dialog *>(_o);
        switch (_id) {
        case 0: _t->ph7Changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->ph4Changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setTextPH7((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setTextPH4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->pH7Pressed(); break;
        case 5: _t->pH4Pressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Calibrate_PH_dialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Calibrate_PH_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Calibrate_PH_dialog,
      qt_meta_data_Calibrate_PH_dialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Calibrate_PH_dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Calibrate_PH_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Calibrate_PH_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Calibrate_PH_dialog))
        return static_cast<void*>(const_cast< Calibrate_PH_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Calibrate_PH_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Calibrate_PH_dialog::ph7Changed(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Calibrate_PH_dialog::ph4Changed(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
