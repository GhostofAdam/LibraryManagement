#ifndef DATAUSER_H
#define DATAUSER_H
#include "data.h"
#include <QSqlDatabase>

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
    int finemoney = 0;
public:
    DataUser(QString account,QString password, QString schoolID,
             QString department, QString major, QString name,
             QString sex);
    virtual std::vector<QString> TranslateToString();
    virtual void Insert(QSqlDatabase& db);
};

#endif // DATAUSER_H
