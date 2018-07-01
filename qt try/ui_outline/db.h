#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <logindialog.h>
#include "configure.h"
#include "data.h"
#include "databook.h"
#include "datauser.h"
#include <vector>
#include "datarecord.h"
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
    void my_update(Data*data,QString key,QString value);//key为需要更新的列名，value为更新值
                                                     //book的key有:name author place isbn abstract
                                                     //record的key有begintime,endtime,condition
                                                     //管理员未批准时begintime endtime可表示申请时间和处理请求截至时间
                                                     //批准后表示借书时间和归还时间
    int Subscribe(QString readerID,QString bookID);
    void Fine(Data*);

    void update(Data* _new);
    QVector<QString> UpdateDB();


    QVector<DataBook*> ExactSearch(QString keyword,QString type);//精确搜索，返回databook的vector
    QVector<DataBook*> FuzzySearch(QString keyword,QString type);//模糊搜索

    QVector<DataUser*> FuzzySearchUser(QString keyword,QString type);

    void AcceptReserveRecords(QString id);//接受预约
    void ExtendRecords(QString id);//延长借阅
    void FinishRecords(QString id);//归还图书

    QVector<DataRecord*> ShowRecords(QString keyword,QString type);//type有readerID，bookID，begintime,endtime,condition

    Data*  BookofRecord(Data*);//请确认输入参数是datarecord，我将在函数中做类型转换
    Data*  ReaderofRecord(Data*); //请确认输入参数是datarecord，我将在函数中做类型转换

    Data*  SearchReader(QString);
    Data*  SearchBook(QString);
    Data*  SearchRecord(QString);







};

#endif // DB_H
