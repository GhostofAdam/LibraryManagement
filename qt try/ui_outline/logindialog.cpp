#include "logindialog.h"
#include "ui_logindialog.h"
#include "db.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_LoginButton_clicked()
{

    QString account = ui->AccountEdit->text();
    QString password = ui->PasswordEdit->text();
    QString type = ui->Type->currentText();
    if(account.size() == 0 || password.size() == 0){
        //账号或密码为空
        ShowBlankRefutation();
        return;
    }
    qDebug() << type;
    emit LoginSignals(account, password, type);
}

void LoginDialog::on_RegisterButton_clicked()
{
    emit OpenRegisterSignals();
}

void LoginDialog::ShowUnmatchRefutation(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, tr("密码错误"),tr("密码错误，请重新尝试"),QMessageBox::Retry);
}

void LoginDialog::ShowBlankRefutation(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, tr("账号或密码不能为空"),tr("账号或密码不能为空，请重新输入账号密码"),QMessageBox::Retry);
}

void LoginDialog::ShowNoQuestRefutation(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, tr("账号不存在"),tr("账号不存在，请重新输入账号"),QMessageBox::Retry);
}

void LoginDialog::on_CancelButton_clicked(){
    this->close();
}
