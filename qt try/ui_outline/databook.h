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
    QString  state;


    friend class DataBookAdapter;
public:
    DataBook(){}
    DataBook(
      QString id,
      QString name ,
      QString author ,
      QString place ,
      QString isbn,
      QString abstract,
      QString state);
    virtual std::vector<QString> TranslateToString();


    virtual void update(QSqlDatabase& db,QString type,QString value);
    virtual void update(QSqlDatabase& db);
    virtual void Insert(QSqlDatabase& db);
    virtual bool IsExist(QSqlDatabase& db);
    virtual void show();



};
#endif // DATABOOK_H
