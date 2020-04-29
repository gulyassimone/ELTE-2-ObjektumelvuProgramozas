#ifndef TROPHY_H
#define TROPHY_H
#include <string>

struct IvoryLength
{
    int right;
    int left;
    IvoryLength()
    {
        right=0;
        left=0;
    }
    IvoryLength(int a, int b)
    {
        right=a;
        left=b;
    }
};

struct SpecialAttribute
{
    IvoryLength ivoryLength;
    int hornWeight;
    std::string gender;
    SpecialAttribute()
    {
        ivoryLength=IvoryLength();
        hornWeight=0;
        gender="";
    }
};

template<typename SpecialAttribute>
class Trophy
{
public:
    virtual ~Trophy() {};
    SpecialAttribute getSpecialAttribute()
    {
        return specialAttribute;
    };
    std::string getSpieces()
    {
        return spieces;
    }
protected:
    std::string spieces;
    std::string spot;
    std::string date;
    int weight;
    SpecialAttribute specialAttribute;
    Trophy<SpecialAttribute>(std::string spieces,std::string spot,std::string date,int weight,SpecialAttribute specialAttribute )
    {
        this->spieces=spieces;
        this->spot=spot;
        this->date=date;
        this->weight=weight;
        this->specialAttribute=specialAttribute;
    };
}
;

class Lion : public Trophy<std::string>
{
public:
    Lion(std::string spieces,std::string spot,std::string date,int weight, std::string specialAttribute):Trophy<std::string>(spieces,spot,date,weight,specialAttribute) {};
};

class Rhino : public Trophy<int>
{
public:
    Rhino(std::string spieces, std::string spot, std::string date, int weight, int specialAttribute) : Trophy<int>(spieces, spot, date, weight,specialAttribute) {};

};

class Elephant : public Trophy<IvoryLength>
{
public:
    Elephant(std::string spieces,std::string spot,std::string date,int weight, IvoryLength specialAttribute):Trophy<IvoryLength>(spieces,spot,date,weight,specialAttribute) {};
};
#endif // TROPHY_H
