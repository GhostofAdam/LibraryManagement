#ifndef DATAUSERADAPTER_H
#define DATAUSERADAPTER_H
#include "datauser.h"

class DataUserAdapter
{
private:
    DataUser *user;
public:
    DataUserAdapter(DataUser* u):user(u){}
    QString Account(){
        return user->account;
    }
    QString Department(){
        return user->department;
    }
    QString Major(){
        return user->major;
    }
    QString Sex(){
        return user->sex;
    }
    QString Name(){
        return user->name;
    }
};

#endif // DATAUSERADAPTER_H
