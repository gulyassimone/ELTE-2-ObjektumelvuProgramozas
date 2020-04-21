#include <iostream>
#include "gasStation.h"

GasStation::GasStation(int unitPrice)
{
    _c=new CashDesk(unitPrice);
    int i=1;
    while(i<8)
    {
        _s.push_back(new Pump());
        i++;
    }
}
Pump* GasStation::getPump(int ind)
{
    if(!(ind>0 && ind<8))
        throw INVALID_STATION;
    _c->setPump(_s[ind-1]);
    return _s[ind-1];
};
