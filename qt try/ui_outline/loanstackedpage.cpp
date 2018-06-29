#include "loanstackedpage.h"
#include "ui_loanstackedpage.h"

LoanStackedPage::LoanStackedPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoanStackedPage)
{
    ui->setupUi(this);
    ui->LoanTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LoanTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LoanTable->setSelectionMode(QAbstractItemView::SingleSelection);
}

LoanStackedPage::~LoanStackedPage()
{
    delete ui;
}

void LoanStackedPage::Adapt2User()
{
    ui->FinishButton->hide();
}

void LoanStackedPage::Adapt2Administer()
{

}

void LoanStackedPage::on_SearchButton_clicked()
{
    QString key = ui->SearchEdit->text();
    QString type = ui->Search->currentText();
    emit SearchLoan(key, type);
}

void LoanStackedPage::on_FinishButton_clicked()
{
    QString id ="bug";//TODO 弄清楚表
}

void LoanStackedPage::on_ProlongButton_clicked()
{

}

void SetLoanTable(QVector<DataRecord> records){
}
