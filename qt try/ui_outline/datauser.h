#ifndef DATAUSER_H
#define DATAUSER_H
#include "data.h"

class DataUser : public Data
{
private:
    QMap<QString,QString> map;
    int finemoney = 0;
public:
    DataUser();
    virtual void TranslateFromString(std::vector<QString>){}
    virtual std::vector<QString> TranslateToString(){}
};

#endif // DATAUSER_H
