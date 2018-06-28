#ifndef USERMAINWINDOW_H
#define USERMAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QListWidget>
#include <QStackedWidget>
#include <QMessageBox>
#include <QLabel>

#include "configure.h"
#include "bookstackedpage.h"
#include "loanstackedpage.h"
#include "userstackedpage.h"
#include "infostackedpage.h"
namespace Ui {
class UserMainWindow;
}

class UserMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMainWindow(QWidget *parent = 0);
    void SetBookTable(QVector<DataBook> books){
        bookpage->SetBookTable(books);
    }

    ~UserMainWindow();
    BookStackedPage* BPage(){
        return bookpage;
    }
    LoanStackedPage* LPage(){
        return loanpage;
    }
    InfoStackedPage* IPage(){
        return infopage;
    }
private:
    Ui::UserMainWindow *ui;
    BookStackedPage * bookpage;
    LoanStackedPage * loanpage;
    InfoStackedPage * infopage;

    //signals:
    //    void SearchBook(QString search_info, QString search_type);
    //    void ViewBookByIsbn(QString isbn);
    //public slots:
    //    void on_SearchBook(QString search_info, QString search_type){
    //        emit SearchBook(search_info, search_type);
    //    }
    //    void on_ViewBookByIsbn(QString isbn){
    //        emit ViewBookByIsbn(isbn);
    //    }

};

#endif // USERMAINWINDOW_H
