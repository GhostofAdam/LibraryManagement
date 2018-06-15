#include <QApplication>
#include <controller.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller Controller;
    //DB db("G:\oop_big_work\sqlite\admitDB.db");
    //db.CreateTable(USER_TABLE);

//     DB test("G:/oop_big_work_debug/sqlite/admitDB.db");
//     Data* b1=new DataBook("01","Silent Spring","carson","science","**","**");
//     Data* b2=new DataBook("02","The three body problem","big liu","science","**","**");
//     test.Insert(b1);
//     test.Insert(b2);
//     std::vector<DataBook> r1=test.ExactSearch("carson");
//     std::vector<DataBook> r2= test.FuzzySearch("sci");
//     for(std::vector<DataBook>::iterator i=r1.begin();i!=r1.end();i++){
//         (*i).show();
//     }

//     for(std::vector<DataBook>::iterator i=r2.begin();i!=r1.end();i++){
//         (*i).show();
//     }
    return a.exec();
}
