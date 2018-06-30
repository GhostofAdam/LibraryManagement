#include "bookfromuserpage.h"
#include "ui_bookfromuserpage.h"

BookFromUserPage::BookFromUserPage(DataBook book, QWidget *parent) :
    QDialog(parent),book(book),
    ui(new Ui::BookFromUserPage)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("预约");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("取消");
    SetUp();
}

BookFromUserPage::~BookFromUserPage()
{
    delete ui;
}

//void BookFromUserPage::on_AppointButton_clicked()
//{
//    DataBookAdapter a(book);
//    QString id = a.id();
//    emit Appoint(id);
//}

void BookFromUserPage::SetUp(){
    DataBookAdapter a(book);

    ui->Author->setText(a.author());
    ui->Isbn->setText(a.isbn());
    ui->Title->setText(a.title());
    ui->Summary->setText(a.abstract());

    ui->Author->setReadOnly(true);
    ui->Isbn->setReadOnly(true);
    ui->Title->setReadOnly(true);
    ui->Summary->setReadOnly(true);
}
void BookFromUserPage::SetUpPlaces(QVector<QString> places){
    for(auto place : places){
        QListWidgetItem *item = new QListWidgetItem(ui->PlaceList);
        item->setText(place);
        ui->PlaceList->addItem(item);
    }
}

void BookFromUserPage::on_buttonBox_accepted()
{
    DataBookAdapter a(book);
    emit Appoint(a.id());
    close();
}

void BookFromUserPage::on_buttonBox_rejected()
{
    close();
}
