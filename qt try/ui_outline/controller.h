#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QtCore>
#include <QMessageBox>
#include <QAbstractButton>
#include <QDialog>
#include "logindialog.h"
#include "db.h"
#include "configure.h"
#include "registerdialog.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    LoginDialog * loginptr = nullptr;
    DB * databaseptr = nullptr;
    RegisterDialog * registerptr = nullptr;
    MainWindow * mainwindowptr = nullptr;

public:
    explicit Controller(QObject *parent = 0);
    void ShowLogin();
public slots:
    void Login(QString,QString);
    void OpenLogin();
    void OpenRegister();
    void OpenMainWindow();
    void CloseRegister();
    void Register(DataUser data);
signals:

public slots:
};

#endif // CONTROLLER_H
