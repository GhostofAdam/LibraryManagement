#include "logindialog.h"
#include "ui_logindialog.h"
#include "libman.h"
#include "db.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
//    connect(this,SIGNAL(LoginSignals(QString, QString)),
//          this,SLOT(debug(QString, QString)));
}

LoginDialog::~LoginDialog()
{
    emit LoginDestruction();
    delete ui;
}

void LoginDialog::on_LoginButton_clicked()
{
    QString account = ui->AccountEdit->text();
    QString password = ui->PasswordEdit->text();
//    this->ShowRefutation();
    emit LoginSignals(account, password);
}

void LoginDialog::on_RegisterButton_clicked()
{
    Register* registr = new Register();
    registr ->exec();
}

void LoginDialog::OpenMainWindowofStudent(){

    MainWindow * mainwnd = new MainWindow(nullptr,USER_NUM);
    mainwnd -> show();
    this->~LoginDialog();
}

void LoginDialog::OpenMainWindowofAdministrator(){

    MainWindow * mainwnd = new MainWindow(nullptr,USER_NUM);
    mainwnd -> show();
    this->close();
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
// void LoginDialog::debug(QString accnount, QString password){
//      DB test("F:\\sqlite\\admitDB.db");
//      int flag=test.EnterCheck(accnount,password);

//      if(flag==0){
//         this->OpenMainWindowofStudent();
//      }
//      else if(flag==1){
//          this->ShowNoQuestRefutation();
//      }
//      else{
//          this->ShowUnmatchRefutation();
//      }
// }
