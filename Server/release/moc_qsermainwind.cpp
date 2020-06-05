/****************************************************************************
** Meta object code from reading C++ file 'qsermainwind.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qsermainwind.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsermainwind.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSerMainWind_t {
    QByteArrayData data[11];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSerMainWind_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSerMainWind_t qt_meta_stringdata_QSerMainWind = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QSerMainWind"
QT_MOC_LITERAL(1, 13, 15), // "onNewConnection"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "onSocketStateChange"
QT_MOC_LITERAL(4, 50, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(5, 79, 11), // "socketState"
QT_MOC_LITERAL(6, 91, 20), // "onClientDisconnected"
QT_MOC_LITERAL(7, 112, 17), // "onSocketReadyRead"
QT_MOC_LITERAL(8, 130, 26), // "on_actStopListen_triggered"
QT_MOC_LITERAL(9, 157, 27), // "on_actBeginListen_triggered"
QT_MOC_LITERAL(10, 185, 28) // "on_SendMessageButton_clicked"

    },
    "QSerMainWind\0onNewConnection\0\0"
    "onSocketStateChange\0QAbstractSocket::SocketState\0"
    "socketState\0onClientDisconnected\0"
    "onSocketReadyRead\0on_actStopListen_triggered\0"
    "on_actBeginListen_triggered\0"
    "on_SendMessageButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSerMainWind[] = {

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
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSerMainWind::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSerMainWind *_t = static_cast<QSerMainWind *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewConnection(); break;
        case 1: _t->onSocketStateChange((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 2: _t->onClientDisconnected(); break;
        case 3: _t->onSocketReadyRead(); break;
        case 4: _t->on_actStopListen_triggered(); break;
        case 5: _t->on_actBeginListen_triggered(); break;
        case 6: _t->on_SendMessageButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
}

const QMetaObject QSerMainWind::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QSerMainWind.data,
      qt_meta_data_QSerMainWind,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSerMainWind::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSerMainWind::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSerMainWind.stringdata0))
        return static_cast<void*>(const_cast< QSerMainWind*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QSerMainWind::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
