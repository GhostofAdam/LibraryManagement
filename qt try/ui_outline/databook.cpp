#include "databook.h"
#include "datauser.h"

DataBook::DataBook(
QString a ,
QString b ,
QString c ,
QString d,
QString e,
QString f,
QString g)
{

    this->name = a;
    this->author = b;
    this->place = c;
    this->isbn = d;
    this->abstract=e;
    this->state=f;
    this->id=g;


}

std::vector<QString> DataBook::TranslateToString(){
    std::vector<QString> list;
    list.push_back(id);
    list.push_back(name);
    list.push_back(author);
    list.push_back(place);
    list.push_back(isbn);
    list.push_back(abstract);

    return list;

}
void DataBook::Insert(QSqlDatabase& db){
    qDebug() << this->id<<" "<<this->name<<" "<<this->author<<" "<<this->place<<" "<<this->isbn<<" "<<this->state;
    QSqlQuery query(db);
    query.prepare("select count(*) from Books");
    if(query.exec()){;
        query.next();
        qDebug()<<"counted";
        this->id=QString::number(query.value(0).toInt(),10);
    }
    else
        this->id="0";
    qDebug()<<"hahahahashahh  "<<this->id;

    query.prepare(QString("insert into BOOKS values (?, ?, ?, ?, ?,?,?)"));

    query.addBindValue(this->id);
    query.addBindValue(this->name);
    query.addBindValue(this->author);
    query.addBindValue(this->place);
    query.addBindValue(this->isbn);
    query.addBindValue(this->state);
    query.addBindValue(this->abstract);


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

void DataBook::update(QSqlDatabase& db,QString key, QString value){
    QSqlQuery query(db);
    if(key=="name"){
        query.prepare(QString("update Books set name='%1' where id ='%2'").arg(value).arg(this->id));
        name=value;
    }
    else if(key=="author"){
        query.prepare(QString("update Books set author='%1' where id ='%2'").arg(value).arg(this->id));
        author=value;
    }
    else if(key=="place"){
        query.prepare(QString("update Books set place='%1' where id ='%2'").arg(value).arg(this->id));
        place=value;
    }
    else if(key=="isbn"){
        query.prepare(QString("update Books set isbn='%1' where id ='%2'").arg(value).arg(this->id));
        isbn=value;
    }
    else if(key=="abstract"){
        query.prepare(QString("update Books set abstract='%1' where id ='%2'").arg(value).arg(this->id));
        abstract=value;
    }



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
    qDebug()<<id<<" "<<name<<" "<<author<<" "<<place<<" "<<isbn<<" "<<abstract<<" "<<state;
}


void DataBook::update(QSqlDatabase& db){

    qDebug() << name << author << place << isbn << abstract << state << id;
//    query.prepare(QString("update Books set name ='%1',author ='%2',place ='%3',isbn='%4',abstract='%5',state='%6' where id='%7'")
//                   .arg(name).arg(author).arg(place).arg(isbn).arg(abstract).arg(state).arg(id));
//
    {
         QSqlQuery query(db);
        query.prepare(QString("update Books set name='%1' where id ='%2'").arg(name).arg(this->id));
        query.exec();
    }
    {
         QSqlQuery query(db);
        query.prepare(QString("update Books set author='%1' where id ='%2'").arg(author).arg(this->id));
        query.exec();
    }
    {
         QSqlQuery query(db);
        query.prepare(QString("update Books set place='%1' where id ='%2'").arg(place).arg(this->id));
            query.exec();
    }
    {
         QSqlQuery query(db);
        query.prepare(QString("update Books set isbn='%1' where id ='%2'").arg(isbn).arg(this->id));
            query.exec();
    }
    {
         QSqlQuery query(db);
        query.prepare(QString("update Books set abstract='%1' where id ='%2'").arg(abstract).arg(this->id));
        if(!query.exec())
        {
            qDebug() << "update failed"<<query.lastError();

        }
        else
        {
            qDebug() << "update successeded";

        }

    }


}
