/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Aug 17 16:25:41 2010
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      29,   11,   11,   11, 0x0a,
      46,   11,   11,   11, 0x0a,
      63,   11,   11,   11, 0x0a,
      80,   11,   11,   11, 0x0a,
      97,   11,   11,   11, 0x0a,
     114,   11,   11,   11, 0x0a,
     131,   11,   11,   11, 0x0a,
     148,   11,   11,   11, 0x0a,
     165,   11,   11,   11, 0x0a,
     182,   11,   11,   11, 0x0a,
     201,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0slot_pbutton_1()\0"
    "slot_pbutton_2()\0slot_pbutton_3()\0"
    "slot_pbutton_4()\0slot_pbutton_5()\0"
    "slot_pbutton_6()\0slot_pbutton_7()\0"
    "slot_pbutton_8()\0slot_pbutton_9()\0"
    "slot_pbutton_0()\0slot_pbutton_and()\0"
    "slot_pbutton_sub()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
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
        switch (_id) {
        case 0: slot_pbutton_1(); break;
        case 1: slot_pbutton_2(); break;
        case 2: slot_pbutton_3(); break;
        case 3: slot_pbutton_4(); break;
        case 4: slot_pbutton_5(); break;
        case 5: slot_pbutton_6(); break;
        case 6: slot_pbutton_7(); break;
        case 7: slot_pbutton_8(); break;
        case 8: slot_pbutton_9(); break;
        case 9: slot_pbutton_0(); break;
        case 10: slot_pbutton_and(); break;
        case 11: slot_pbutton_sub(); break;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
