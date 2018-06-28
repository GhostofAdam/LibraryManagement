#ifndef INFOSTACKEDPAGE_H
#define INFOSTACKEDPAGE_H

#include <QWidget>

namespace Ui {
class InfoStackedPage;
}

class InfoStackedPage : public QWidget
{
    Q_OBJECT

public:
    explicit InfoStackedPage(QWidget *parent = 0);
    ~InfoStackedPage();

signals:
    void ChangePassword(QString password);
private:
    Ui::InfoStackedPage *ui;
};

#endif // INFOSTACKEDPAGE_H
