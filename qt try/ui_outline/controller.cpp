#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    //database 路径暂时就是"../sqlite/admitDB.db"
    databaseptr = new DB("sqlite/admitDB.db");


    OpenLogin();
}

void Controller::OpenLogin(){
    if(loginptr != nullptr)
        return;
    loginptr = new LoginDialog ();
    loginptr->show();
    connect(loginptr, SIGNAL(LoginSignals(QString,QString,QString)),this,SLOT(Login(QString,QString,QString)));
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

void Controller::OpenUserMainWindow(){
    if(mainwindowptr != nullptr)
        return;
    //needs switch
    mainwindowptr = new UserMainWindow();
    mainwindowptr->show();
}

void Controller::OpenAdministerMainWindow(){
    if(mainwindowptr2 != nullptr)
        return;
    //needs switch
    mainwindowptr2 = new AdministerMainWindow();
    connect(mainwindowptr2->BPage(), SIGNAL(InsertBook()), this, SLOT(InsertBook()));
    connect(mainwindowptr2->BPage(), SIGNAL(SearchBook(QString,QString)), this, SLOT(SearchBook(QString,QString)));
    mainwindowptr2->show();
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
//TODO 模糊搜索图书
void Controller::SearchBook(QString search_info, QString search_type)
{
    if(mainwindowptr2){
        QVector<DataBook*> books = databaseptr->FuzzySearch(search_info,search_type);
        qDebug() << "fuzzysearch";
        mainwindowptr2->BPage()->SetBookTable(books);
        for(DataBook * book : books)
            delete book;
    }
}
//TODO 插入书籍
void Controller::InsertBook()
{
    BookAddDialog *dialog_tmpptr = new BookAddDialog();
    connect(dialog_tmpptr, SIGNAL(InsertBook(DataBook)), this, SLOT(InsertBook(DataBook)));
    dialog_tmpptr ->exec();
}

void Controller::InsertBook(DataBook book)
{
    databaseptr->Insert(&book);
}

void Controller::ChangeBook(QString id)
{

}

void Controller::ChangeBook(QString id, DataBook book)
{

}

void Controller::SelectBookIsbn(QString isbn)
{

}

void Controller::AppointBook(QString id)
{

}

void Controller::ChangePassword(QString password)
{
    if(mainwindowptr2){
        QString account = mainwindowptr2->Account();
        ChangePassword(account, password);
    }
}

void Controller::ChangePassword(QString account, QString password)
{

}

void Controller::SearchRecord(QString key, QString type)
{

}

void Controller::ExtendRecord(QString id)
{

}

void Controller::FinishRecord(QString id)
{

}

void Controller::ChangeUser(QString account, DataUser newinfo)
{

}

void Controller::ShowLogin(){
    if(this->loginptr == nullptr)
        QMessageBox::StandardButton reply = QMessageBox::critical(nullptr, tr("#"),tr("程序出错"),QMessageBox::Retry);
    else{
        this->loginptr->show();
    }
}

void Controller::Login(QString account,QString password, QString type){
        //ui信息未填完不会发送过来
    qDebug() << type;
    switch(databaseptr->EnterCheck(account, password)){
    case LOGINCHECK_SUCCESS_READER:
        if(type == "用户" ){
            OpenUserMainWindow();
            loginptr->close();
            }
        else{
            loginptr->ShowUnmatchRefutation();
        }
        break;
    case LOGINCHECK_NOQUEST:
        loginptr->ShowNoQuestRefutation();
        break;
    case LOGINCHECK_UNMATCH:
        loginptr->ShowUnmatchRefutation();
        break;
    case LOGINCHECK_SUCCESS_ADMINISTRATOR:
        if(type == "管理员"){
            OpenAdministerMainWindow();
            loginptr ->close();
        }
        else{
            loginptr->ShowUnmatchRefutation();
        }
        break;
    default:
        BUG;
       //以上三种情况
    }

}
