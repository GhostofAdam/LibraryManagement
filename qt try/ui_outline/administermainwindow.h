#ifndef ADMINISTERMAINWINDOW_H
#define ADMINISTERMAINWINDOW_H

#include <QWidget>
#include "configure.h"
#include "bookstackedpage.h"

namespace Ui {
class AdministerMainWindow;
}

class AdministerMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdministerMainWindow(QWidget *parent = 0);
    ~AdministerMainWindow();
    void SetBookTable(QVector<DataBook> books){
        bookpage -> SetBookTable(books);
    }
signals:
    void SearchBook(QString search_info, QString search_type);
    void ChangeBookById(QString id);
    void InsertBook();
public slots:
    void on_SearchBook(QString search_info, QString search_type){
        emit SearchBook(search_info, search_type);
    }
    void on_ChangeBookById(QString isbn){
        emit ChangeBookById(isbn);
    }
    void on_InsertBook(){
        emit InsertBook();
    }

private:
    Ui::AdministerMainWindow *ui;
    BookStackedPage * bookpage;
};

#endif // ADMINISTERMAINWINDOW_H
