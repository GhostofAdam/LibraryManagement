#include "bookstackedpage.h"
#include "ui_bookstackedpage.h"
#define TABLE ui->ViewTable
#define ISBNCOLUMN 4
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

void BookStackedPage::SetBookTable(QVector<DataBook> book)
{
    ui->ViewTable->clearContents();

    int row = book.size();
    //TODO check i = 0?
    for(int i = 0; i < row; i ++){
        DataBookAdapter tmp(book[i]);
        ui->ViewTable->setItem(i, 0, new QTableWidgetItem(tmp.title()));
        ui->ViewTable->setItem(i, 1, new QTableWidgetItem(tmp.author()));
        ui->ViewTable->setItem(i, 2, new QTableWidgetItem(tmp.place()));
        ui->ViewTable->setItem(i, 3, new QTableWidgetItem(tmp.isbn()));
    }
}

void BookStackedPage::on_SearchButton_clicked()
{
    emit SearchBook(ui->textEdit->toPlainText(),ui->TypeBox->currentText());
}

void BookStackedPage::on_ViewButton_clicked()
{
    int selectrow = ui->ViewTable->currentRow();
    qDebug() << selectrow;
    if(selectrow >= 0)
    emit SelectBookIsbn(ui->ViewTable->item(ISBNCOLUMN,selectrow)->text());
}

void BookStackedPage::Adapt2User(){
    ui->ChangeButton->hide();
    ui->InsertButton->hide();
}

void BookStackedPage::Adapt2Administer(){
    ui->ViewButton->hide();
}

#undef TABLE

void BookStackedPage::on_InsertButton_clicked()
{
    emit InsertBook();
}

void BookStackedPage::on_ChangeButton_clicked()
{
     int selectrow = ui->ViewTable->currentRow();
    emit ChangeBook(ui->ViewTable->item(IDCOLUMN,selectrow)->text());
}
