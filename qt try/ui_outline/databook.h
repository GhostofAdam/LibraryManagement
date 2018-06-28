#ifndef DATABOOK_H
#define DATABOOK_H
#include "data.h"

class DataBookAdapter;
class DataBook : public Data
{
private:
    QString  id;
    QString  name ;
    QString  author ;
    QString  place ;
    QString  isbn ;
    QString  abstract;


    friend class DataBookAdapter;
public:
    DataBook(){}
    DataBook(
      QString name ,
      QString author ,
      QString place ,
      QString isbn,
      QString id="*",
      QString abstract="*");
    virtual std::vector<QString> TranslateToString();
    
    virtual void update(QSqlDatabase& db,QString type,QString value);
    virtual void Insert(QSqlDatabase& db);
    virtual bool IsExist(QSqlDatabase& db);
    virtual void show();



};
#endif // DATABOOK_H
