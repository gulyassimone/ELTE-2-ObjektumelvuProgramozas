#ifndef ENOR_H
#define ENOR_H
#include <fstream>

struct Order
{
    std::string food;
    int price;
};

class Enor
{
    public:
        enum Errors{FILEERROR};

        Enor(const std::string fname);

        void first(){read();next();};
        void next();
        Order current() const
        {
            return _act;
        }
        bool end() const{return _end;};


    private:
        struct Temp
        {
            int number;
            std::string food;
            std::string date;
            int portion;
            int price;
        };
        enum Status{abnorm,norm};

        std::ifstream _x;
        Temp _dx;
        Status _sx;
        Order _act;
        bool _end;

        void read();
};

#endif // ENOR_H
