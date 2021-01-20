/****************************************************************************
** Meta object code from reading C++ file 'Bullet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Bullet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Bullet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_bullet_t {
    QByteArrayData data[6];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bullet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bullet_t qt_meta_stringdata_bullet = {
    {
QT_MOC_LITERAL(0, 0, 6), // "bullet"
QT_MOC_LITERAL(1, 7, 13), // "increaseScore"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "removeEnemy"
QT_MOC_LITERAL(4, 34, 12), // "removeBullet"
QT_MOC_LITERAL(5, 47, 4) // "move"

    },
    "bullet\0increaseScore\0\0removeEnemy\0"
    "removeBullet\0move"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bullet[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       4,    1,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void bullet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<bullet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->increaseScore(); break;
        case 1: _t->removeEnemy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->removeBullet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->move(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (bullet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bullet::increaseScore)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (bullet::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bullet::removeEnemy)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (bullet::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bullet::removeBullet)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject bullet::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_bullet.data,
    qt_meta_data_bullet,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *bullet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bullet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_bullet.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "SpaceObject"))
        return static_cast< SpaceObject*>(this);
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(this);
    return QObject::qt_metacast(_clname);
}

int bullet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void bullet::increaseScore()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void bullet::removeEnemy(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void bullet::removeBullet(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
