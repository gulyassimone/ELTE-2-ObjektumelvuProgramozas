#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>
#include "airStratum.h"

class Weather
{
public:
    Weather();
    virtual void transmute(AirStratum* airStratum);
};
class Else: public Weather
{
public:
    Else();
    void transmute(AirStratum* airStratum) override;
};
class Rain: public Weather
{
public:
    Rain();
    void transmute(AirStratum* airStratum) override;
};
class Sunny: public Weather
{
public:
    Sunny();
    void transmute(AirStratum* airStratum) override;
};

#endif // WEATHER_H
