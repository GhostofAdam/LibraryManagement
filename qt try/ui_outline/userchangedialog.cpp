#include "userchangedialog.h"
#include "ui_userchangedialog.h"

UserChangeDialog::UserChangeDialog(DataUser data,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserChangeDialog),user(data)
{
    ui->setupUi(this);
    DataUserAdapter a(&user);
    QString depart = a.Department();
    QString major = a.Major();
    QString sex = a.Sex();
    QString name = a.Name();
}

UserChangeDialog::~UserChangeDialog()
{
    delete ui;
}

void UserChangeDialog::on_buttonBox_accepted()
{
    DataUserAdapter a(user);

}

void UserChangeDialog::SetUp(){

}

void UserChangeDialog::SetUpSex(QString sex){

}
