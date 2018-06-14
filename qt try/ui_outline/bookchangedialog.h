#ifndef BOOKCHANGEDIALOG_H
#define BOOKCHANGEDIALOG_H

#include <QWidget>
#include <databook.h>
#include "databook.h"
#include "databookadapter.h"
namespace Ui {
class BookChangeDialog;
}

class BookChangeDialog : public QWidget
{
    Q_OBJECT
    QString id;
public:
    BookChangeDialog() = delete;
    BookChangeDialog(QWidget * parent,DataBook book);
    ~BookChangeDialog();


signals:
    void ChangeBook(QString id, DataBook book);
    void Cancel();
private slots:
    void on_ChangeButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::BookChangeDialog *ui;
    QString id;
    void SetupBook(const DataBook & book);
};

#endif // BOOKCHANGEDIALOG_H
