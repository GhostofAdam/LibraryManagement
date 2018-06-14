#include "administermainwindow.h"
#include "ui_administermainwindow.h"

AdministerMainWindow::AdministerMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdministerMainWindow)
{
    ui->setupUi(this);
    bookpage = new BookStackedPage(this);
    ui->PageStack->removeWidget(ui->BookPage);
    ui->PageStack->addWidget(bookpage);

    connect(ui->SelectList,SIGNAL(currentRowChanged(int)),ui->PageStack,SLOT(setCurrentIndex(int)));
}

AdministerMainWindow::~AdministerMainWindow()
{
    delete ui;
}
