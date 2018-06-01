#include "datauser.h"

DataUser::DataUser(QString a, QString p, QString ID, QString d,
                   QString m, QString n, QString s)
{
    this->account = a;
    this->password = p;
    this->schoolID = ID;
    this->department = d;
    this->major = m;
    this->name = n;
    this->sex = s;
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

    return list;
}
void DataUser::Insert(QSqlDatabase& db){

    qDebug() << this->account<<" "<<this->password<<" "<<this->password<<" "<<this->schoolID<<" "<<this->department<<" "<<this->major<<" "<<this->name<<" "<<this->sex;
    QSqlQuery query(db);
    query.prepare(QString("insert into USERS values (?, ?, ?, ?, ?, ?, ?)"));
    QVariantList INFO;
    INFO.append(this->account);
    INFO.append(this->password);
    INFO.append(this->schoolID);
    INFO.append(this->department);
    INFO.append(this->major);
    INFO.append(this->name);
    INFO.append(this->sex);
    query.addBindValue(INFO);

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
       return true;
   }
   else
       return false;
}
