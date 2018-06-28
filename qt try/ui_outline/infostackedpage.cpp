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

}
