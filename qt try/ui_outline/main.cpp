#include <QApplication>
#include <controller.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller Controller;
    //DB db("G:\oop_big_work\sqlite\admitDB.db");
    //db.CreateTable(USER_TABLE);
    return a.exec();
}
