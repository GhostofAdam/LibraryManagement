#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QtCore>
#include <QMessageBox>
#include <QAbstractButton>
#include <QDialog>
#include <logindialog.h>
#include <db.h>
#include "configure.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    LoginDialog * loginptr = nullptr;
    DB * databaseptr = nullptr;

public:
    explicit Controller(QObject *parent = 0);
    void ShowLogin();
public slots:
    void  login(QString,QString);
signals:

public slots:
};

#endif // CONTROLLER_H
