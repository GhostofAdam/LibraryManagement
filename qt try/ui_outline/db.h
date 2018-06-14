#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <logindialog.h>
#include "configure.h"
#include "data.h"
#include "databook.h"
#include <vector>
class DB
{
private:
    QSqlDatabase m_db;
public:
    DB(const QString& path);
    ~DB();
    int EnterCheck(const QString& username,const QString& password);
    //bool CreateTable(int type);//创建成功和表已存在返回SUCCCESS=true，否则返回FAIL=false
    //bool DeleteTable(const QString& type);//删除成功和表不存在返回SUCCCESS=true，否则返回FAIL=false
    //void PrintTablesType();//debug用，qdebug输出所有表类型，没几个表就没做查找了
    bool isExist(Data*data);
    void Insert(Data*data);//插入成功和用户已存在返回SUCCCESS=true，否则返回FAIL=false

    std::vector<DataBook> ExactSearch(QString keyword);//精确搜索，返回databook的vector
    std::vector<DataBook> FuzzySearch(QString keyword);//模糊搜索


    


};

#endif // DB_H
