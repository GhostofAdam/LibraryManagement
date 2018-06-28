#include "userchangedialog.h"
#include "ui_userchangedialog.h"

UserChangeDialog::UserChangeDialog(DataUser data,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserChangeDialog),user(data)
{
    ui->setupUi(this);
}

UserChangeDialog::~UserChangeDialog()
{
    delete ui;
}

void UserChangeDialog::on_buttonBox_accepted()
{

}
