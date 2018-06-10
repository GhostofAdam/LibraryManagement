#ifndef DATABOOK_H
#define DATABOOK_H
#include "data.h"
class DataBook : public Data
{
private:
    QString author;
    QString title;
    QString place;
    QString isbn;

    friend class DataBookAdapter;
public:
    std::vector<QString> TranslateToString(){    std::vector<QString> list;
                                                 return list;}
    void Insert(QSqlDatabase& db){}
    bool IsExist(QSqlDatabase& db){return 1;}
    DataBook();
};

#endif // DATABOOK_H
