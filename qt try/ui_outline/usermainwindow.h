#ifndef USERMAINWINDOW_H
#define USERMAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>

#include "bookstackedpage.h"

namespace Ui {
class UserMainWindow;
}

class UserMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    BookStackedPage * bookpage;

public:
    explicit UserMainWindow(QWidget *parent = 0);
    void SetBookTable(QVector<DataBook> books){
        bookpage->SetBookTable(books);
    }

    ~UserMainWindow();

signals:
    void SearchBook(QString search_info, QString search_type);
    void SelectBookIsbn(QString isbn);
private slots:
    void on_SearchBook(QString search_info, QString search_type){
        emit SearchBook(search_info, search_type);
    }
    void on_SelectBookIsbn(QString isbn){
        emit SelectBookIsbn(isbn);
    }

private:
    Ui::UserMainWindow *ui;
};

#endif // USERMAINWINDOW_H
