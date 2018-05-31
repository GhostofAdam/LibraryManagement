#ifndef DATA_H
#define DATA_H
#include <vector>
#include <Qmap>
#include <QString>
#include <QSqlDatabase>

class Data
{
public:
    Data();
    virtual std::vector<QString> TranslateToString() = 0;
    virtual void Insert(QSqlDatabase& db)=0;//暂时传数据库的引用
};

#endif // DATA_H
