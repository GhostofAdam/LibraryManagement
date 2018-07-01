#include "userstackedpage.h"
#include "ui_userstackedpage.h"
#define TABLE ui->tableWidget
#define ACCOUNTCOLUMN 0
UserStackedPage::UserStackedPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserStackedPage)
{
    ui->setupUi(this);
    TABLE->setEditTriggers(QAbstractItemView::NoEditTriggers);;
    TABLE->setSelectionBehavior(QAbstractItemView::SelectRows);
    TABLE->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->DeleteButton->hide();
}

UserStackedPage::~UserStackedPage()
{
    delete ui;
}

void UserStackedPage::SetUserTable(QVector<DataUser*>users)
{
    ClearTable();
    int row = users.size();
    //TODO check i = 0?
    for(int i = 0; i < row; i ++){
        DataUser* user = users[i];
        int Rowcount = TABLE->rowCount();
        TABLE->insertRow(Rowcount);
        TABLE->setItem(i, 0, new QTableWidgetItem(user->account));
        TABLE->setItem(i, 1, new QTableWidgetItem(QString::number(user->finemoney)));
        TABLE->setItem(i, 2, new QTableWidgetItem(user->permission));
        TABLE->setItem(i, 3, new QTableWidgetItem(user->schoolID));
        TABLE->setItem(i, 4, new QTableWidgetItem(user->name));
        TABLE->setItem(i, 5, new QTableWidgetItem(user->department));
        TABLE->setItem(i, 6, new QTableWidgetItem(user->major));
        TABLE->setItem(i, 7, new QTableWidgetItem(user->sex));
    }

}

void UserStackedPage::ClearTable()
{
    TABLE->setRowCount(0);
    TABLE->clearContents();
}

void UserStackedPage::on_DeleteButton_clicked()
{
    int selectrow = TABLE->currentRow();
    if(selectrow < 0){
        QMessageBox::StandardButton reply = QMessageBox::critical(this, tr("错误"),tr("错误"),QMessageBox::Retry);
        return;
    }
    if(selectrow >= 0)
    emit NukeUser(TABLE->item(selectrow,ACCOUNTCOLUMN)->text());
}

void UserStackedPage::on_ClearFineButton_clicked()
{
    int selectrow = TABLE->currentRow();
    if(selectrow < 0){
        QMessageBox::StandardButton reply = QMessageBox::critical(this, tr("错误"),tr("错误"),QMessageBox::Retry);
        return;
    }
    if(selectrow >= 0)
    emit ClearFineofUser(TABLE->item(selectrow,ACCOUNTCOLUMN)->text());
}

void UserStackedPage::on_ChangeInfoButton_clicked()
{
    int selectrow = TABLE->currentRow();
    if(selectrow < 0){
        QMessageBox::StandardButton reply = QMessageBox::critical(this, tr("错误"),tr("错误"),QMessageBox::Retry);
        return;
    }
    if(selectrow >= 0)
    emit ChangeInfoofUser(TABLE->item(selectrow,ACCOUNTCOLUMN)->text());
}

void UserStackedPage::on_SearchButton_clicked()
{
    emit SearchUser(ui->Search->text(),ui->SearchType->currentText());
}

#undef TABLE
#undef ACCOUNTCOLUMN
