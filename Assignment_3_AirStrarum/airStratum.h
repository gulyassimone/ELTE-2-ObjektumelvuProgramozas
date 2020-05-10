#ifndef AIRSTRATUM_H
#define AIRSTRATUM_H
#include <iostream>

class Else;
class Sunny;
class Rain;

class AirStratum
{
public:
    AirStratum();
//getters
    std::string getName()
    {
        return _name;
    };
    bool remaining()
    {
        return _size < 0.5;
    };
    virtual AirStratum* change (Else *p) = 0;
    virtual AirStratum* change (Sunny *p) = 0;
    virtual AirStratum* change (Rain *p) = 0;
//setters

protected:
    std::string _name;
    int _size;
};

class Oxygen: public AirStratum
{
public:
    Oxygen(int s)
    {
        _name = "Oxygen";
        _size = s;
    };
    AirStratum* change (Else *p) override;
    AirStratum* change (Sunny *p) override;
    AirStratum* change (Rain *p) override;
};

class Ozone: public AirStratum
{
public:
    Ozone(int s)
    {
        _name = "Ozone";
        _size = s;
    };
    AirStratum* change (Else *p) override;
    AirStratum* change (Sunny *p) override;
    AirStratum* change (Rain *p) override;
};

class CarbonDioxide: public AirStratum
{
public:
    CarbonDioxide(int s)
    {
        _name = "CarbonDioxide";
        _size = s;
    };
    AirStratum* change (Else *p) override;
    AirStratum* change (Sunny *p) override;
    AirStratum* change (Rain *p) override;
};

#endif // AIRSTRATUM_H
