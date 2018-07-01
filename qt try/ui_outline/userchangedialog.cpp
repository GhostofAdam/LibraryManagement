#include "userchangedialog.h"
#include "ui_userchangedialog.h"

UserChangeDialog::UserChangeDialog(DataUser u,QWidget *parent) :
    QDialog(parent),user(u),
    ui(new Ui::UserChangeDialog)
{
    ui->setupUi(this);
    SetUp();
    SetUpSex();
}

UserChangeDialog::~UserChangeDialog()
{
    delete ui;
}

void UserChangeDialog::on_buttonBox_accepted()
{
    DataUser changeduser = user;
    changeduser.name = ui->name->text();
    changeduser.department=ui->department->text();
    changeduser.major=ui->major->text();
    changeduser.sex=ui->sex->currentText();
    emit ChangeUser(changeduser);

}

void UserChangeDialog::SetUp(){
    ui->name->setText(user.name);
    ui->department->setText(user.department);
    ui->major->setText(user.major);
}

void UserChangeDialog::SetUpSex(){
   if(user.sex == "男" || user.sex =="女")
    ui->sex->setCurrentText(user.sex);
   else
    ui->sex->setCurrentText("未知");
}
