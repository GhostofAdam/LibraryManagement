#ifndef BOOKFROMUSERPAGE_H
#define BOOKFROMUSERPAGE_H

#include <QWidget>
#include "configure.h"
#include "databook.h"
#include "databookadapter.h"
namespace Ui {
class BookFromUserPage;
}

class BookFromUserPage : public QDialog
{
    Q_OBJECT
private:
    DataBook book;
public:
    explicit BookFromUserPage(DataBook book, QWidget *parent = 0);
    ~BookFromUserPage();
    void SetUp();
    void SetUpPlaces(QVector<QString> places);
signals:
    void Appoint(QString isbn);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::BookFromUserPage *ui;
};

#endif // BOOKFROMUSERPAGE_H
