#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QAbstractButton>
#include "datauser.h"
#include "configure.h"
#include <QMessageBox>
namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT
private:
    bool CheckBlank();

public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();
    void ShowAlreadyExistError();

signals:
    void Register(DataUser user);
    void Destruction();
private slots:
    void on_ok_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::RegisterDialog *ui;


};

#endif // REGISTER_H
