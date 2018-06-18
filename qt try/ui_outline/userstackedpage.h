#ifndef USERSTACKEDPAGE_H
#define USERSTACKEDPAGE_H

#include <QWidget>

namespace Ui {
class UserStackedPage;
}

class UserStackedPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserStackedPage(QWidget *parent = 0);
    ~UserStackedPage();

private:
    Ui::UserStackedPage *ui;
};

#endif // USERSTACKEDPAGE_H
