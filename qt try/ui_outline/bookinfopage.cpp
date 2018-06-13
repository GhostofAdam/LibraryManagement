#include "bookinfopage.h"
#include "ui_bookinfopage.h"

BookInfoPage::BookInfoPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookInfoPage)
{
    ui->setupUi(this);
}

BookInfoPage::~BookInfoPage()
{
    delete ui;
}
