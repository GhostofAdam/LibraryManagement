#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    //一打开就有登录界面
    loginptr = new LoginDialog ();
    //database 路径暂时就是"../../sqlite/admitDB.db"
    databaseptr = new DB("../../sqlite/admitDB.db");
    this->ShowLogin();


    connect(loginptr, SIGNAL(LoginSignals(QString,QString)),this,SLOT(login(QString,QString)));
    //连接信号调用
}

void Controller::ShowLogin(){
    if(this->loginptr == nullptr)
        QMessageBox::StandardButton reply = QMessageBox::critical(nullptr, tr("#"),tr("程序出错"),QMessageBox::Retry);
    else{
        this->loginptr->show();
    }
}

void Controller::login(QString account,QString password){
    if(account.size() == 0 || password.size() == 0){
        //账号或密码为空
        loginptr->ShowBlankRefutation();
    }
    else{
        //
        switch(databaseptr->EnterCheck(account, password)){
        case LOGINCHECK_SUCCESS:
            //TODO 分清楚是管理员还是用户
            loginptr->OpenMainWindowofAdministrator();
            loginptr->close();
            break;
        case LOGINCHECK_NOQUEST:
            loginptr->ShowNoQuestRefutation();
            break;
        case LOGINCHECK_UNMATCH:
            loginptr->ShowUnmatchRefutation();
            break;
        default:
            BUG;
            //
        }
    }

}
