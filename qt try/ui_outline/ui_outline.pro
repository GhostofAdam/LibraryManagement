#-------------------------------------------------
#
# Project created by QtCreator 2018-05-06T10:07:20
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ui_outline
TEMPLATE = app


SOURCES += main.cpp\
    logindialog.cpp \
    db.cpp\
    controller.cpp \
    registerdialog.cpp \
    data.cpp \
    datauser.cpp \
    usermainwindow.cpp \
    bookstackedpage.cpp \
    dataadapter.cpp \
    databookadapter.cpp \
    databook.cpp \
    bookadddialog.cpp \
    bookchangedialog.cpp \
    administermainwindow.cpp

HEADERS  += logindialog.h \
    configure.h \
    db.h\
    controller.h \
    registerdialog.h \
    data.h \
    datauser.h \
    usermainwindow.h \
    bookstackedpage.h \
    dataadapter.h \
    databookadapter.h \
    databook.h \
    bookadddialog.h \
    bookchangedialog.h \
    administermainwindow.h

FORMS    += logindialog.ui \
    registerdialog.ui \
    usermainwindow.ui \
    bookstackedpage.ui \
    bookadddialog.ui \
    bookchangedialog.ui \
    administermainwindow.ui
