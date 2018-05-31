#ifndef DATA_H
#define DATA_H
#include <vector>
#include <Qmap>
#include <QString>

class Data
{
public:
    Data();
    virtual void TranslateFromString(std::vector<QString>) = 0;
    virtual std::vector<QString> TranslateToString() = 0;
};

#endif // DATA_H
