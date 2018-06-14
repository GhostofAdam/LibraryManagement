#include "databook.h"
#include "datauser.h"

DataBook::DataBook(QString a,
QString b ,
QString c ,
QString d ,
QString e,
QString f)
{
    this->id = a;
    this->name = b;
    this->author = c;
    this->label = d;
    this->abstract = e;
    this->comments = f;

}

std::vector<QString> DataBook::TranslateToString(){
    std::vector<QString> list;
    list.push_back(id);
    list.push_back(name);
    list.push_back(author);
    list.push_back(label);
    list.push_back(abstract);
    list.push_back(comments);

    return list;

}
void DataBook::Insert(QSqlDatabase& db){
    qDebug() << this->id<<" "<<this->name<<" "<<this->author<<" "<<this->label<<" "<<this->abstract<<" "<<this->comments;
    QSqlQuery query(db);
    query.prepare(QString("insert into BOOKS values (?, ?, ?, ?, ?, ?)"));

    query.addBindValue(this->id);
    query.addBindValue(this->name);
    query.addBindValue(this->author);
    query.addBindValue(this->label);
    query.addBindValue(this->abstract);
    query.addBindValue(this->comments);


    if(!query.exec())
    {
        qDebug() << "insert failed"<<query.lastError();

    }
    else
    {
        qDebug() << "insert successeded";

    }
}

bool DataBook::IsExist(QSqlDatabase& db){
}

void DataBook::update(QSqlDatabase& db){
    QSqlQuery query(db);
    query.prepare(QString("update Books set id='?', name='?',author='?',label='?',abstract='?',comments='?' where id ='?'"));
    query.addBindValue(this->id);
    query.addBindValue(this->name);
    query.addBindValue(this->author);
    query.addBindValue(this->label);
    query.addBindValue(this->abstract);
    query.addBindValue(this->comments);
    
    if(!query.exec())
    {
        qDebug() << "update failed"<<query.lastError();

    }
    else
    {
        qDebug() << "update successeded";

    }
    
                          
                          
}
void DataBook::show(){
    qDebug()<<id<<" "<<name<<" "<<author<<" "<<label<<" "<<abstract<<" "<<comments;
}
