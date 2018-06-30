#ifndef DATAUSER_H
#define DATAUSER_H
#include "data.h"

class DataUserAdapter;
class DataUser : public Data
{
private:
    QString  account ;
    QString  password ;
    QString  schoolID ;
    QString  department ;
    QString  major ;
    QString  name ;
    QString  sex ;
    QString  permission;
    int finemoney = 0;
    friend class DataUserAdapter;
public:
    DataUser(QString account,QString password, QString schoolID,
             QString department, QString major, QString name,
             QString sex,QString permission,int finemoney);

    virtual std::vector<QString> TranslateToString();
    virtual void Insert(QSqlDatabase& db);
    virtual bool IsExist(QSqlDatabase& db);
    virtual void update(QSqlDatabase& db,QString key, QString value);
    virtual void update(QSqlDatabase& db);
    virtual void show();
};

#endif // DATAUSER_H
