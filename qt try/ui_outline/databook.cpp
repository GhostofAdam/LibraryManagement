#include "databook.h"
#include "datauser.h"

DataBook::DataBook(QString a,
QString b ,
QString c ,
QString d ,
QString e)
{
    this->id = a;
    this->name = b;
    this->author = c;
    this->place = d;
    this->isbn = e;


}

std::vector<QString> DataBook::TranslateToString(){
    std::vector<QString> list;
    list.push_back(id);
    list.push_back(name);
    list.push_back(author);
    list.push_back(place);
    list.push_back(isbn);

    return list;

}
void DataBook::Insert(QSqlDatabase& db){
    qDebug() << this->id<<" "<<this->name<<" "<<this->author<<" "<<this->place<<" "<<this->isbn;
    QSqlQuery query(db);
    query.prepare(QString("insert into BOOKS values (?, ?, ?, ?, ?)"));

    query.addBindValue(this->id);
    query.addBindValue(this->name);
    query.addBindValue(this->author);
    query.addBindValue(this->place);
    query.addBindValue(this->isbn);


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
    QSqlQuery query(db);

    query.prepare("SELECT password FROM USERS WHERE id = (:name)");
    query.bindValue(":name",id);

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

void DataBook::update(QSqlDatabase& db){
    QSqlQuery query(db);
    query.prepare(QString("update Books set id='?', name='?',author='?',label='?',abstract='?',comments='?' where id ='?'"));
    query.addBindValue(this->id);
    query.addBindValue(this->name);
    query.addBindValue(this->author);
    query.addBindValue(this->place);
    query.addBindValue(this->isbn);

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
    qDebug()<<id<<" "<<name<<" "<<author<<" "<<place<<" "<<isbn;
}
