#ifndef DATARECORD_H
#define DATARECORD_H
#include "data.h"
#include "databook.h"
#include  "datauser.h"
class DataRecord: public Data
{
private:

    friend class DataRecordAdapter;



public:
    QString  recordID;
    QString  readerID ;
    QString  bookID ;
    QString  begintime ;
    QString  endtime;
    QString  condition;
    DataRecord(QString  recordID ,
             QString  readerID ,
             QString  bookID ,
             QString  begintime,
             QString  endtime,
             QString  condition="untreated");
    virtual std::vector<QString> TranslateToString();


    virtual void Insert(QSqlDatabase& db);
    virtual void update(QSqlDatabase& db,QString key, QString value);
    virtual bool IsExist(QSqlDatabase& db){}
    virtual void show(){
        qDebug()<<recordID<<" "<<readerID<<" "<<bookID<<" "<<begintime<<" "<<endtime<<" "<<condition;
    }
    virtual void update(QSqlDatabase& db);
    Data* thebook(QSqlDatabase& db);
    Data* thereader(QSqlDatabase& db);
    void fine(QSqlDatabase& db);





};
#endif // DATARECORD_H
