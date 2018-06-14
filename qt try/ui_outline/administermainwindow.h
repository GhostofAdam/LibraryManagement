#ifndef ADMINISTERMAINWINDOW_H
#define ADMINISTERMAINWINDOW_H

#include <QWidget>
#include "bookstackedpage.h"

namespace Ui {
class AdministerMainWindow;
}

class AdministerMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdministerMainWindow(QWidget *parent = 0);
    ~AdministerMainWindow();

private:
    Ui::AdministerMainWindow *ui;
};

#endif // ADMINISTERMAINWINDOW_H
