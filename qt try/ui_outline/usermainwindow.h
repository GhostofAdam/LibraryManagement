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
    ~UserMainWindow();

signals:
    void SearchBook(QString search_info, QString search_type);
private slots:

private:
    Ui::UserMainWindow *ui;
};

#endif // USERMAINWINDOW_H
