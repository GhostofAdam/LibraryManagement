#include "loanstackedpage.h"
#include "ui_loanstackedpage.h"

LoanStackedPage::LoanStackedPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoanStackedPage)
{
    ui->setupUi(this);
}

LoanStackedPage::~LoanStackedPage()
{
    delete ui;
}
