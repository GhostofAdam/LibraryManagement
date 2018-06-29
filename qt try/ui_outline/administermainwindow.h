#ifndef ADMINISTERMAINWINDOW_H
#define ADMINISTERMAINWINDOW_H

#include <QWidget>
#include "configure.h"
#include "bookstackedpage.h"
#include "loanstackedpage.h"
#include "userstackedpage.h"
#include "infostackedpage.h"
#include "datauseradapter.h"
namespace Ui {
class AdministerMainWindow;
}

class AdministerMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdministerMainWindow(DataUser user, QWidget *parent = 0);
    explicit AdministerMainWindow(QWidget *parent = 0);//暂时这样做
    ~AdministerMainWindow();


//    void SetBookTable(QVector<DataBook> books){
//        bookpage -> SetBookTable(books);
//    }
    BookStackedPage* BPage(){
        return bookpage;
    }
    LoanStackedPage* LPage(){
        return loanpage;
    }
    InfoStackedPage* IPage(){
        return infopage;
    }
    UserStackedPage* UPage(){
        return userpage;
    }
    QString Account(){
        DataUserAdapter a(&user);
        return a.Account();
    }

private:
    DataUser user;
    Ui::AdministerMainWindow *ui;
    BookStackedPage * bookpage;
    LoanStackedPage * loanpage;
    InfoStackedPage * infopage;
    UserStackedPage * userpage;

    //signals:
    //    void SearchBook(QString search_info, QString search_type);
    //    void ChangeBookById(QString id);
    //    void InsertBook();
    //    void ChangePassword(QString password);
    //    void SearchLoan(QString search_info, QString search_type);
    //    void ExtendLoan(QString id);
    //    void FinishLoan(QString id);

    //public slots:
    //    void on_SearchBook(QString search_info, QString search_type){
    //        emit SearchBook(search_info, search_type);
    //    }
    //    void on_ChangeBookById(QString isbn){
    //        emit ChangeBookById(isbn);
    //    }
    //    void on_InsertBook(){
    //        emit InsertBook();
    //    }
    //    void on_ChangePassword(QString newpssw){
    //        emit ChangePassword(newpssw);
    //    }
    //    void on_SearchLoan(QString search_info, QString search_type){
    //        emit SearchLoan(search_info, search_type);
    //    }
    //    void on_ExtendLoan(QString id){
    //        emit ExtendLoan(id);
    //    }//或许不需要这样麻烦的方式,信号和槽直接连接起来就行

};

#endif // ADMINISTERMAINWINDOW_H
