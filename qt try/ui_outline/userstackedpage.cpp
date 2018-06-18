#include "userstackedpage.h"
#include "ui_userstackedpage.h"

UserStackedPage::UserStackedPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserStackedPage)
{
    ui->setupUi(this);
}

UserStackedPage::~UserStackedPage()
{
    delete ui;
}

void UserStackedPage::on_DeleteButton_clicked()
{

}

void UserStackedPage::on_ClearFineButton_clicked()
{

}

void UserStackedPage::on_ChangeInfoButton_clicked()
{

}

void UserStackedPage::on_SearchButton_clicked()
{

}
