#ifndef GASSTATION_H
#define GASSTATION_H
#include <vector>
#include "serviceStation.h"
#include "cashDesk.h"

class GasStation
{
public:
    GasStation(int unitPrice);
    ~GasStation()
    {
        for(ServiceStation *i: _s)
            delete i;
        delete _c;
    }
    ServiceStation* getServiceStation(int ind)
    {
        _c->setServiceStation(_s[ind]);
        return _s[ind];
    };
    int getCash() const{return _c->purchase();};
private:
    std::vector<ServiceStation*> _s;
    CashDesk *_c;
};

#endif // GASSTATION_H
