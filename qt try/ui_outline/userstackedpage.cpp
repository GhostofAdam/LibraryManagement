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
