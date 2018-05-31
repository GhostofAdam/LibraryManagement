#include "registerdialog.h"
#include "ui_registerdialog.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QString account = ui->account->text();
    QString password = ui->password->text();
    QString schoolID = ui->schoolID->text();
    QString department = ui->department->text();
    QString major = ui->major->text();
    QString name = ui->name->text();
    QString sex = ui->sex->currentText();

    DataUser data(account,password,schoolID
                  department, major, name, sex);
    emit Register(data);
}
