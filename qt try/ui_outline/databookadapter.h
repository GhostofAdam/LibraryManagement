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
    QString id(){
        return this->book.id;
    }

    QString abstract(){
        return this->book.abstract;
    }

    QString author(){
       return this->book.author;
    }

    QString title(){
       return this->book.name;
    }

    QString place(){
       return this->book.place;
    }

    QString isbn(){
       return this->book.isbn;
    }

//    int id(){
//        return book.id.toInt();
//    }
};

#endif // DATABOOKADAPTER_H
