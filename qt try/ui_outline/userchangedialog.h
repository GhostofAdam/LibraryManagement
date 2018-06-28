#ifndef USERCHANGEDIALOG_H
#define USERCHANGEDIALOG_H

#include <QDialog>
#include "configure.h"
#include "datauser.h"
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
    void ChangeUser(DataUser);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::UserChangeDialog *ui;
    DataUser user;
};

#endif // USERCHANGEDIALOG_H
