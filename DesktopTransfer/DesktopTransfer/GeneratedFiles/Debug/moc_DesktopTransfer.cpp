/****************************************************************************
** Meta object code from reading C++ file 'DesktopTransfer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DesktopTransfer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DesktopTransfer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DesktopTransfer_t {
    QByteArrayData data[15];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DesktopTransfer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DesktopTransfer_t qt_meta_stringdata_DesktopTransfer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DesktopTransfer"
QT_MOC_LITERAL(1, 16, 23), // "on_activatedSysTrayIcon"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(4, 75, 6), // "reason"
QT_MOC_LITERAL(5, 82, 16), // "OnClickedPreview"
QT_MOC_LITERAL(6, 99, 21), // "OnClickedSaveAndStart"
QT_MOC_LITERAL(7, 121, 15), // "OnPressedSelWnd"
QT_MOC_LITERAL(8, 137, 21), // "OnCheckedChangeSelWnd"
QT_MOC_LITERAL(9, 159, 19), // "receiveSdkDatagrams"
QT_MOC_LITERAL(10, 179, 8), // "nMsgType"
QT_MOC_LITERAL(11, 188, 8), // "nSession"
QT_MOC_LITERAL(12, 197, 8), // "datagram"
QT_MOC_LITERAL(13, 206, 18), // "radioCheckedChange"
QT_MOC_LITERAL(14, 225, 5) // "index"

    },
    "DesktopTransfer\0on_activatedSysTrayIcon\0"
    "\0QSystemTrayIcon::ActivationReason\0"
    "reason\0OnClickedPreview\0OnClickedSaveAndStart\0"
    "OnPressedSelWnd\0OnCheckedChangeSelWnd\0"
    "receiveSdkDatagrams\0nMsgType\0nSession\0"
    "datagram\0radioCheckedChange\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DesktopTransfer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    3,   56,    2, 0x08 /* Private */,
      13,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QByteArray,   10,   11,   12,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void DesktopTransfer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DesktopTransfer *_t = static_cast<DesktopTransfer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_activatedSysTrayIcon((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 1: _t->OnClickedPreview(); break;
        case 2: _t->OnClickedSaveAndStart(); break;
        case 3: _t->OnPressedSelWnd(); break;
        case 4: _t->OnCheckedChangeSelWnd(); break;
        case 5: _t->receiveSdkDatagrams((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 6: _t->radioCheckedChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DesktopTransfer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DesktopTransfer.data,
      qt_meta_data_DesktopTransfer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DesktopTransfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DesktopTransfer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DesktopTransfer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DesktopTransfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
