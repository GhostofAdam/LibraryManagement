#ifndef BOOKFROMUSERPAGE_H
#define BOOKFROMUSERPAGE_H

#include <QWidget>

namespace Ui {
class BookFromUserPage;
}

class BookFromUserPage : public QWidget
{
    Q_OBJECT

public:
    explicit BookFromUserPage(QWidget *parent = 0);
    ~BookFromUserPage();

private:
    Ui::BookFromUserPage *ui;
};

#endif // BOOKFROMUSERPAGE_H
