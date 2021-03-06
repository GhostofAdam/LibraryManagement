#include "bookstackedpage.h"
#include "ui_bookstackedpage.h"
#define TABLE ui->ViewTable
#define IDCOLUMN 4
BookStackedPage::BookStackedPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookStackedPage)
{
    ui->setupUi(this);
    ui->ViewTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ViewTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ViewTable->setSelectionMode(QAbstractItemView::SingleSelection);
}

BookStackedPage::~BookStackedPage()
{
    delete ui;
}

void BookStackedPage::SetBookTable(QVector<DataBook *> book)
{
    ui->ViewTable->setRowCount(0);
    ui->ViewTable->clearContents();

    int row = book.size();
    //TODO check i = 0?
    for(int i = 0; i < row; i ++){
        DataBookAdapter tmp(*book[i]);
        qDebug()<<tmp.title();
        int Rowcount = ui->ViewTable->rowCount();
        ui->ViewTable->insertRow(Rowcount);
        ui->ViewTable->setItem(i, 0, new QTableWidgetItem(tmp.title()));
        ui->ViewTable->setItem(i, 1, new QTableWidgetItem(tmp.author()));
        ui->ViewTable->setItem(i, 2, new QTableWidgetItem(tmp.place()));
        ui->ViewTable->setItem(i, 3, new QTableWidgetItem(tmp.isbn()));
         ui->ViewTable->setItem(i, 4, new QTableWidgetItem(tmp.id()));
    }
}

void BookStackedPage::on_SearchButton_clicked()
{
    emit SearchBook(ui->textEdit->toPlainText(),ui->TypeBox->currentText());
}

void BookStackedPage::on_ViewButton_clicked()
{
    int selectrow = ui->ViewTable->currentRow();
    emit SelectBookId(ui->ViewTable->item(selectrow,IDCOLUMN)->text());
}

void BookStackedPage::Adapt2User(){
    ui->ChangeButton->hide();
    ui->InsertButton->hide();
}

void BookStackedPage::Adapt2Administer(){
    ui->ViewButton->hide();
}


void BookStackedPage::on_InsertButton_clicked()
{
    emit InsertBook();
}

void BookStackedPage::on_ChangeButton_clicked()
{
     int selectrow = ui->ViewTable->currentRow();
     emit ChangeBook(ui->ViewTable->item(selectrow,IDCOLUMN)->text());
}

void BookStackedPage::ClearTable(){
    ui->ViewTable->setRowCount(0);
    ui->ViewTable->clearContents();
}

#undef TABLE
#undef IDCOLUMN
