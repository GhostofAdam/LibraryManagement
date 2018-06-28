#include "bookchangedialog.h"
#include "ui_bookchangedialog.h"

BookChangeDialog::BookChangeDialog(QWidget * parent,DataBook book) :
    QDialog(parent),
    ui(new Ui::BookChangeDialog)
{
    ui->setupUi(this);
    SetupBook(book);
}

BookChangeDialog::~BookChangeDialog()
{
    delete ui;
}

void BookChangeDialog::SetupBook(const DataBook & book)
{
    DataBookAdapter bookadpt(book);
    ui->Title->setText(bookadpt.title());
    ui->Author->setText(bookadpt.author());
    ui->Summary->setText(bookadpt.abstract());
    ui->Place->setText(bookadpt.place());
    ui->Isbn->setText(bookadpt.isbn());

    ui->Title_2->setText(bookadpt.title());
    ui->Author_2->setText(bookadpt.author());
    ui->Summary_2->setText(bookadpt.abstract());
    ui->Place_2->setText(bookadpt.place());
    ui->Isbn_2->setText(bookadpt.isbn());

    ui->Title->setReadOnly(true);
    ui->Author->setReadOnly(true);
    ui->Summary->setReadOnly(true);
    ui->Place->setReadOnly(true);
    ui->Isbn->setReadOnly(true);\

    this->id = bookadpt.id();
}

void BookChangeDialog::on_buttonBox_accepted()
{
    switch( QMessageBox::warning(NULL, "warning",QString::fromLocal8Bit("确定修改书籍吗?"),
                                 QMessageBox::Yes | QMessageBox::Default,
                                 QMessageBox::No | QMessageBox::Escape ))
    {
    case QMessageBox::Yes:{
        QString id = QString::number(this->id);
        QString author = ui->Author_2->text();
        QString title = ui->Title_2->text();
        QString place = ui->Place_2->text();
        QString isbn = ui->Isbn->text();
        QString summary = ui->Summary_2->text();
        DataBook newbook(title, author, place, isbn, summary);
        emit ChangeBook(id, newbook);
        }
        break;
    case QMessageBox::No:
        return;
        break;
    }
}
