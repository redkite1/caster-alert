/****************************************************************************
** Meta object code from reading C++ file 'casteralertlistenerimpl.h'
**
** Created: Tue Dec 16 19:33:51 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/casteralertlistenerimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'casteralertlistenerimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CasterAlertListenerImpl[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x0a,
      43,   24,   24,   24, 0x08,
      66,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CasterAlertListenerImpl[] = {
    "CasterAlertListenerImpl\0\0startListenning()\0"
    "readPendingDatagrams()\0stopListenning()\0"
};

const QMetaObject CasterAlertListenerImpl::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CasterAlertListenerImpl,
      qt_meta_data_CasterAlertListenerImpl, 0 }
};

const QMetaObject *CasterAlertListenerImpl::metaObject() const
{
    return &staticMetaObject;
}

void *CasterAlertListenerImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CasterAlertListenerImpl))
        return static_cast<void*>(const_cast< CasterAlertListenerImpl*>(this));
    if (!strcmp(_clname, "Ui::CasterAlertListenerGUI"))
        return static_cast< Ui::CasterAlertListenerGUI*>(const_cast< CasterAlertListenerImpl*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CasterAlertListenerImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startListenning(); break;
        case 1: readPendingDatagrams(); break;
        case 2: stopListenning(); break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
