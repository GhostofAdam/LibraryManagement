#ifndef DATABOOK_H
#define DATABOOK_H
#include "data.h"

class DataBookAdapter;
class DataBook : public Data
{
private:



    friend class DataBookAdapter;
public:
    QString  id;
    QString  name ;
    QString  author ;
    QString  place ;
    QString  isbn ;
    QString  abstract;
    QString  state;
    DataBook(){}
    DataBook(

      QString name ,
      QString author ,
      QString place ,
      QString isbn,
      QString abstract,
      QString state="on_shelf",
      QString id="debug");
    virtual std::vector<QString> TranslateToString();


    virtual void update(QSqlDatabase& db,QString type,QString value);
    virtual void update(QSqlDatabase& db);
    virtual void Insert(QSqlDatabase& db);
    virtual bool IsExist(QSqlDatabase& db);
    virtual void show();



};
#endif // DATABOOK_H
