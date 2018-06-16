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
    int EnterCheck(const QString& username,const QString& password);//LOGINCHECK_SUCCESS_READER 
                                                                    //LOGINCHECK_SUCCESS_ADMINISTRATOR 
                                                                    //LOGINCHECK_NOQUEST 
                                                                    //LOGINCHECK_UNMATCH 
                                                                    //datauser 增加permission 值为Reader Administrator
    
    bool isExist(Data*data);
    void Insert(Data*data);//插入成功和用户已存在返回SUCCCESS=true，否则返回FAIL=false
                            //对于书籍的插入将自动生成id，此时databook中的id值也被修改
                            //所以务必插入表中不存在书籍
    void Update(Data*data,QString key,QString value);//key为需要更新的列名，value为更新值

    std::vector<DataBook> ExactSearch(QString keyword,QString type);//精确搜索，返回databook的vector
    std::vector<DataBook> FuzzySearch(QString keyword,QString type);//模糊搜索


    


};

#endif // DB_H
