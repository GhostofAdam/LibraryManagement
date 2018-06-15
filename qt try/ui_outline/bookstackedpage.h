#ifndef BOOKSTACKEDPAGE_H
#define BOOKSTACKEDPAGE_H

#include <QWidget>
#include <QMainWindow>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QString>

#include "databookadapter.h"
#include "databook.h"


namespace Ui {
class BookStackedPage;
}

class BookStackedPage : public QWidget
{
    Q_OBJECT

public:
    explicit BookStackedPage(QWidget *parent = 0);
    ~BookStackedPage();
    void SetBookTable(QVector<DataBook>);
    void Adapt2User();

signals:
    void SearchBook(QString search_info, QString search_type);
    void SelectBookIsbn(QString isbn);
private slots:
    void on_SearchButton_clicked();
    void on_ViewButton_clicked();

private:
    Ui::BookStackedPage *ui;
};

#endif // BOOKSTACKEDPAGE_H
