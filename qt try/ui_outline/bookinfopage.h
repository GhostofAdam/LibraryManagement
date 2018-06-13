#ifndef BOOKINFOPAGE_H
#define BOOKINFOPAGE_H

#include <QWidget>

namespace Ui {
class BookInfoPage;
}

class BookInfoPage : public QWidget
{
    Q_OBJECT

public:
    explicit BookInfoPage(QWidget *parent = 0);
    ~BookInfoPage();

private slots:

private:
    Ui::BookInfoPage *ui;
};

#endif // BOOKINFOPAGE_H
