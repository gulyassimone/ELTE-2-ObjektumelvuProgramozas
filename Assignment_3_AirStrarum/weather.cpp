#include "weather.h"

Else* Else::_instance = nullptr;
Else* Else :: instance()
{
    if(_instance == nullptr)
    {
        _instance = new Else();
    }
    return _instance;
}
Else* Else :: transmute(Oxygen* oxygen)
{
    return this;
}
Else* Else :: transmute(Ozone* ozone)
{
    ozone->changeSize(-ozone->getSize()*0.05);
    return this;
}
Else* Else :: transmute(CarbonDioxide* carbonDioxide)
{
    carbonDioxide->changeSize(-carbonDioxide->getSize()*0.1);
    return this;
}
void Else::destroy() { if ( nullptr!=_instance ) delete _instance; }

Rain* Rain::_instance = nullptr;
Rain* Rain :: instance()
{
    if(_instance == nullptr)
    {
        _instance = new Rain();
    }
    return _instance;
}
Rain* Rain :: transmute(Oxygen* oxygen)
{
    oxygen->changeSize(-oxygen->getSize()*0.5);
    return this;
}
Rain* Rain :: transmute(Ozone* ozone)
{
    return this;
}
Rain* Rain :: transmute(CarbonDioxide* carbonDioxide)
{
    return this;
}
void Rain::destroy() { if ( nullptr!=_instance ) delete _instance; }

Sunny* Sunny::_instance = nullptr;
Sunny* Sunny :: instance()
{
    if(_instance == nullptr)
    {
        _instance = new Sunny();
    }
    return _instance;
}
Sunny* Sunny :: transmute(Oxygen* oxygen)
{
    oxygen->changeSize(-oxygen->getSize()*0.05);
    return this;
}
Sunny* Sunny :: transmute(Ozone* ozone)
{
    ozone->changeSize(-ozone->getSize()*0.05);
    return this;
}
Sunny* Sunny :: transmute(CarbonDioxide* carbonDioxide)
{
    return this;
}
void Sunny::destroy() { if ( nullptr!=_instance ) delete _instance; }
