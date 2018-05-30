#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QAbstractButton>
#include <QDialog>
#include <QtCore>
#include <QMessageBox>
#include "configure.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

    void OpenMainWindowofStudent();
    void OpenMainWindowofAdministrator();
    void ShowUnmatchRefutation();
    void ShowBlankRefutation();
    void ShowNoQuestRefutation();
signals:
    void LoginSignals(QString accnount, QString password);
    void LoginDestruction();

private slots:
    void on_LoginButton_clicked();
    void on_RegisterButton_clicked();
    void on_CancelButton_clicked();
//    void debug(QString accnount, QString password);

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
