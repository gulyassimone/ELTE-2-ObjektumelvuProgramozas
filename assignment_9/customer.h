#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "gasStation.h"

class Customer
{
    public:
        Customer(std::string const &name): _name(name){};
        void refuel(GasStation &g, int ind, int liter) {g.getServiceStation(ind)->fill(liter);};
    private:
        std::string _name;
};

#endif // CUSTOMER_H
