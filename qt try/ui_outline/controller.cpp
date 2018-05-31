#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    //database 路径暂时就是"../LibraryManagement/sqlite/admitDB.db"
    databaseptr = new DB("../LibraryManagement/sqlite/admitDB.db");

    OpenLogin();
}

void Controller::OpenLogin(){
    if(loginptr != nullptr)
        return;
    loginptr = new LoginDialog ();
    loginptr->show();
    connect(loginptr, SIGNAL(LoginSignals(QString,QString)),this,SLOT(Login(QString,QString)));
    connect(loginptr, SIGNAL(OpenRegisterSignals()),this,SLOT(OpenRegister()));
}

void Controller::OpenRegister(){
    if(registerptr != nullptr)
        return;
    registerptr = new RegisterDialog();
    registerptr->show();
    connect(registerptr, SIGNAL(Register(DataUser)),this,SLOT(Register(DataUser)));
    connect(registerptr, SIGNAL(Destruction()),this,SLOT(CloseRegister()));
}

void Controller::OpenMainWindow(){
    if(mainwindowptr != nullptr)
        return;
    //needs switch
    mainwindowptr = new MainWindow();
    mainwindowptr->show();
}

void Controller::CloseRegister()
{
    if(registerptr != nullptr){
    registerptr ->close();
    delete registerptr;
    registerptr = nullptr;
    }
}

void Controller::Register(DataUser data)
{
    if(databaseptr->isExist(&data))
        registerptr->ShowAlreadyExistError();
    else{
        databaseptr->Insert(&data);
        CloseRegister();
    }
}

void Controller::ShowLogin(){
    if(this->loginptr == nullptr)
        QMessageBox::StandardButton reply = QMessageBox::critical(nullptr, tr("#"),tr("程序出错"),QMessageBox::Retry);
    else{
        this->loginptr->show();
    }
}

void Controller::Login(QString account,QString password){
        //ui信息未填完不会发送过来
    switch(databaseptr->EnterCheck(account, password)){
    case LOGINCHECK_SUCCESS:
        loginptr->close();
        OpenMainWindow();
        break;
    case LOGINCHECK_NOQUEST:
        loginptr->ShowNoQuestRefutation();
        break;
    case LOGINCHECK_UNMATCH:
        loginptr->ShowUnmatchRefutation();
        break;
    default:
        BUG;
       //以上三种情况
    }

}
