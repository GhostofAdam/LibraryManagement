#include "datarecord.h"
DataRecord::DataRecord(QString  _recordID ,
         QString  _readerID ,
         QString  _bookID ,
         QString  _btime ,
                       QString _etime,
                       QString _con){
    recordID=_recordID;
    readerID=_readerID;
    bookID=_bookID;
    begintime=_btime;
    endtime=_etime;
    condition=_con;
}

void DataRecord::Insert(QSqlDatabase &db){
    qDebug() << this->recordID<<" "<<this->readerID<<" "<<this->bookID<<" "<<this->begintime<<" "<<this->endtime<<" "<<this->condition ;
    QSqlQuery query(db);
    query.prepare("select count(*) from Records");
    if(query.exec()){
    query.next();
    this->recordID=QString::number(query.value(0).toInt(),10);
    }
    else
        this->recordID="0";

    query.prepare(QString("insert into Records values (?, ?, ?, ?,?,?)"));

    query.addBindValue(this->recordID);
    query.addBindValue(this->readerID);
    query.addBindValue(this->bookID);
    query.addBindValue(this->begintime);
    query.addBindValue(this->endtime);
    query.addBindValue(this->condition);


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
    list.push_back(begintime);
    list.push_back(endtime);
    list.push_back(condition);


    return list;
}

void DataRecord::update(QSqlDatabase& db,QString key, QString value){
    QSqlQuery query(db);
    if(key=="begintime"){
    query.prepare(QString("update Records set begintime='%1' where recordID ='%2'").arg(value).arg(this->recordID));
    begintime=value;
    }
    else if(key=="endtime"){
        query.prepare(QString("update Records set endtime='%1' where recordID ='%2'").arg(value).arg(this->recordID));
        endtime=value;
    }
    else if(key=="condition"){
        query.prepare(QString("update Records set condition='%1' where recordID ='%2'").arg(value).arg(this->recordID));
        condition=value;
    }
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

Data* DataRecord::thebook(QSqlDatabase& db){
    QSqlQuery query(db);


       query.prepare(QString("select * from Books where id = '%1'").arg(bookID));//查找name

    //query.addBindValue(keyword);
    if (query.exec())
    {
        if (query.next())
        {
            // qDebug()<<"Find one!";
            Data* a=new DataBook(QString(query.value(1).toString()),QString(query.value(2).toString()),QString(query.value(3).toString()),
                       QString(query.value(4).toString()),QString(query.value(0).toString()),QString(query.value(5).toString()));
         return a;
        }
    }
    else
    {
        qDebug()  << query.lastError();
    }


    return NULL;
}
Data* DataRecord::thereader(QSqlDatabase& db){
    QSqlQuery query(db);


       query.prepare(QString("select * from USERS where account = '%1'").arg(readerID));

    //query.addBindValue(keyword);
    if (query.exec())
    {
        if (query.next())
        {
            // qDebug()<<"Find one!";
            Data* a=new DataUser(QString(query.value(0).toString()),QString(query.value(1).toString()),QString(query.value(2).toString()),
                       QString(query.value(3).toString()),QString(query.value(4).toString()),QString(query.value(5).toString()),QString(query.value(6).toString()),
                       QString(query.value(7).toString()));
         return a;
        }
    }
    else
    {
        qDebug()  << query.lastError();
    }

   return NULL;

}
void fine(QSqlDatabase& db){
    QSqlQuery query(db);
    query.prepare(QString("select finemoney from USERS where account = '%1'").arg(readerID));
    if(query.exec())
    {
        if(query.next()){
            int finemoney=query.value(0).toInt;
            finemoney+=10;
        query.prepare(QString("update USERS set finemoney = '%1' where account ='%2'").arg(finemoney).arg(readerID));
    }
        else {
            qDebug() << "Fine error" << query.lastError();
        }
}
}
void DataRecord::update(QSqlDatabase& db){
 QSqlQuery query(db);
        query.prepare(QString("update Records set readerID ='%1',bookID ='%2',begintime ='%3',endtime='%4',condition='%5'where recordID='%6'")
                       .arg(readerID).arg(bookID).arg(begintime).arg(endtime).arg(condition).arg(recordID);
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
