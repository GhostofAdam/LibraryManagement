#ifndef DATARECORD_H
#define DATARECORD_H
#include "data.h"
class DataRecord: public Data
{
private:
    QString  recordID;
    QString  readerID ;
    QString  bookID ;
    QString  time ;
    QString  condition;




public:

    DataRecord(QString  recordID ,
             QString  readerID ,
             QString  bookID ,
             QString  time );
    virtual std::vector<QString> TranslateToString();


    virtual void Insert(QSqlDatabase& db);
    virtual void update(QSqlDatabase& db,QString key, QString value);
    virtual void show(){}
    virtual bool IsExist(QSqlDatabase& db){return 0;}




};
#endif // DATARECORD_H
