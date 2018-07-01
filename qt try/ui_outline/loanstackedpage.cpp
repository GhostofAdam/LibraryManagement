#include "loanstackedpage.h"
#include "ui_loanstackedpage.h"
#define IDCOLUMN 4
#define CONDITIONCOLUMN 5
#define TABLE ui->LoanTable
LoanStackedPage::LoanStackedPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoanStackedPage)
{
    ui->setupUi(this);
    ui->LoanTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LoanTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LoanTable->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->ReserveButton->hide();
}

LoanStackedPage::~LoanStackedPage()
{
    delete ui;
}

void LoanStackedPage::SetLoanTable(QVector<DataRecord*> records)
{
    ClearTable();

    int row = records.size();
    for(int i = 0; i < row; i ++){
        DataRecord* tmp = records[i];
        int Rowcount = TABLE->rowCount();
        TABLE->insertRow(Rowcount);
        TABLE->setItem(i,0,new QTableWidgetItem(tmp->readerID));
        TABLE->setItem(i,1,new QTableWidgetItem(tmp->bookID));
        TABLE->setItem(i,2,new QTableWidgetItem(tmp->begintime));
        TABLE->setItem(i,3,new QTableWidgetItem(tmp->endtime));
        TABLE->setItem(i,4,new QTableWidgetItem(tmp->recordID));
        TABLE->setItem(i,5,new QTableWidgetItem(tmp->condition));
    }

}

void LoanStackedPage::ClearTable()
{
    TABLE->setRowCount(0);
    TABLE->clearContents();
}

void LoanStackedPage::Adapt2User()
{
    ui->FinishButton->hide();
    ui->ReserveButton->hide();
    ui->Search->hide();
    ui->SearchEdit->hide();
    ui->label->hide();
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
    int selectrow = TABLE->currentRow();
    if(selectrow < 0){
        QMessageBox::StandardButton reply = QMessageBox::critical(this, tr("错误"),tr("错误"),QMessageBox::Retry);
        return;
    }
    QString condit = TABLE->item(selectrow,CONDITIONCOLUMN)->text();
    if(condit != "borrowed"){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::critical(this, tr("本条记录无法被归还"),tr("本条记录无法被归还"),QMessageBox::Retry);
        return;
    }
    emit FinishLoan(TABLE->item(selectrow,IDCOLUMN)->text());
}

void LoanStackedPage::on_ProlongButton_clicked()
{
    int selectrow = TABLE->currentRow();
    if(selectrow < 0){
        QMessageBox::StandardButton reply = QMessageBox::critical(this, tr("错误"),tr("错误"),QMessageBox::Retry);
        return;
    }
    QString condit = TABLE->item(selectrow,CONDITIONCOLUMN)->text();
    if(condit != "borrowed"){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::critical(this, tr("本条记录无法被延长"),tr("本条记录无法被延长"),QMessageBox::Retry);
        return;
    }
    emit ExtendLoan(TABLE->item(selectrow,IDCOLUMN)->text());
}

void LoanStackedPage::on_ReserveButton_clicked()
{
    int selectrow = TABLE->currentRow();
    if(selectrow < 0){
        QMessageBox::StandardButton reply = QMessageBox::critical(this, tr("错误"),tr("错误"),QMessageBox::Retry);
        return;
    }
    QString condit = TABLE->item(selectrow,CONDITIONCOLUMN)->text();
    if(condit != "subscribed"){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::critical(this, tr("本条记录已经借阅成功"),tr("本条记录已经借阅成功"),QMessageBox::Retry);
        return;
    }
    emit AcceptReserveLoan(TABLE->item(selectrow,IDCOLUMN)->text());
}

#undef IDCOLUMN
#undef CONDITIONCOLUMN
#undef TABLE
