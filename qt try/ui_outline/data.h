#ifndef DATA_H
#define DATA_H
#include <vector>
#include <Qmap>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>


class Data
{
public:
    Data();
    virtual std::vector<QString> TranslateToString() = 0;
    virtual void Insert(QSqlDatabase& db)=0;//
    virtual bool IsExist(QSqlDatabase& db) = 0;
};

#endif // DATA_H
