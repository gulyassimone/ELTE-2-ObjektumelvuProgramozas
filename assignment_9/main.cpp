#include <iostream>
#include "gasStation.h"
#include "customer.h"

using namespace std;

int main()
{
    GasStation s(450);
    Customer c("Anna");
    c.refuel(s,1,10);
    s.getCash();
    return 0;
}
