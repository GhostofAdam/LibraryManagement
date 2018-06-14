#ifndef DATABOOKADAPTER_H
#define DATABOOKADAPTER_H
#include "databook.h"


class DataBook;
class DataBookAdapter
{
private:
    DataBook book;
public:
    DataBookAdapter(DataBook databook):book(databook){}
    QString author(){
        //return this->book.author;
    }

    QString title(){
       // return this->book.title;
    }

    QString place(){
       // return this->book.place;
    }

    QString isbn(){
     //   return this->book.isbn;
    }
};

#endif // DATABOOKADAPTER_H
