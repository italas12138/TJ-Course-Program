/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Qt_Texteditor/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "Creat_Menu"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "New_File"
QT_MOC_LITERAL(4, 32, 9), // "maybeSave"
QT_MOC_LITERAL(5, 42, 9), // "Save_File"
QT_MOC_LITERAL(6, 52, 15), // "Save_Other_File"
QT_MOC_LITERAL(7, 68, 8), // "fileName"
QT_MOC_LITERAL(8, 77, 9), // "Open_File"
QT_MOC_LITERAL(9, 87, 10), // "Creat_Tool"
QT_MOC_LITERAL(10, 98, 8), // "Set_Font"
QT_MOC_LITERAL(11, 107, 4), // "font"
QT_MOC_LITERAL(12, 112, 12), // "Set_FontSize"
QT_MOC_LITERAL(13, 125, 5), // "index"
QT_MOC_LITERAL(14, 131, 11), // "connectImpl"
QT_MOC_LITERAL(15, 143, 9), // "Find_Text"
QT_MOC_LITERAL(16, 153, 16), // "Count_characters"
QT_MOC_LITERAL(17, 170, 12), // "Count_number"
QT_MOC_LITERAL(18, 183, 11), // "Count_space"
QT_MOC_LITERAL(19, 195, 11), // "Count_chars"
QT_MOC_LITERAL(20, 207, 12) // "Delete_chars"

    },
    "MainWindow\0Creat_Menu\0\0New_File\0"
    "maybeSave\0Save_File\0Save_Other_File\0"
    "fileName\0Open_File\0Creat_Tool\0Set_Font\0"
    "font\0Set_FontSize\0index\0connectImpl\0"
    "Find_Text\0Count_characters\0Count_number\0"
    "Count_space\0Count_chars\0Delete_chars"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       5,    1,  104,    2, 0x08 /* Private */,
       8,    1,  107,    2, 0x08 /* Private */,
       9,    0,  110,    2, 0x08 /* Private */,
      10,    1,  111,    2, 0x08 /* Private */,
      12,    1,  114,    2, 0x08 /* Private */,
      14,    0,  117,    2, 0x08 /* Private */,
      15,    0,  118,    2, 0x08 /* Private */,
      16,    0,  119,    2, 0x08 /* Private */,
      17,    0,  120,    2, 0x08 /* Private */,
      18,    0,  121,    2, 0x08 /* Private */,
      19,    0,  122,    2, 0x08 /* Private */,
      20,    0,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QFont,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Creat_Menu(); break;
        case 1: _t->New_File(); break;
        case 2: { bool _r = _t->maybeSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->Save_File();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->Save_Other_File();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->Save_File((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->Open_File((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->Creat_Tool(); break;
        case 8: _t->Set_Font((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 9: _t->Set_FontSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->connectImpl(); break;
        case 11: _t->Find_Text(); break;
        case 12: _t->Count_characters(); break;
        case 13: _t->Count_number(); break;
        case 14: _t->Count_space(); break;
        case 15: _t->Count_chars(); break;
        case 16: _t->Delete_chars(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
