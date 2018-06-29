#include "administermainwindow.h"
#include "ui_administermainwindow.h"
#include <QMessageBox>
AdministerMainWindow::AdministerMainWindow(DataUser user_, QWidget *parent) :
    QWidget(parent),user(user_),
    ui(new Ui::AdministerMainWindow)
{
    ui->setupUi(this);
    bookpage = new BookStackedPage(this);
    loanpage = new LoanStackedPage(this);
    userpage = new UserStackedPage(this);
    infopage = new InfoStackedPage(this);
    ui->PageStack->removeWidget(ui->BookPage);
    ui->PageStack->addWidget(bookpage);
    ui->PageStack->addWidget(loanpage);
    ui->PageStack->addWidget(userpage);
    ui->PageStack->addWidget(infopage);
//    connect(bookpage,SIGNAL(SearchBook(QString,QString)),this,SLOT(on_SearchBook(QString,QString)));
//    connect(bookpage,SIGNAL(SelectBookIsbn(QString)),this,SLOT(on_ChangeBookById(QString)));
//    connect(bookpage,SIGNAL(InsertBook()),this, SLOT(on_InsertBook()));

    bookpage->Adapt2Administer();
    connect(ui->SelectList,SIGNAL(currentRowChanged(int)),ui->PageStack,SLOT(setCurrentIndex(int)));
}

//这个是应该删掉的
AdministerMainWindow::AdministerMainWindow(QWidget *parent)
{
    ui->setupUi(this);
    bookpage = new BookStackedPage(this);
    loanpage = new LoanStackedPage(this);
    userpage = new UserStackedPage(this);
    infopage = new InfoStackedPage(this);
    ui->PageStack->removeWidget(ui->BookPage);
    ui->PageStack->addWidget(bookpage);
    ui->PageStack->addWidget(loanpage);
    ui->PageStack->addWidget(userpage);
    ui->PageStack->addWidget(infopage);
//    connect(bookpage,SIGNAL(SearchBook(QString,QString)),this,SLOT(on_SearchBook(QString,QString)));
//    connect(bookpage,SIGNAL(SelectBookIsbn(QString)),this,SLOT(on_ChangeBookById(QString)));
//    connect(bookpage,SIGNAL(InsertBook()),this, SLOT(on_InsertBook()));

    bookpage->Adapt2Administer();
    connect(ui->SelectList,SIGNAL(currentRowChanged(int)),ui->PageStack,SLOT(setCurrentIndex(int)));

}

AdministerMainWindow::~AdministerMainWindow()
{
    delete ui;
}
