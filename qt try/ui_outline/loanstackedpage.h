#ifndef LOANSTACKEDPAGE_H
#define LOANSTACKEDPAGE_H

#include <QWidget>

namespace Ui {
class LoanStackedPage;
}

class LoanStackedPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoanStackedPage(QWidget *parent = 0);
    ~LoanStackedPage();

private:
    Ui::LoanStackedPage *ui;
};

#endif // LOANSTACKEDPAGE_H
