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

class Trophy
{
public:
    virtual ~Trophy() {};
    SpecialAttribute getSpecialAttribute()
    {
        return specialAttribute;
    }
    std::string getSpieces()
    {
        return spieces;
    }
protected:
    std::string spieces;
    std::string spot;
    std::string date;
    int weight;
    SpecialAttribute specialAttribute=SpecialAttribute();
    Trophy(std::string spieces,std::string spot,std::string date,int weight,IvoryLength specialAttribute );
    Trophy(std::string spieces,std::string spot,std::string date,int weight,std::string specialAttribute );
    Trophy(std::string spieces,std::string spot,std::string date,int weight,int specialAttribute );
}
;

class Lion : public Trophy
{
public:
    Lion(std::string spieces,std::string spot,std::string date,int weight, std::string specialAttribute):Trophy(spieces,spot,date,weight,specialAttribute)
    {
        this->specialAttribute.gender=specialAttribute;
    };
};

class Rhino : public Trophy
{
public:
    Rhino(std::string spieces, std::string spot, std::string date, int weight, int specialAttribute) : Trophy(spieces, spot, date, weight,specialAttribute)
    {
        this->specialAttribute.hornWeight=specialAttribute;
    }

};

class Elephant : public Trophy
{
public:
    Elephant(std::string spieces,std::string spot,std::string date,int weight, IvoryLength specialAttribute):Trophy(spieces,spot,date,weight,specialAttribute)
    {
        this->specialAttribute.ivoryLength=specialAttribute;
    }

};
#endif // TROPHY_H
