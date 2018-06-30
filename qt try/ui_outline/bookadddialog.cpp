#include "bookadddialog.h"
#include "ui_bookadddialog.h"

BookAddDialog::BookAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookAddDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("确定");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("取消");
}

BookAddDialog::~BookAddDialog()
{
    delete ui;
}

void BookAddDialog::on_buttonBox_accepted()
{
    QString title = ui->Title->text();
    QString author = ui->Author->text();
    QString isbn = ui->Isbn->text();
    QString summary = ui->Summary->text();
    QString label = ui->label->text();

    DataBook book("0",title,author,isbn,label,summary);

    emit InsertBook(book);
}

