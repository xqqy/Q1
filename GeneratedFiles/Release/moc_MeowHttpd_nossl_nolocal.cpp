/****************************************************************************
** Meta object code from reading C++ file 'MeowHttpd_nossl_nolocal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../http/MeowHttpd_nossl_nolocal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeowHttpd_nossl_nolocal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MeowHttpd__Session_t {
    QByteArrayData data[16];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeowHttpd__Session_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeowHttpd__Session_t qt_meta_stringdata_MeowHttpd__Session = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MeowHttpd::Session"
QT_MOC_LITERAL(1, 19, 9), // "replyText"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "replyData"
QT_MOC_LITERAL(4, 40, 14), // "httpStatusCode"
QT_MOC_LITERAL(5, 55, 14), // "replyRedirects"
QT_MOC_LITERAL(6, 70, 9), // "targetUrl"
QT_MOC_LITERAL(7, 80, 15), // "replyJsonObject"
QT_MOC_LITERAL(8, 96, 10), // "jsonObject"
QT_MOC_LITERAL(9, 107, 14), // "replyJsonArray"
QT_MOC_LITERAL(10, 122, 9), // "jsonArray"
QT_MOC_LITERAL(11, 132, 9), // "replyFile"
QT_MOC_LITERAL(12, 142, 8), // "filePath"
QT_MOC_LITERAL(13, 151, 10), // "replyImage"
QT_MOC_LITERAL(14, 162, 5), // "image"
QT_MOC_LITERAL(15, 168, 12) // "replyOptions"

    },
    "MeowHttpd::Session\0replyText\0\0replyData\0"
    "httpStatusCode\0replyRedirects\0targetUrl\0"
    "replyJsonObject\0jsonObject\0replyJsonArray\0"
    "jsonArray\0replyFile\0filePath\0replyImage\0"
    "image\0replyOptions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeowHttpd__Session[] = {

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
       1,    2,   79,    2, 0x0a /* Public */,
       1,    1,   84,    2, 0x2a /* Public | MethodCloned */,
       5,    2,   87,    2, 0x0a /* Public */,
       5,    1,   92,    2, 0x2a /* Public | MethodCloned */,
       7,    2,   95,    2, 0x0a /* Public */,
       7,    1,  100,    2, 0x2a /* Public | MethodCloned */,
       9,    2,  103,    2, 0x0a /* Public */,
       9,    1,  108,    2, 0x2a /* Public | MethodCloned */,
      11,    2,  111,    2, 0x0a /* Public */,
      11,    1,  116,    2, 0x2a /* Public | MethodCloned */,
      13,    2,  119,    2, 0x0a /* Public */,
      13,    1,  124,    2, 0x2a /* Public | MethodCloned */,
      15,    0,  127,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QUrl, QMetaType::Int,    6,    4,
    QMetaType::Void, QMetaType::QUrl,    6,
    QMetaType::Void, QMetaType::QJsonObject, QMetaType::Int,    8,    4,
    QMetaType::Void, QMetaType::QJsonObject,    8,
    QMetaType::Void, QMetaType::QJsonArray, QMetaType::Int,   10,    4,
    QMetaType::Void, QMetaType::QJsonArray,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   12,    4,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QImage, QMetaType::Int,   14,    4,
    QMetaType::Void, QMetaType::QImage,   14,
    QMetaType::Void,

       0        // eod
};

void MeowHttpd::Session::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Session *_t = static_cast<Session *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->replyText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->replyRedirects((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 3: _t->replyRedirects((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 4: _t->replyJsonObject((*reinterpret_cast< const QJsonObject(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 5: _t->replyJsonObject((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 6: _t->replyJsonArray((*reinterpret_cast< const QJsonArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 7: _t->replyJsonArray((*reinterpret_cast< const QJsonArray(*)>(_a[1]))); break;
        case 8: _t->replyFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 9: _t->replyFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->replyImage((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 11: _t->replyImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 12: _t->replyOptions(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MeowHttpd::Session::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MeowHttpd__Session.data,
      qt_meta_data_MeowHttpd__Session,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MeowHttpd::Session::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeowHttpd::Session::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MeowHttpd__Session.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MeowHttpd::Session::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
struct qt_meta_stringdata_MeowHttpd__AbstractManage_t {
    QByteArrayData data[5];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeowHttpd__AbstractManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeowHttpd__AbstractManage_t qt_meta_stringdata_MeowHttpd__AbstractManage = {
    {
QT_MOC_LITERAL(0, 0, 25), // "MeowHttpd::AbstractManage"
QT_MOC_LITERAL(1, 26, 12), // "readyToClose"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5), // "begin"
QT_MOC_LITERAL(4, 46, 5) // "close"

    },
    "MeowHttpd::AbstractManage\0readyToClose\0"
    "\0begin\0close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeowHttpd__AbstractManage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void MeowHttpd::AbstractManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractManage *_t = static_cast<AbstractManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyToClose(); break;
        case 1: { bool _r = _t->begin();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->close(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AbstractManage::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractManage::readyToClose)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MeowHttpd::AbstractManage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MeowHttpd__AbstractManage.data,
      qt_meta_data_MeowHttpd__AbstractManage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MeowHttpd::AbstractManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeowHttpd::AbstractManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MeowHttpd__AbstractManage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MeowHttpd::AbstractManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MeowHttpd::AbstractManage::readyToClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_MeowHttpd__TcpServerManage_t {
    QByteArrayData data[1];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeowHttpd__TcpServerManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeowHttpd__TcpServerManage_t qt_meta_stringdata_MeowHttpd__TcpServerManage = {
    {
QT_MOC_LITERAL(0, 0, 26) // "MeowHttpd::TcpServerManage"

    },
    "MeowHttpd::TcpServerManage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeowHttpd__TcpServerManage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MeowHttpd::TcpServerManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MeowHttpd::TcpServerManage::staticMetaObject = {
    { &AbstractManage::staticMetaObject, qt_meta_stringdata_MeowHttpd__TcpServerManage.data,
      qt_meta_data_MeowHttpd__TcpServerManage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MeowHttpd::TcpServerManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeowHttpd::TcpServerManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MeowHttpd__TcpServerManage.stringdata0))
        return static_cast<void*>(this);
    return AbstractManage::qt_metacast(_clname);
}

int MeowHttpd::TcpServerManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractManage::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
