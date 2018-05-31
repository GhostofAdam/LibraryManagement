#include "registerdialog.h"
#include "ui_registerdialog.h"

bool RegisterDialog::CheckBlank()
{
    QString account = ui->account->text();
    QString password = ui->password->text();
    QString schoolID = ui->schoolID->text();
    QString department = ui->department->text();
    QString major = ui->major->text();
    QString name = ui->name->text();
    QString sex = ui->sex->currentText();
    if(account.size() == 0 || password.size() == 0 || schoolID.size() == 0)
        return 1;
    else
        return 0;
}

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_ok_clicked()
{
    if(ui->password->text() != ui->passwordaffirm->text()){
     QMessageBox::critical(this,tr("错误"),tr("两次密码不一样"),QMessageBox::Retry);
    }
    else{
    QString account = ui->account->text();
    QString password = ui->password->text();
    QString schoolID = ui->schoolID->text();
    QString department = ui->department->text();
    QString major = ui->major->text();
    QString name = ui->name->text();
    QString sex = ui->sex->currentText();
    if(CheckBlank()){
        QMessageBox::critical(this,tr("错误"),tr("必填信息未填完"),QMessageBox::Retry);
        return;
    }
    DataUser data(account,password,schoolID,
                  department, major, name, sex);
    emit Register(data);
    }
}

void RegisterDialog::on_pushButton_2_clicked()
{
    emit Destruction();
}
