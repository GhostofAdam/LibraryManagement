#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include "configure.h"
#include "logindialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0, int = 0);//int indicates who uses it,0: administrator; 1:user
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QListWidget* leftlist;
    QStackedWidget * stack;
};

#endif // MAINWINDOW_H
