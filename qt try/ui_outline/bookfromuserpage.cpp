#include "bookfromuserpage.h"
#include "ui_bookfromuserpage.h"

BookFromUserPage::BookFromUserPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookFromUserPage)
{
    ui->setupUi(this);
}

BookFromUserPage::~BookFromUserPage()
{
    delete ui;
}
