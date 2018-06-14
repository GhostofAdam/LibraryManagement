#ifndef BOOKADDDIALOG_H
#define BOOKADDDIALOG_H

#include <QWidget>
#include <databook.h>
//添加书的时候有很大的问题

namespace Ui {
class BookAddDialog;
}

class BookAddDialog : public QWidget
{
    Q_OBJECT

public:
    explicit BookAddDialog(QWidget *parent = 0);
    ~BookAddDialog();

signals:
    void Cancel();
    void AddBook(DataBook book);
private slots:
    void on_AddButton_clicked();
    void on_CancelButton_clicked();

private:
    Ui::BookAddDialog *ui;
};

#endif // BOOKADDDIALOG_H
