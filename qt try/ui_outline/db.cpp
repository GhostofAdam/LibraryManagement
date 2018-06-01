#include "db.h"

#include <QSqlQuery>

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
        checkQuery.prepare("SELECT password FROM USERS WHERE account = (:name)");
        checkQuery.bindValue(":name", username);

        if (checkQuery.exec())
        {
            if (checkQuery.next())
            {
                QString real = checkQuery.value(0).toString();
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
bool DB::CreateTable(int type){
    QSqlQuery query(m_db);
    switch (type){
    case USER_TABLE:{
    bool isTableExist = query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("USER"));
    if(isTableExist){
        qDebug()<<"table already exits";
        //PrintTablesType();//查看表类型
        return SUCCESS;//表已存在也返回成功 ture
        }
    else{
        QString create_sql =
                "create table USERS (account int primary key, password varchar(30), schoolID int, department varchar(30),major varchar(30),"
                "name varchar(30),sex boolean)";
        query.prepare(create_sql);
        if(!query.exec())
        {
            qDebug() << "Error: Fail to create table." << query.lastError();
            return FAIL;
        }
        else
        {
            qDebug() << "Table created!";
            //PrintTablesType();//查看表类型
            return SUCCESS;
        }
    }
        break;
}
    default:
            break;
    }




    }

//bool DB::DeleteTable(const QString &type){
//    QSqlQuery query(m_db);
//    bool isTableExist = query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg(type));
//    if(!isTableExist){
//        qDebug<<"table doesn't exist";
//        return SUCCESS;
//    }
//    else{
//    QString clear_sql = "delete from "+type;
//    query.prepare(clear_sql);
//    if(!query.exec())
//    {
//        qDebug() << "delete failed"<<sql_query.lastError();
//        return FAIL;
//    }
//    else
//    {
//        qDebug() << "table cleared";
//        return SUCCESS;
//    }
//    }
//}

//void DB:: PrintTablesType(){
//    QStringList tables = m_db.tables();  //获取数据库中的表
//           qDebug() << QString::fromLocal8Bit("表的个数： %1").arg(tables.count()); //打印表的个数
//           QStringListIterator itr(tables);
//           while (itr.hasNext())
//           {
//               QString tableNmae = itr.next().toLocal8Bit();
//               qDebug() << QString::fromLocal8Bit("表名：")+ tableNmae;
                 
//               outPutTableInfo(tableNmae);
//           }
//}
bool DB::isExist(Data*data){
    return data->IsExist(m_db);
}

void DB::Insert(Data *data)
{
    QSqlQuery query(m_db);

    data->Insert(m_db);
}

 
/*bool InsertUser(const QString& _account, 
const QString&  _password ,
const QString& _schoolID ,
const QString& _department ,
const QString& _major ,
const QString&  _name ,
const QString& _sex ){
   QSqlQuery query(m_db);
   bool isExist = query.exec(QString("select count(*) from USERS where account ='%1')").arg(_account));
   if(isExist){
       qDebug<<"User already exits";
       return SUCCESS;
   }
   else{
     query.prepare(QString("insert into USERS values (%1, %2, %3, %4, %5, %6, %7)").arg(_account).arg(_password).arg(_schoolID).arg(_department).arg(_major).arg(_name).arg(_sex));
     if(!query.exec())
     {
         qDebug() << "insert failed"<<sql_query.lastError();
         return FAIL;
     }
     else
     {
         qDebug() << "table cleared";
         return SUCCESS;
     }
   }
    
}*/
