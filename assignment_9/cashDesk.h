#ifndef CASHDESK_H
#define CASHDESK_H
#include "serviceStation.h"


class CashDesk
{
    public:
        CashDesk(int unitPrice): _unitPrice(unitPrice) {};
        purchase();
        void setServiceStation(ServiceStation *s) { _s=s;}
    private:
        int _unitPrice;
        int _station;
        ServiceStation *_s;
};

#endif // CASHDESK_H
