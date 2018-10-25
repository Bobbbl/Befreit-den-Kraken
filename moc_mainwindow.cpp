/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   41,   53,   53, 0x0a,
      54,   53,   53,   53, 0x0a,
      66,   53,   53,   53, 0x0a,
      88,   53,   53,   53, 0x0a,
     106,   53,   53,   53, 0x0a,
     127,  147,   53,   53, 0x0a,
     153,   53,   53,   53, 0x0a,
     175,   53,   53,   53, 0x0a,
     200,   53,   53,   53, 0x0a,
     213,  234,   53,   53, 0x0a,
     239,   53,  250,   53, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0saveAndCheck(QString,QString)\0"
    "path,inhalt\0\0saverSlot()\0WLAN_Button_Pressed()\0"
    "readPHSensor(int)\0readTruebSensor(int)\0"
    "readTempSensor(int)\0value\0"
    "CalibratePH_Pressed()\0pushButtonTruebPressed()\0"
    "uhrPressed()\0refreshPath(QString)\0"
    "path\0readTemp()\0double\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->saveAndCheck((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->saverSlot(); break;
        case 2: _t->WLAN_Button_Pressed(); break;
        case 3: _t->readPHSensor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->readTruebSensor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->readTempSensor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->CalibratePH_Pressed(); break;
        case 7: _t->pushButtonTruebPressed(); break;
        case 8: _t->uhrPressed(); break;
        case 9: _t->refreshPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: { double _r = _t->readTemp();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
