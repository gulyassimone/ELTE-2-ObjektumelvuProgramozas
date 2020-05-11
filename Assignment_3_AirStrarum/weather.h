#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>
#include "airStratum.h"

class Oxygen;
class Ozone;
class CarbonDioxide;

class Weather
{
public:
    virtual ~Weather() {}
    virtual Weather* transmute(Oxygen* oxygen) = 0;
    virtual Weather* transmute(Ozone* ozone) = 0;
    virtual Weather* transmute(CarbonDioxide* carbonDioxide) = 0;
};
class Else: public Weather
{
public:
    static Else* instance();
    virtual Else* transmute(Oxygen* oxygen) override;
    virtual Else* transmute(Ozone* ozone) override;
    virtual Else* transmute(CarbonDioxide* carbonDioxide) override;
    static void destroy();
private:
    Else() {}
    static Else* _instance;
};
class Rain: public Weather
{
public:
    static Rain* instance();
    virtual Rain* transmute(Oxygen* oxygen) override;
    virtual Rain* transmute(Ozone* ozone) override;
    virtual Rain* transmute(CarbonDioxide* carbonDioxide) override;
    static void destroy();
private:
    Rain() {}
    static Rain* _instance;
};
class Sunny: public Weather
{
public:
    static Sunny* instance();
    virtual Sunny* transmute(Oxygen* oxygen) override;
    virtual Sunny* transmute(Ozone* ozone) override;
    virtual Sunny* transmute(CarbonDioxide* carbonDioxide) override;
    static void destroy();
private:
    Sunny() {}
    static Sunny* _instance;
};

#endif // WEATHER_H
