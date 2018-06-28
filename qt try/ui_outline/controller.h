#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QtCore>
#include <QMessageBox>
#include <QAbstractButton>
#include <QDialog>
#include <QDebug>

#include "logindialog.h"
#include "db.h"
#include "configure.h"
#include "registerdialog.h"
#include "usermainwindow.h"
#include "administermainwindow.h"
#include "databook.h"
#include "bookadddialog.h"

class BookAddDialog;
class Controller : public QObject
{
    Q_OBJECT
private:
    LoginDialog * loginptr = nullptr;
    DB * databaseptr = nullptr;
    RegisterDialog * registerptr = nullptr;
    UserMainWindow * mainwindowptr = nullptr;
    AdministerMainWindow * mainwindowptr2 = nullptr;

public:
    explicit Controller(QObject *parent = 0);
    void ShowLogin();
public slots:
    void Login(QString,QString,QString type);
    void OpenLogin();
    void OpenRegister();
    void OpenUserMainWindow();
    void OpenAdministerMainWindow();
    void CloseRegister();
    void Register(DataUser data);
    void SearchBook(QString search_info, QString search_type);
    //连接不同的ui窗口
    void InsertBook();
    void InsertBook(DataBook book);
    void ChangeBook(QString id);
    void ChangeBook(QString id, DataBook book);
    void SelectBookIsbn(QString isbn);//???
    void AppointBook(QString id);//??id or isbn

    void ChangePassword(QString account,QString password);

    void SearchRecord(QString key, QString type);
    void ExtendRecord(QString id);
    void FinishRecord(QString id);

    void ChangeUser(QString account, DataUser newinfo);
signals:

public slots:
};

#endif // CONTROLLER_H
