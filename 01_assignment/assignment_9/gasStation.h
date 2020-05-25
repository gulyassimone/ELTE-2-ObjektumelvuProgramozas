#ifndef GASSTATION_H
#define GASSTATION_H
#include <vector>
#include "pump.h"
#include "cashDesk.h"

class GasStation
{
public:
    enum error{INVALID_STATION};
    GasStation(int unitPrice);
    ~GasStation()
    {
        for(Pump *i: _s)
            delete i;
        delete _c;
    }
    Pump* getPump(int ind);
    int getCash() const{return _c->purchase();};
private:
    std::vector<Pump*> _s;
    CashDesk *_c;
};

#endif // GASSTATION_H
