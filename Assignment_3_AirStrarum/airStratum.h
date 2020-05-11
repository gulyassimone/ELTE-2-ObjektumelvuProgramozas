#ifndef AIRSTRATUM_H
#define AIRSTRATUM_H
#include <iostream>

class Else;
class Sunny;
class Rain;

class AirStratum
{
public:
    virtual ~AirStratum() {};
    char getName(){return _name;}
    char getSize(){return _size;}
    bool remaining()
    {
        return _size < 0.5;
    }
    void changeSize(int e)
    {
        _size +=e ;
    }
protected:
    AirStratum (const char ch, int e = 0) :_name(ch), _size(e) {}
    char _name;
    int _size;
};

class Oxygen: public AirStratum
{
public:
Oxygen(const char ch, int e = 0) : AirStratum(ch,e) {};
    ~Oxygen() {};
};

class Ozone: public AirStratum
{
public:
Ozone(const char ch, int e = 0): AirStratum(ch,e) {};
    ~Ozone() {};
};

class CarbonDioxide: public AirStratum
{
public:
CarbonDioxide(const char ch, int e = 0) : AirStratum(ch,e) {};
    ~CarbonDioxide() {};
};

#endif // AIRSTRATUM_H
