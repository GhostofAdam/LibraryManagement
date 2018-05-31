#include <QApplication>
#include <controller.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller Controller;
    DB test("../../sqlite/admitDB.db");
    test.CreateTable(USER_TYPE);
    return a.exec();
}
