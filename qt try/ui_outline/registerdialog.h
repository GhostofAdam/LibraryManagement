#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();

signals:
    void Register();
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::RegisterDialog *ui;


};

#endif // REGISTER_H
