#include <iostream>
#include "gasStation.h"
#include "customer.h"

using namespace std;

int main()
{
    GasStation s(450);
    Customer c("Anna");
    try
    {
        c.refuel(s,6,5);
        s.getCash();
    }
    catch(GasStation::error err)
    {
        if(err==GasStation::INVALID_STATION)
        {
            cout << "Nem létező töltőállomás."<<endl;
        }
    }
    return 0;
}
