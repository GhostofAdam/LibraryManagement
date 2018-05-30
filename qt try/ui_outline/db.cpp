#include "db.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>




#include <QDebug>
DB::DB(const QString& path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
       m_db.setDatabaseName(path);

       if (!m_db.open())
       {
        qDebug() << "Error: connection with database fail";

       }
       else
       {
         qDebug() << "Database: connection ok";
       }


}
DB::~DB()
{
    if (m_db.isOpen())
       {
           m_db.close();
       }
}
int DB::EnterCheck(const QString &username, const QString &password)
{
        qDebug() << username;
        qDebug() << password;
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT PASSWORD FROM ADMITS WHERE USERNAME = (:name)");
        checkQuery.bindValue(":name", username);

        if (checkQuery.exec())
        {
            if (checkQuery.next())
            {
                QString real = checkQuery.value(0).toString();
                qDebug() << real;
                qDebug() << password;

                if(real==password)
                    return 0;
                else
                    return 2;

            }
        }
        else
        {
            qDebug() << "person exists failed: " << checkQuery.lastError();
        }


        return 1;
}
