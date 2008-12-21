/****************************************************************************
** Meta object code from reading C++ file 'casteralertsenderimpl.h'
**
** Created: Sun Dec 21 17:27:08 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/casteralertsenderimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'casteralertsenderimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CasterAlertSenderImpl[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      47,   22,   22,   22, 0x08,
      76,   22,   22,   22, 0x08,
     103,   22,   22,   22, 0x08,
     133,   22,   22,   22, 0x08,
     148,   22,   22,   22, 0x08,
     170,  164,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CasterAlertSenderImpl[] = {
    "CasterAlertSenderImpl\0\0readPendingDatagramsM()\0"
    "on_sendAlertButton_clicked()\0"
    "on_addUserButton_clicked()\0"
    "on_removeUserButton_clicked()\0"
    "readSettings()\0writeSettings()\0event\0"
    "closeEvent(QCloseEvent*)\0"
};

const QMetaObject CasterAlertSenderImpl::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CasterAlertSenderImpl,
      qt_meta_data_CasterAlertSenderImpl, 0 }
};

const QMetaObject *CasterAlertSenderImpl::metaObject() const
{
    return &staticMetaObject;
}

void *CasterAlertSenderImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CasterAlertSenderImpl))
        return static_cast<void*>(const_cast< CasterAlertSenderImpl*>(this));
    if (!strcmp(_clname, "Ui::CasterAlertSenderGUI"))
        return static_cast< Ui::CasterAlertSenderGUI*>(const_cast< CasterAlertSenderImpl*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CasterAlertSenderImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: readPendingDatagramsM(); break;
        case 1: on_sendAlertButton_clicked(); break;
        case 2: on_addUserButton_clicked(); break;
        case 3: on_removeUserButton_clicked(); break;
        case 4: readSettings(); break;
        case 5: writeSettings(); break;
        case 6: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
