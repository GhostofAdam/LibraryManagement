#ifndef USERSTACKEDPAGE_H
#define USERSTACKEDPAGE_H

#include <QWidget>
#include "configure.h"
#include "datauser.h"
namespace Ui {
class UserStackedPage;
}

class UserStackedPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserStackedPage(QWidget *parent = 0);
    ~UserStackedPage();
    void SetUserTable(QVector<DataUser*>);
    void ClearTable();
signals:
    void SearchUser(QString search_info, QString search_type);
    void NukeUser(QString account);
    void ClearFineofUser(QString account);
    void ChangeInfoofUser(QString account);

private slots:
    void on_DeleteButton_clicked();
    void on_ClearFineButton_clicked();
    void on_ChangeInfoButton_clicked();
    void on_SearchButton_clicked();

private:
    Ui::UserStackedPage *ui;
};

#endif // USERSTACKEDPAGE_H
