#include "usermainwindow.h"
#include "ui_usermainwindow.h"
#include <QMessageBox>

UserMainWindow::UserMainWindow(DataUser user_,QWidget *parent) :
    AdministerMainWindow(user_)
//  , ui(new Ui::UserMainWindow)
{
//    ui->setupUi(this);
//    bookpage = new BookStackedPage(this);
//    loanpage = new LoanStackedPage(this);
//    infopage = new InfoStackedPage(this);
    AdministerMainWindow::Adapt2User();
//    ui->PageStack->removeWidget(ui->BookPage);

//    ui->PageStack->addWidget(bookpage);
//    ui->PageStack->addWidget(loanpage);
//    ui->PageStack->addWidget(infopage);
//    connect(ui->SelectList,SIGNAL(currentRowChanged(int)),ui->PageStack,SLOT(setCurrentIndex(int)));
}

UserMainWindow::~UserMainWindow()
{
    delete ui;
}
