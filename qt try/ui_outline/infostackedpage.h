#ifndef INFOSTACKEDPAGE_H
#define INFOSTACKEDPAGE_H

#include <QWidget>
#include "configure.h"
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
    void ChangePassword(QString oldpassword,QString newpassword);
private slots:
    void on_pushButton_clicked();

private:
    Ui::InfoStackedPage *ui;
};

#endif // INFOSTACKEDPAGE_H
