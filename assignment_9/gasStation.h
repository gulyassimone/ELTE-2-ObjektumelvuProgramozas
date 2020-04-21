#ifndef GASSTATION_H
#define GASSTATION_H
#include <vector>
#include "serviceStation.h"
#include "cashDesk.h"

class GasStation
{
    public:
        GasStation(int unitPrice): _unitPrice(unitPrice), _c(unitPrice){};
        ServiceStation* getServiceStation(int ind) {return _s[ind];};
    private:
        std::vector<ServiceStation*> _s;
        int _unitPrice;
        CashDesk _c;
        void createServiceStation() { int i=1; while(i<8) _s.push_back(new ServiceStation);};
};

#endif // GASSTATION_H
