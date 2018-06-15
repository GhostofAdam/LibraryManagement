#include "usermainwindow.h"
#include "ui_usermainwindow.h"
#include <QMessageBox>

UserMainWindow::UserMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMainWindow)
{
    ui->setupUi(this);
    bookpage = new BookStackedPage(this);
    bookpage->Adapt2User();
    ui->PageStack->removeWidget(ui->BookPage);
    ui->PageStack->addWidget(bookpage);

    connect(ui->SelectList,SIGNAL(currentRowChanged(int)),ui->PageStack,SLOT(setCurrentIndex(int)));
}

UserMainWindow::~UserMainWindow()
{
    delete ui;
}
