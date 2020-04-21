#include <iostream>
#include "gasStation.h"

GasStation::GasStation(int unitPrice)
{
    _c=new CashDesk(unitPrice);
    int i=1;
    while(i<8)
    {
        _s.push_back(new ServiceStation());
        i++;
    }
}
