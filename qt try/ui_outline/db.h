#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <logindialog.h>
#include "configure.h"
class DB
{
private:
    QSqlDatabase m_db;
public:
    DB(const QString& path);
    ~DB();
    int EnterCheck(const QString& username,const QString& password);


};

#endif // DB_H
