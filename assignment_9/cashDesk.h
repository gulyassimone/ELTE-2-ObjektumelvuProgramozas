#ifndef CASHDESK_H
#define CASHDESK_H
#include "pump.h"


class CashDesk
{
    public:
        CashDesk(int unitPrice): _unitPrice(unitPrice) {};
        int purchase();
        void setPump(Pump *s) { _s=s;}
    private:
        int _unitPrice;
        Pump *_s;
};

#endif // CASHDESK_H
