#ifndef BOOKADDDIALOG_H
#define BOOKADDDIALOG_H

#include <QDialog>
#include "configure.h"

#include "databook.h"
namespace Ui {
class BookAddDialog;
}

class BookAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookAddDialog(QWidget *parent = 0);
    ~BookAddDialog();

signals:
    void InsertBook(DataBook book);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::BookAddDialog *ui;
};

#endif // BOOKADDDIALOG_H
