#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTextEdit"

MainWindow::MainWindow(QWidget *parent, int type) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
      leftlist = new QListWidget(this);
      stack= new QStackedWidget(this);
      QLabel* label0[4] = {new QLabel("MY INFO"),new QLabel("BOOK INFO"),new QLabel("LENDING INFO"), new QLabel("USER INFO")};
      QLabel* label1[3] = {new QLabel("MY INFO"),new QLabel("BOOK INFO"),new QLabel("LENDING INFO")};
      for(int i = 0; i <= 3; i ++)
          label0[i]->setAlignment(Qt::AlignCenter);
      for(int i = 0 ; i <= 2; i ++)
          label1[i]->setAlignment(Qt::AlignCenter);
//      LoginDialog* l1 =new LoginDialog(); 可以用dialog来当widget

      leftlist->setGeometry(10,10,70,200);
      stack->setGeometry(85,10,300,200);
      resize(390,220);
      switch(type)
      {
       case ADMINISTRATOR_NUM:
           leftlist->addItem("MY INFO");
           leftlist->addItem("BOOK INFO");
           leftlist->addItem("LENDING INFO");
           leftlist->addItem("USER INFO");

           for(int i = 0; i <= 3; i ++)
               stack->addWidget(label0[i]);

          break;
       case USER_NUM:
          leftlist->addItem("MY INFO");
          leftlist->addItem("BOOK INFO");
          leftlist->addItem("LENDING INFO");

          for(int i = 0; i<= 2; i ++)
               stack->addWidget(label1[i]);

          break;
      }

      connect(leftlist,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
