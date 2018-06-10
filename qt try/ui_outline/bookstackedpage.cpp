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

void BookStackedPage::on_SearchButton_clicked()
{
    emit SearchBook(ui->textEdit->toPlainText(),ui->TypeBox->currentText());
}

void BookStackedPage::on_ViewButton_clicked()
{
    int selectrow = ui->ViewTable->currentRow();
    emit SelectBookIsbn(ui->ViewTable->item(ISBNCOLUMN,selectrow)->text());
}

#undef TABLE
