#include "datauser.h"

DataUser::DataUser(QString a, QString p, QString ID, QString d,
                   QString m, QString n, QString s,QString pe,int f)
{
    this->account = a;
    this->password = p;
    this->schoolID = ID;
    this->department = d;
    this->major = m;
    this->name = n;
    this->sex = s;
    this->permission=pe;
    this->finemoney=f;
}

std::vector<QString> DataUser::TranslateToString(){
    std::vector<QString> list;
    list.push_back(account);
    list.push_back(password);
    list.push_back(schoolID);
    list.push_back(department);
    list.push_back(major);
    list.push_back(name);
    list.push_back(sex);
    list.push_back(permission);

    return list;
}
void DataUser::Insert(QSqlDatabase& db){

    qDebug() << this->account<<" "<<this->password<<" "<<" "<<this->schoolID<<" "<<this->department<<" "<<this->major<<" "<<this->name<<" "
             <<this->sex<<" "<<this->permission;
    QSqlQuery query(db);
    query.prepare(QString("insert into USERS values (?, ?, ?, ?, ?, ?, ?, 'Reader', 0)"));

    query.addBindValue(this->account);
    query.addBindValue(this->password);
    query.addBindValue(this->schoolID);
    query.addBindValue(this->department);
    query.addBindValue(this->major);
    query.addBindValue(this->name);
    query.addBindValue(this->sex);
    //query.addBindValue(this->permission);

    if(!query.exec())
    {
        qDebug() << "insert failed"<<query.lastError();

    }
    else
    {
        qDebug() << "insert successeded";

    }
}

bool DataUser::IsExist(QSqlDatabase& db){
    QSqlQuery query(db);
    qDebug()<<"test";
    query.prepare("SELECT password FROM USERS WHERE account = (:name)");
    query.bindValue(":name",account);

   if (query.exec())
   {
       if(query.next())
            return true;
       else
           return false;
   }
   else
      qDebug()<<"error";
       return false;
}
void DataUser::update(QSqlDatabase& db,QString key, QString value){
    QSqlQuery query(db);

    if(key=="password")
        query.prepare(QString("update USERS set password='%1' where account ='%2'").arg(value).arg(this->account));
    else if(key=="schoolID")
        query.prepare(QString("update USERS set schoolID='%1' where account ='%2'").arg(value).arg(this->account));
    else if(key=="department")
        query.prepare(QString("update USERS set department='%1' where account ='%2'").arg(value).arg(this->account));
    else if(key=="major")
        query.prepare(QString("update USERS set major='%1' where account ='%2'").arg(value).arg(this->account));
    else if(key=="name")
        query.prepare(QString("update USERS set name='%1' where account ='%2'").arg(value).arg(this->account));
    else if(key=="sex")
        query.prepare(QString("update USERS set sex='%1' where account ='%2'").arg(value).arg(this->account));
    else if(key=="permission")
        query.prepare(QString("update USERS set permission='%1' where account ='%2'").arg(value).arg(this->account));

    ;

    if(!query.exec())
    {
        qDebug() << "update failed"<<query.lastError();

    }
    else
    {
        qDebug() << "update successeded";

    }



}
void DataUser::update(QSqlDatabase& db){
 QSqlQuery query(db);

       query.prepare(QString("update USERS set password ='%1',schoolID ='%2',department ='%3',major='%4',name='%5', sex='%6',permission='%7',finemoney='%8' where account='%9'")
                       .arg(password).arg(schoolID).arg(department).arg(major).arg(name).arg(sex).arg(permission).arg(finemoney).arg(account));
        if(!query.exec())
        {
            qDebug() << "update failed"<<query.lastError();

        }
        else
        {
            qDebug() << "update successeded";

        }
    }


