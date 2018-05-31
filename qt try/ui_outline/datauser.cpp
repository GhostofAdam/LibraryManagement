#include "datauser.h"
#include <QSqlDatabase>

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
    QSqlQuery query(db);
    query.prepare(QString("insert into USERS values (%1, %2, %3, %4, %5, %6, %7)")
                  .arg(this->account).arg(this->password).arg(this->schoolID).arg(this->department).arg(this->major).arg(this->name).arg(this->sex));
}
