/****************************************************************************
** Meta object code from reading C++ file 'previewmazeview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../previewmazeview.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'previewmazeview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPreviewMazeViewENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPreviewMazeViewENDCLASS = QtMocHelpers::stringData(
    "PreviewMazeView",
    "errorCatched",
    "",
    "errorLog",
    "incrementCellsH",
    "h",
    "incrementCellsV",
    "decrementCellsH",
    "decrementCellsV",
    "addEntrance",
    "AbstractGraphicsRectItem*",
    "a",
    "addExit",
    "removeExit",
    "removeEntrance",
    "X",
    "Y"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPreviewMazeViewENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   83,    2, 0x0a,    3 /* Public */,
       6,    1,   86,    2, 0x0a,    5 /* Public */,
       7,    1,   89,    2, 0x0a,    7 /* Public */,
       8,    1,   92,    2, 0x0a,    9 /* Public */,
       9,    1,   95,    2, 0x0a,   11 /* Public */,
      12,    1,   98,    2, 0x0a,   13 /* Public */,
      13,    0,  101,    2, 0x0a,   15 /* Public */,
      14,    0,  102,    2, 0x0a,   16 /* Public */,
      15,    0,  103,    2, 0x0a,   17 /* Public */,
      16,    0,  104,    2, 0x0a,   18 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

Q_CONSTINIT const QMetaObject PreviewMazeView::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_CLASSPreviewMazeViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPreviewMazeViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPreviewMazeViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PreviewMazeView, std::true_type>,
        // method 'errorCatched'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'incrementCellsH'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'incrementCellsV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'decrementCellsH'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'decrementCellsV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'addEntrance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AbstractGraphicsRectItem *, std::false_type>,
        // method 'addExit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AbstractGraphicsRectItem *, std::false_type>,
        // method 'removeExit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeEntrance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'X'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'Y'
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void PreviewMazeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PreviewMazeView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->errorCatched((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->incrementCellsH((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->incrementCellsV((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->decrementCellsH((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->decrementCellsV((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->addEntrance((*reinterpret_cast< std::add_pointer_t<AbstractGraphicsRectItem*>>(_a[1]))); break;
        case 6: _t->addExit((*reinterpret_cast< std::add_pointer_t<AbstractGraphicsRectItem*>>(_a[1]))); break;
        case 7: _t->removeExit(); break;
        case 8: _t->removeEntrance(); break;
        case 9: { int _r = _t->X();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->Y();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AbstractGraphicsRectItem* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AbstractGraphicsRectItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PreviewMazeView::*)(QString );
            if (_t _q_method = &PreviewMazeView::errorCatched; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *PreviewMazeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreviewMazeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPreviewMazeViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int PreviewMazeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void PreviewMazeView::errorCatched(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
