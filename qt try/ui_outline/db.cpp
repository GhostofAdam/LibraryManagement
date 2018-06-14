#include "db.h"

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QMessageBox>
#include "configure.h"




#include <QDebug>
DB::DB(const QString& path)
{

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

                if(real==password)
                    return 0;
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
    QSqlQuery query(m_db);

    data->Insert(m_db);
}

std::vector<DataBook> DB:: ExactSearch(QString keyword){
     std::vector<DataBook> result;
     QSqlQuery query(m_db);
     query.prepare("select * from Books where name=(:keyword)");//查找name
     query.bindValue(":keyword",keyword);
     if (query.exec())
     {
         if (query.next())
         {
             DataBook a(QString(query.value(0).toString()),QString(query.value(1).toString()),QString(query.value(2).toString()),
                        QString(query.value(3).toString()),QString(query.value(4).toString()));
             result.push_back(a);
         }
     }
     else
     {
         qDebug() << "ExactSearch failed: " << query.lastError();
     }
       
     query.prepare("select * from Books where author= (:keyword)");//查找author
     query.bindValue(":keyword",keyword);
     if (query.exec())
     {
         if (query.next())
         {
             DataBook a(QString(query.value(0).toString()),QString(query.value(1).toString()),QString(query.value(2).toString()),
                        QString(query.value(3).toString()),QString(query.value(4).toString()));
             result.push_back(a);

         }
     }
     else
     {
         qDebug() << "ExactSearch failed: " << query.lastError();
     }
     
     return result;
}
std::vector<DataBook> DB::FuzzySearch(QString keyword){
     std::vector<DataBook> result;

     QSqlQuery query(m_db);

     query.prepare(QString("select* from Books where name like :keyword"));
     query.bindValue(":keyword","%"+keyword+"%");

     if (query.exec())
     {
        while(query.next())
         {
             DataBook a(QString(query.value(0).toString()),QString(query.value(1).toString()),QString(query.value(2).toString()),
                        QString(query.value(3).toString()),QString(query.value(4).toString()));
             result.push_back(a);

         }
     }
     else
     {
         qDebug() << "FuzzySearch failed: " << query.lastError();
     }

     query.prepare(QString("select *from Books where author like :keyword"));
     query.bindValue(":keyword","%"+keyword+"%");

     if (query.exec())
     {
         while (query.next())
         {
             DataBook a(QString(query.value(0).toString()),QString(query.value(1).toString()),QString(query.value(2).toString()),
                        QString(query.value(3).toString()),QString(query.value(4).toString()));
             result.push_back(a);

         }
     }
     else
     {
         qDebug() << "FuzzySearch failed: " << query.lastError();
     }


     return result;

}
