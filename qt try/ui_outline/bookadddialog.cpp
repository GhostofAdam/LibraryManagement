#include "bookadddialog.h"
#include "ui_bookadddialog.h"

BookAddDialog::BookAddDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookAddDialog)
{
    ui->setupUi(this);
}

BookAddDialog::~BookAddDialog()
{
    delete ui;
}



void BookAddDialog::on_AddButton_clicked()
{
    QString title = ui->Title->text();
    QString author = ui->Author->text();
    QString isbn = ui->Isbn->text();
    QString summary = ui->Summary->text();
    QString label = ui->label->text();

    DataBook book(title,author,isbn,label,summary);
    emit AddBook(book);
}

void BookAddDialog::on_CancelButton_clicked()
{
    emit Cancel();
}
