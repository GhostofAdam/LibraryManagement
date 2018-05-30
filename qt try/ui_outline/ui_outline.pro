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
    register.cpp \
    db.cpp\
    controller.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    register.h \
    configure.h \
    db.h\
    controller.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    register.ui
