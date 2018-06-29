#ifndef DATARECORD_H
#define DATARECORD_H
#include "data.h"
#include "databook.h"
#include  "datauser.h"
class DataRecord: public Data
{
private:
    QString  recordID;
    QString  readerID ;
    QString  bookID ;
    QString  begintime ;
    QString  endtime;
    QString  condition;
    friend class DataRecordAdapter;



public:

    DataRecord(QString  recordID ,
             QString  readerID ,
             QString  bookID ,
             QString  begintime,
             QString  endtime,
             QString  condition="untreated");
    virtual std::vector<QString> TranslateToString();


    virtual void Insert(QSqlDatabase& db);
    virtual void update(QSqlDatabase& db,QString key, QString value);



    Data* thebook(QSqlDatabase& db);
    Data* thereader(QSqlDatabase& db);

    virtual void show(){}
    virtual bool IsExist(QSqlDatabase& db){return 0;}





};
#endif // DATARECORD_H
