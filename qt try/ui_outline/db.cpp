#include "db.h"

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QMessageBox>
#include <QTime>
#include "configure.h"




#include <QDebug>
DB::DB(const QString& path)
{

    if(QSqlDatabase::contains("qt_sql_default_connection"))
      m_db = QSqlDatabase::database("qt_sql_default_connection");
    else
      m_db = QSqlDatabase::addDatabase("QSQLITE");

    m_db.setDatabaseName(path);

       if (!m_db.open())
       {
        qDebug() << "Error: connection with database fail";

       }
       else
       {
         qDebug() << "Database: connection ok";
       }
}


DB::~DB()
{
    if (m_db.isOpen())
       {
           m_db.close();
       }
     QSqlDatabase::removeDatabase("QSQLITE");
}
int DB::EnterCheck(const QString &username, const QString &password)
{
        qDebug() << username;
        qDebug() << password;
        QSqlQuery checkQuery(m_db);
        checkQuery.prepare("SELECT * FROM USERS WHERE account = (:name)");
        checkQuery.bindValue(":name", username);

        if (checkQuery.exec())
        {
            if (checkQuery.next())
            {
                QString real = checkQuery.value(1).toString();
                qDebug() << real;
                qDebug() << password;

                if(real==password){
                    QString permission = checkQuery.value(7).toString();
                    if(permission=="Reader")
                        return 0;
                    else if(permission=="Administrator")
                         return 3;
                    else
                        qDebug() << "Permssion error " << checkQuery.lastError();
                }
                else
                    return 2;

            }
        }
        else
        {
            qDebug() << "person exists failed: " << checkQuery.lastError();
        }


        return 1;
}


bool DB::isExist(Data*data){
    return data->IsExist(m_db);
}

void DB::Insert(Data *data)
{


    data->Insert(m_db);
}
void DB::my_update(Data *data,QString key,QString value)
{

    data->update(m_db,key,value);
}

QVector<DataBook*> DB:: ExactSearch(QString keyword,QString type){
     QVector<DataBook*> result;
     QSqlQuery query(m_db);
     qDebug()<<"ExactSearch begin!";
     if(type=="name")
        query.prepare(QString("select * from Books where name = '%1'").arg(keyword));//查找name
       else if(type=="author")
        query.prepare(QString("select * from Books where author = '%1'").arg(keyword));//查找author
     else if(type=="isbn")
         query.prepare(QString("select * from Books where isbn = '%1'").arg(keyword));//查找author
     //query.addBindValue(keyword);
     if (query.exec())
     {
         while (query.next())
         {
             // qDebug()<<"Find one!";
             DataBook* a=new DataBook(QString(query.value(1).toString()),QString(query.value(2).toString()),
                        QString(query.value(3).toString()),QString(query.value(4).toString()),QString(query.value(5).toString()),QString(query.value(6).toString()),QString(query.value(0).toString()));
             result.push_back(a);
         }
     }
     else
     {
         qDebug() << "ExactSearch failed: " << query.lastError();
     }



     return result;
}
QVector<DataBook*> DB::FuzzySearch(QString keyword,QString type){
     QVector<DataBook*> result;


     QSqlQuery query(m_db);
    if(type=="name")
        query.prepare(QString("select * from Books where name like :keyword"));
    else if(type=="author")
        query.prepare(QString("select * from Books where author like :keyword"));
    else if(type=="isbn")
        query.prepare(QString("select * from Books where isbn like :keyword"));

     query.bindValue(":keyword",QString("%%1%").arg(keyword));

     if (query.exec())
     {

        while(query.next())
         {
            //qDebug()<<"Find one!";
            DataBook* a=new DataBook(QString(query.value(1).toString()),QString(query.value(2).toString()),
                       QString(query.value(3).toString()),QString(query.value(4).toString()),QString(query.value(5).toString()),QString(query.value(6).toString()),QString(query.value(0).toString()));

             result.push_back(a);

         }
     }
     else
     {
         qDebug() << "FuzzySearch failed: " << query.lastError();
     }




     return result;

}
QVector<DataUser*>DB:: FuzzySearchUser(QString keyword,QString type){
    QVector<DataUser*> result;


    QSqlQuery query(m_db);
   if(type=="account")
       query.prepare(QString("select * from USERS where account like :keyword"));
   else if(type=="schoolID")
       query.prepare(QString("select * from USERS where schoolID like :keyword"));
   else if(type=="department")
       query.prepare(QString("select * from USERS where department like :keyword"));
   else if(type=="major")
       query.prepare(QString("select * from USERS where major like :keyword"));
   else if(type=="name")
       query.prepare(QString("select * from USERS where name like :keyword"));
   else if(type=="sex")
       query.prepare(QString("select * from USERS where sex like :keyword"));



    query.bindValue(":keyword",QString("%%1%").arg(keyword));

    if (query.exec())
    {

       while(query.next())
        {
           //qDebug()<<"Find one!";
           if(!(QString(query.value(7).toString())=="Administrator")){
           DataUser* a=new DataUser(QString(query.value(0).toString()),QString(query.value(1).toString()),
                      QString(query.value(2).toString()),QString(query.value(3).toString()),QString(query.value(4).toString()),QString(query.value(5).toString()),QString(query.value(6).toString()),QString(query.value(7).toString()),query.value(8).toInt());

            result.push_back(a);}

        }
    }
    else
    {
        qDebug() << "FuzzySearch failed: " << query.lastError();
    }




    return result;
}

QVector<DataRecord*> DB::ShowRecords(QString keyword,QString type){//type有readerID，bookID，begintime,endtime,condition

    QVector<DataRecord*> result;
    QSqlQuery query(m_db);

    if(type=="readerID")
       query.prepare(QString("select * from Records where readerID like :keyword"));
      else if(type=="bookID")
       query.prepare(QString("select * from Records where bookID like :keyword"));
    else if(type=="begintime")
        query.prepare(QString("select * from Records where begintime like :keyword"));
    else if(type=="endtime")
        query.prepare(QString("select * from Records where endtime like :keyword"));
    else if(type=="condition")
        query.prepare(QString("select * from Records where condition like :keyword"));
    query.bindValue(":keyword",QString("%%1%").arg(keyword));

    if (query.exec())
    {
        while (query.next())
        {
            qDebug()<<"Find one!";
            DataRecord* a=new DataRecord(QString(query.value(0).toString()),QString(query.value(1).toString()),QString(query.value(2).toString()),
                       QString(query.value(3).toString()),QString(query.value(4).toString()),QString(query.value(5).toString()));
            result.push_back(a);
        }
    }
    else
    {
        qDebug() << "ExactSearch failed: " << query.lastError();
    }



    return result;
}

Data*  DB::BookofRecord(Data*a){
    DataRecord* b=dynamic_cast<DataRecord*>(a);
    return b->thebook(m_db);
}

Data*  DB::ReaderofRecord(Data*a){
    DataRecord* b=dynamic_cast<DataRecord*>(a);
    return b->thereader(m_db);

}
Data*  DB::SearchReader(QString account){

    QSqlQuery query(m_db);


        query.prepare(QString("select * from USERS where account = '%1'").arg(account));
    //query.addBindValue(keyword);
    if (query.exec())
    {
        if (query.next())
        {
            // qDebug()<<"Find one!";
             if(!(QString(query.value(7).toString())=="Administrator")){
            Data* a=new DataUser(QString(query.value(0).toString()),QString(query.value(1).toString()),QString(query.value(2).toString()),
                       QString(query.value(3).toString()),QString(query.value(4).toString()),QString(query.value(5).toString()),
                                QString(query.value(6).toString()),QString(query.value(7).toString()),query.value(8).toInt() );
            return a;
             }
             return nullptr;
        }
    }
    else
    {
        qDebug() << "Search user from account error! " << query.lastError();
    }



    return nullptr;
}
Data*  DB::FindAdministrator(QString account){

    QSqlQuery query(m_db);


        query.prepare(QString("select * from USERS where account = '%1'").arg(account));
    //query.addBindValue(keyword);
    if (query.exec())
    {
        if (query.next())
        {
            // qDebug()<<"Find one!";
             if(QString(query.value(7).toString())=="Administrator"){
            Data* a=new DataUser(QString(query.value(0).toString()),QString(query.value(1).toString()),QString(query.value(2).toString()),
                       QString(query.value(3).toString()),QString(query.value(4).toString()),QString(query.value(5).toString()),
                                QString(query.value(6).toString()),QString(query.value(7).toString()),query.value(8).toInt() );
            return a;
             }
             return nullptr;
        }
    }
    else
    {
        qDebug() << "Search user from account error! " << query.lastError();
    }



    return nullptr;
}
Data*DB::  SearchBook(QString id){
    QSqlQuery query(m_db);


        query.prepare(QString("select * from Books where id = '%1'").arg(id));
    //query.addBindValue(keyword);
    if (query.exec())
    {
        if (query.next())
        {
            // qDebug()<<"Find one!";
            DataBook* a=new DataBook(QString(query.value(1).toString()),QString(query.value(2).toString()),
                       QString(query.value(3).toString()),QString(query.value(4).toString()),QString(query.value(5).toString()),QString(query.value(6).toString()),QString(query.value(0).toString()));
            return a;
        }
    }
    else
    {
        qDebug() << "SearchBook from id error!" << query.lastError();
    }



    return nullptr;
}

Data*DB::  SearchRecord(QString id){
    QSqlQuery query(m_db);


        query.prepare(QString("select * from Records where recordID = '%1'").arg(id));
    //query.addBindValue(keyword);
    if (query.exec())
    {
        if (query.next())
        {
            // qDebug()<<"Find one!";
            Data* a=new DataRecord(QString(query.value(0).toString()),QString(query.value(1).toString()),QString(query.value(2).toString()),
                       QString(query.value(3).toString()),QString(query.value(4).toString()),QString(query.value(5).toString()));

            return a;
        }
    }
    else
    {
        qDebug() << "Search record from id error! " << query.lastError();
    }



    return nullptr;
}
int DB:: Subscribe(QString readerID,QString bookID){
    QSqlQuery query(m_db);
    query.prepare(QString("select finemoney from USERS where account= '%1'").arg(readerID));
    if (query.exec())
    {
        if (query.next())
        {

            int finemoney=query.value(0).toInt();
            if(finemoney==-1)
                return READER_DISABLE;
        }
    }
    else{
        qDebug() << "subscribe error!!! " << query.lastError();
    }

    query.prepare(QString("select state from Books where id = '%1'").arg(bookID));
    if (query.exec())
    {
        if (query.next())
        {
            QDateTime time = QDateTime::currentDateTime();
            QString str = time.toString("yyyy.MM.dd");
            qDebug()<<str;
            QString state = query.value(0).toString();
            if(state=="on_shelf"){
                QDateTime end=time.addSecs(2678400);
                QString end_time=end.toString("yyyy.MM.dd");
                DataRecord* a=new DataRecord("",readerID, bookID,str,end_time,"borrowed");
                Data* b=new DataBook("","","","","","",bookID);
                my_update(b,"state","borrowed");
                a->Insert(m_db);
                return BORROW_SUCCEED;
            }
            else if(state=="borrowed"){

                DataRecord* a=new DataRecord("",readerID,bookID,str,"","subscribed");
                a->Insert(m_db);
                return SUBSCRIBE_SUCCEED;
            }
        }
    }
    else{
        qDebug() << "subscribe error! " << query.lastError();
    }
}

void DB::Fine(Data*a){
    DataRecord* b=dynamic_cast<DataRecord*>(a);
    b->fine(m_db);
}

void DB::update(Data* _new){
    _new->update(m_db);
}

QVector<QString> DB::UpdateDB(){
    QSqlQuery query;
    query.prepare(QString("select *from Records where condition='subscribed'"));
    QVector<QString> list;
    if(query.exec())
    {
        while(query.next())
        {
            QString bookID=query.value(2).toString();
            QString readerID=query.value(1).toString();
            QString recordID=query.value(0).toString();
            if(query.exec(QString("select state from Books where id='%1'").arg(bookID))){
                if(query.next()){
                    if(query.value(0).toString()=="on_shelf"){
                        Data* a=new DataRecord(recordID,"","","","","");
                        Data* b=new DataBook("","","","","","",bookID);
                        list.push_back(recordID);
                        QDateTime time = QDateTime::currentDateTime();
                        QString str = time.toString("yyyy.MM.dd");
                        QDateTime end=time.addSecs(2678400);
                        QString end_time=end.toString("yyyy.MM.dd");
                        this->my_update(a,"condition","borrowed");
                        this->my_update(a,"begintime",str);
                        this->my_update(a,"endtime",end_time);
                        this->my_update(b,"state","borrowed");



                    }
                }
            }


        }
    }
    for(int i=0;i<list.size();i++)
    {
        qDebug()<<list.at(i);    }
    return list;
}
void DB::FinishRecords(QString id){
    Data*a = SearchRecord(id);
    DataRecord*t= dynamic_cast<DataRecord*>(a);
    Data*b = SearchBook(t->bookID);


    my_update(a,"condition","endborrow");
    my_update(b,"state","on_shelf");
    UpdateDB();
}
void DB:: AcceptReserveRecords(QString id){

}

void DB::ExtendRecords(QString id){
    Data*a = SearchRecord(id);
    DataRecord*t= dynamic_cast<DataRecord*>(a);
    QDateTime time;
    time=QDateTime::fromString(t->endtime,"yyyy.MM.dd");
    QDateTime endtime=time.addSecs(2678400);
    QString _endtime=QString(endtime.toString());

    my_update(a,"endtime",_endtime);
}


