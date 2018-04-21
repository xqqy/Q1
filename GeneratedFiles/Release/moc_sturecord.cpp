/****************************************************************************
** Meta object code from reading C++ file 'sturecord.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sturecord.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sturecord.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sturecord_t {
    QByteArrayData data[21];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sturecord_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sturecord_t qt_meta_stringdata_sturecord = {
    {
QT_MOC_LITERAL(0, 0, 9), // "sturecord"
QT_MOC_LITERAL(1, 10, 13), // "stopRecording"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "play"
QT_MOC_LITERAL(4, 30, 3), // "doc"
QT_MOC_LITERAL(5, 34, 6), // "inerst"
QT_MOC_LITERAL(6, 41, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 63, 31), // "on_listWidget_currentRowChanged"
QT_MOC_LITERAL(8, 95, 10), // "currentRow"
QT_MOC_LITERAL(9, 106, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(10, 130, 11), // "playerstate"
QT_MOC_LITERAL(11, 142, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(12, 162, 5), // "state"
QT_MOC_LITERAL(13, 168, 30), // "on_commandLinkButton_2_clicked"
QT_MOC_LITERAL(14, 199, 5), // "check"
QT_MOC_LITERAL(15, 205, 14), // "QNetworkReply*"
QT_MOC_LITERAL(16, 220, 5), // "reply"
QT_MOC_LITERAL(17, 226, 4), // "done"
QT_MOC_LITERAL(18, 231, 9), // "timerDone"
QT_MOC_LITERAL(19, 241, 4), // "init"
QT_MOC_LITERAL(20, 246, 8) // "countlow"

    },
    "sturecord\0stopRecording\0\0play\0doc\0"
    "inerst\0on_pushButton_clicked\0"
    "on_listWidget_currentRowChanged\0"
    "currentRow\0on_pushButton_2_clicked\0"
    "playerstate\0QMediaPlayer::State\0state\0"
    "on_commandLinkButton_2_clicked\0check\0"
    "QNetworkReply*\0reply\0done\0timerDone\0"
    "init\0countlow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sturecord[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    1,   80,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    1,   85,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    1,   89,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    1,   93,    2, 0x08 /* Private */,
      17,    0,   96,    2, 0x08 /* Private */,
      18,    0,   97,    2, 0x08 /* Private */,
      19,    0,   98,    2, 0x08 /* Private */,
      20,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void sturecord::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        sturecord *_t = static_cast<sturecord *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stopRecording(); break;
        case 1: _t->play((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->inerst(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_listWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->playerstate((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 7: _t->on_commandLinkButton_2_clicked(); break;
        case 8: _t->check((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 9: _t->done(); break;
        case 10: _t->timerDone(); break;
        case 11: _t->init(); break;
        case 12: _t->countlow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject sturecord::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_sturecord.data,
      qt_meta_data_sturecord,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *sturecord::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sturecord::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sturecord.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int sturecord::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
