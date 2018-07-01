#ifndef USERCHANGEDIALOG_H
#define USERCHANGEDIALOG_H

#include <QDialog>
#include "configure.h"
#include "datauser.h"
#include "datauseradapter.h"
namespace Ui {
class UserChangeDialog;
}

class UserChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserChangeDialog(DataUser data,QWidget *parent = 0);
    ~UserChangeDialog();
signals:
    void ChangeUser(DataUser newinfo);
private slots:
    void on_buttonBox_accepted();

private:
    void SetUp();
    void SetUpSex();
    Ui::UserChangeDialog *ui;
    DataUser user;
};

#endif // USERCHANGEDIALOG_H
