#ifndef DATAUSER_H
#define DATAUSER_H
#include "data.h"

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
};

#endif // DATAUSER_H
