#include "bookchangedialog.h"
#include "ui_bookchangedialog.h"

BookChangeDialog::BookChangeDialog(DataBook book,QWidget * parent) :
    QDialog(parent),book(book),
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

    //this->id = bookadpt.id();
}

void BookChangeDialog::on_buttonBox_accepted()
{
    switch( QMessageBox::warning(NULL, tr("warning"),tr("确定修改书籍吗?"),
                                 QMessageBox::Yes | QMessageBox::Default,
                                 QMessageBox::No | QMessageBox::Escape ))
    {
    case QMessageBox::Yes:{
        DataBook newbook = this->book;
        newbook.id = this->book.id;
        newbook.author = ui->Author_2->text();
        newbook.name = ui->Title_2->text();
        newbook.place = ui->Place_2->text();
        newbook.isbn = ui->Isbn_2->text();
        newbook.abstract = ui->Summary_2->text();
        qDebug()<< newbook.id;
        emit ChangeBook(newbook.id, newbook);
        this->close();
        }
        break;
    case QMessageBox::No:
        break;
    }
}
void BookChangeDialog::on_buttonBox_rejected(){
    this->close();
}
