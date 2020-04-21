#include "cashDesk.h"
#include <iostream>

using namespace std;
CashDesk::purchase()
{

    int price;
     price=_s->getDisplay()*_unitPrice;

     cout << "Fizetendő összeg: "<<price;
     _s->clearFuel();

     return price;
}
