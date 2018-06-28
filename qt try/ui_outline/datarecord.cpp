#include "datarecord.h"
DataRecord::DataRecord(QString  _recordID ,
         QString  _readerID ,
         QString  _bookID ,
         QString  _time ){
    recordID=_recordID;
    readerID=_readerID;
    bookID=_bookID;
    time=_time;
    condition="untreated";
}

void DataRecord::Insert(QSqlDatabase &db){
    qDebug() << this->recordID<<" "<<this->readerID<<" "<<this->bookID<<" "<<this->time;
    QSqlQuery query(db);
    query.prepare("select count* from Records");
    query.exec();
    query.next();
    int id=query.value(0).toInt();

    query.prepare(QString("insert into Records values (?, ?, ?, ?)"));

    query.addBindValue(id);
    query.addBindValue(this->readerID);
    query.addBindValue(this->bookID);
    query.addBindValue(this->time);


    if(!query.exec())
    {
        qDebug() << "insert failed"<<query.lastError();

    }
    else
    {
        qDebug() << "insert successeded";

    }
}

std::vector<QString> DataRecord::TranslateToString(){
    std::vector<QString> list;
    list.push_back(recordID);
    list.push_back(readerID);
    list.push_back(bookID);
    list.push_back(time);

    return list;
}

void DataRecord::update(QSqlDatabase& db,QString key, QString value){
    QSqlQuery query(db);
    query.prepare(QString("update Records set %1='%2' where recordID ='%3'").arg(key).arg(value).arg(this->recordID));
    //query.addBindValue(key);
    //query.addBindValue(value);
    //query.addBindValue(this->recordID);

    if(!query.exec())
    {
        qDebug() << "update failed"<<query.lastError();

    }
    else
    {
        qDebug() << "update successeded";

    }



}
