/****************************************************************************
** Meta object code from reading C++ file 'area.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Catan/area.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'area.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Area_t {
    QByteArrayData data[14];
    char stringdata[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Area_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Area_t qt_meta_stringdata_Area = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 11),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 1),
QT_MOC_LITERAL(4, 20, 1),
QT_MOC_LITERAL(5, 22, 11),
QT_MOC_LITERAL(6, 34, 8),
QT_MOC_LITERAL(7, 43, 10),
QT_MOC_LITERAL(8, 54, 5),
QT_MOC_LITERAL(9, 60, 1),
QT_MOC_LITERAL(10, 62, 20),
QT_MOC_LITERAL(11, 83, 1),
QT_MOC_LITERAL(12, 85, 1),
QT_MOC_LITERAL(13, 87, 16)
    },
    "Area\0AreaClicked\0\0i\0j\0std::string\0"
    "areaType\0DeleteArea\0Area*\0p\0"
    "DistanceAreasClicked\0x\0y\0AreaRightClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Area[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06,
       7,    1,   41,    2, 0x06,
      10,    2,   44,    2, 0x06,
      13,    2,   49,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,

       0        // eod
};

void Area::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Area *_t = static_cast<Area *>(_o);
        switch (_id) {
        case 0: _t->AreaClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3]))); break;
        case 1: _t->DeleteArea((*reinterpret_cast< Area*(*)>(_a[1]))); break;
        case 2: _t->DistanceAreasClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->AreaRightClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Area* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Area::*_t)(int , int , std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Area::AreaClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (Area::*_t)(Area * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Area::DeleteArea)) {
                *result = 1;
            }
        }
        {
            typedef void (Area::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Area::DistanceAreasClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (Area::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Area::AreaRightClicked)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Area::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Area.data,
      qt_meta_data_Area,  qt_static_metacall, 0, 0}
};


const QMetaObject *Area::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Area::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Area.stringdata))
        return static_cast<void*>(const_cast< Area*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< Area*>(this));
    return QObject::qt_metacast(_clname);
}

int Area::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Area::AreaClicked(int _t1, int _t2, std::string _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Area::DeleteArea(Area * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Area::DistanceAreasClicked(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Area::AreaRightClicked(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
