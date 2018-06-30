#ifndef BOOKCHANGEDIALOG_H
#define BOOKCHANGEDIALOG_H

#include <QWidget>
#include <QMessageBox>

#include <databook.h>
#include "databook.h"
#include "databookadapter.h"
namespace Ui {
class BookChangeDialog;
}

class BookChangeDialog : public QDialog
{
    Q_OBJECT
public:
    BookChangeDialog() = delete;
    BookChangeDialog(DataBook book, QWidget * parent);
    ~BookChangeDialog();


signals:
    void ChangeBook(QString id, DataBook book);
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::BookChangeDialog *ui;
    DataBook book;
    void SetupBook(const DataBook & book);
};

#endif // BOOKCHANGEDIALOG_H
