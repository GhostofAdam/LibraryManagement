#include "registerdialog.h"
#include "ui_registerdialog.h"

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

    DataUser data(account,password,schoolID,
                  department, major, name, sex);
    emit Register(data);
    }
}

void RegisterDialog::on_pushButton_2_clicked()
{
    emit Destruction();
}
