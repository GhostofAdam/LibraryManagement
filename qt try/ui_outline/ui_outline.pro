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
        mainwindow.cpp \
    logindialog.cpp \
    db.cpp\
    controller.cpp \
    registerdialog.cpp \
    data.cpp \
    datauser.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    configure.h \
    db.h\
    controller.h \
    registerdialog.h \
    data.h \
    datauser.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    registerdialog.ui
