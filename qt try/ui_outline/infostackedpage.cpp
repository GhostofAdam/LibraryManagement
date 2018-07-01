#include "infostackedpage.h"
#include "ui_infostackedpage.h"

InfoStackedPage::InfoStackedPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoStackedPage)
{
    ui->setupUi(this);
}

InfoStackedPage::~InfoStackedPage()
{
    delete ui;
}
void InfoStackedPage::on_pushButton_clicked()
{
    if(ui->NewPassword->text() != ui->NewPassword2->text()){
         QMessageBox::critical(this,tr("错误"),tr("两次密码不一样"),QMessageBox::Retry);
        return;
    }
    emit ChangePassword(ui->OldPassword->text(),ui->NewPassword->text());
}
