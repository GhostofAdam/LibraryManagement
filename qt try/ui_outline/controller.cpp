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

void Controller::OpenUserMainWindow(DataUser user){
    if(mainwindowptr2 != nullptr)
        return;
    //needs switch
    mainwindowptr2 = new UserMainWindow(user);
//    connect(mainwindowptr2->BPage(), SIGNAL(InsertBook()), this, SLOT(InsertBook()));
    connect(mainwindowptr2->BPage(), SIGNAL(SearchBook(QString,QString)), this, SLOT(SearchBook(QString,QString)));
    connect(mainwindowptr2->IPage(),SIGNAL(ChangePassword(QString,QString)),this,SLOT(ChangePassword(QString,QString)));
//    connect(mainwindowptr2->BPage(),SIGNAL(ChangeBook(QString)),this,SLOT(ChangeBook(QString)));
//    connect(mainwindowptr2->UPage(),SIGNAL(SearchUser(QString,QString)),this,SLOT(SearchUser(QString,QString)));
//    connect(mainwindowptr2->UPage(),SIGNAL(NukeUser(QString)),this,SLOT(NukeUser(QString)));
//    connect(mainwindowptr2->UPage(),SIGNAL(ChangeInfoofUser(QString)),this,SLOT(ChangeUser(QString)));
//    connect(mainwindowptr2->UPage(),SIGNAL(ClearFineofUser(QString)),this,SLOT(ClearFineofUser(QString)));
    connect(mainwindowptr2->LPage(),SIGNAL(SearchLoan(QString,QString)),this,SLOT(SearchRecord(QString,QString)));
    connect(mainwindowptr2->LPage(),SIGNAL(ExtendLoan(QString)),this,SLOT(ExtendRecord(QString)));
//    connect(mainwindowptr2->LPage(),SIGNAL(FinishLoan(QString)),this,SLOT(FinishRecord(QString)));
//    connect(mainwindowptr2->LPage(),SIGNAL(AcceptReserveLoan(QString)),this,SLOT(AcceptReserveRecord(QString)));
    //调试用
    connect(mainwindowptr2->BPage(), SIGNAL(SelectBookId(QString)),this,SLOT(SelectBookId(QString)));

    mainwindowptr2->show();
}

void Controller::OpenAdministerMainWindow(DataUser user){
    if(mainwindowptr2 != nullptr)
        return;
    //needs switch
    mainwindowptr2 = new AdministerMainWindow(user);
    connect(mainwindowptr2->BPage(), SIGNAL(InsertBook()), this, SLOT(InsertBook()));
    connect(mainwindowptr2->BPage(), SIGNAL(SearchBook(QString,QString)), this, SLOT(SearchBook(QString,QString)));
    connect(mainwindowptr2->IPage(),SIGNAL(ChangePassword(QString,QString)),this,SLOT(ChangePassword(QString,QString)));
    connect(mainwindowptr2->BPage(),SIGNAL(ChangeBook(QString)),this,SLOT(ChangeBook(QString)));
    connect(mainwindowptr2->UPage(),SIGNAL(SearchUser(QString,QString)),this,SLOT(SearchUser(QString,QString)));
    connect(mainwindowptr2->UPage(),SIGNAL(NukeUser(QString)),this,SLOT(NukeUser(QString)));
    connect(mainwindowptr2->UPage(),SIGNAL(ChangeInfoofUser(QString)),this,SLOT(ChangeUser(QString)));
    connect(mainwindowptr2->UPage(),SIGNAL(ClearFineofUser(QString)),this,SLOT(ClearFineofUser(QString)));
    connect(mainwindowptr2->LPage(),SIGNAL(SearchLoan(QString,QString)),this,SLOT(SearchRecord(QString,QString)));
    connect(mainwindowptr2->LPage(),SIGNAL(ExtendLoan(QString)),this,SLOT(ExtendRecord(QString)));
    connect(mainwindowptr2->LPage(),SIGNAL(FinishLoan(QString)),this,SLOT(FinishRecord(QString)));
    connect(mainwindowptr2->LPage(),SIGNAL(AcceptReserveLoan(QString)),this,SLOT(AcceptReserveRecord(QString)));
    //调试用
    connect(mainwindowptr2->BPage(), SIGNAL(SelectBookId(QString)),this,SLOT(SelectBookId(QString)));

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
        if(search_type == "书名")
            search_type = "name";
        else if(search_type == "作者")
            search_type = "author";
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
    qDebug()<<id;
    DataBook* book = dynamic_cast<DataBook *>(databaseptr->SearchBook(id));
    qDebug() << book->id;
    BookChangeDialog *dialog_tmpptr = new BookChangeDialog(*book,mainwindowptr2);
    connect(dialog_tmpptr, SIGNAL(ChangeBook(QString,DataBook)), this, SLOT(ChangeBook(QString,DataBook)));
    dialog_tmpptr ->exec();
    if(mainwindowptr2)
    mainwindowptr2->BPage()->ClearTable();
}

void Controller::ChangeBook(QString id, DataBook book)
{
    databaseptr->update(&book);
}

void Controller::SelectBookId(QString id)
{
     DataBook* book = dynamic_cast<DataBook *>(databaseptr->SearchBook(id));
     BookFromUserPage *dialog_tmpptr = new  BookFromUserPage(*book,mainwindowptr2);
     connect(dialog_tmpptr, SIGNAL(Appoint(QString)), this, SLOT(AppointBook(QString)));
     dialog_tmpptr ->exec();
     if(mainwindowptr2)
     mainwindowptr2->BPage()->ClearTable();
}

void Controller::AppointBook(QString id)
{
    if(mainwindowptr2){
        qDebug()<<id;
        databaseptr->Subscribe(mainwindowptr2->Account(),id);

    }
}

void Controller::ChangePassword(QString oldpassword,QString newpassword)
{
    if(mainwindowptr2){
        QString account = mainwindowptr2->Account();
        switch(databaseptr->EnterCheck(account, oldpassword)){
        case LOGINCHECK_UNMATCH:{
            QMessageBox::StandardButton reply;
            reply = QMessageBox::critical(mainwindowptr2, tr("密码错误"),tr("密码错误，请重新尝试"),QMessageBox::Retry);
            break;
        }
        case LOGINCHECK_SUCCESS_READER:
        case LOGINCHECK_SUCCESS_ADMINISTRATOR:{
            ChangePassword(mainwindowptr2->User(),newpassword);
            QMessageBox::StandardButton reply;
            reply = QMessageBox::information(nullptr,tr("success"),tr("修改成功"),QMessageBox::Ok);
            break;
        }
        default:
            BUG;
        }
    }
}
//??
void Controller::ChangePassword(Data * data, QString password)
{
    if(mainwindowptr2){
        databaseptr->my_update(data,"password",password);
    }
}

void Controller::SearchRecord(QString key, QString type)
{
    if(dynamic_cast<UserMainWindow *>(mainwindowptr2)){
        QString account = mainwindowptr2->Account();
        QVector<DataRecord*> records = databaseptr->ShowRecords(account,"readerID");
        mainwindowptr2->LPage()->SetLoanTable(records);
        for(DataRecord* record: records)
            delete record;
    }
    else{
        if(type == "用户账号")
            type = "readerID";
        else if(type =="书籍编号")
            type = "bookID";
        else if(type == "状态")
            type = "condition";

        QVector<DataRecord*> records = databaseptr->ShowRecords(key,type);
        mainwindowptr2->LPage()->SetLoanTable(records);
        for(DataRecord* record: records)
            delete record;
    }
}

void Controller::ExtendRecord(QString id)
{
    if(mainwindowptr2){
        databaseptr->ExtendRecords(id);
        mainwindowptr2->LPage()->ClearTable();
    }
}

void Controller::FinishRecord(QString id)
{
    if(mainwindowptr2){
        databaseptr->FinishRecords(id);
        mainwindowptr2->LPage()->ClearTable();
    }
}

void Controller::AcceptReserveRecord(QString id)
{
    if(mainwindowptr2){
        databaseptr->AcceptReserveRecords(id);
    }
}

void Controller::SearchUser(QString key, QString type)
{
    qDebug()<< "searchuser";
    if(mainwindowptr2){
        if(type == "账号")
            type = "account";
        else if(type == "学号")
            type = "schoolID";
        else if(type == "院系")
            type = "department";
        else if(type == "专业")
            type = "major";
        else if(type == "姓名")
            type = "name";
        else if(type == "状态")
            type = "permission";

        QVector<DataUser *>users = databaseptr->FuzzySearchUser(key,type);
        mainwindowptr2->UPage()->SetUserTable(users);
        for(DataUser * user: users)
            delete user;
    }
}

void Controller::NukeUser(QString account)
{
    if(mainwindowptr2){
        DataUser * user = dynamic_cast<DataUser *>(databaseptr->SearchReader(account));
        databaseptr->my_update(user, "permission", "Nuked");
    }
}

void Controller::ClearFineofUser(QString account)
{
    if(mainwindowptr2){
        DataUser * user = dynamic_cast<DataUser *>(databaseptr->SearchReader(account));
        databaseptr->my_update(user, "finemoney", "0");
        QMessageBox::StandardButton reply = QMessageBox::information(nullptr, tr("ok"),tr("ok"),QMessageBox::Ok);
        mainwindowptr2->UPage()->ClearTable();
    }
}

void Controller::ChangeUser(QString account)
{
    if(mainwindowptr2){
        DataUser * user = dynamic_cast<DataUser *>(databaseptr->SearchReader(account));
        UserChangeDialog *dialog_tmpptr = new UserChangeDialog(*user,mainwindowptr2);
        connect(dialog_tmpptr,SIGNAL(ChangeUser(DataUser)),this,SLOT(ChangeUser(DataUser)));
        dialog_tmpptr ->exec();
        if(mainwindowptr2)
        mainwindowptr2->UPage()->ClearTable();
    }
}

void Controller::ChangeUser(DataUser newinfo)
{

    databaseptr->update(&newinfo);
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(nullptr,tr("success"),tr("修改成功"),QMessageBox::Ok);
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
            DataUser * user = dynamic_cast<DataUser*>(databaseptr->SearchReader(account));
            OpenUserMainWindow(*user);
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
            DataUser * user = dynamic_cast<DataUser*>(databaseptr->SearchReader(account));
            OpenAdministerMainWindow(*user);
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
