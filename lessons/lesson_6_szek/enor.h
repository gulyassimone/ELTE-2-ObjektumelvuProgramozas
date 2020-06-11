#ifndef ENOR_H
#define ENOR_H

#include <fstream>


struct Egyenleg
{
    std::string szaml;
    int egy;
};

class Enor
{
public:
    enum Errors {FILEERROR};

    Enor(const std::string fnev);

    void first()
    {
        read();
        next();
    };
    void next();
    Egyenleg current() const
    {
        return _akt;
    };
    bool end() const{return _vege;};
private:
    struct Tranzakcio
    {
        std::string szaml;
        std::string datum;
        int ossz;
    }; //lathatosagat

    enum Status { abnorm, norm};

    std::ifstream _x;
    Tranzakcio _dx;
    Status _sx;
    Egyenleg _akt;
    bool _vege;

    void read();
};

#endif // ENOR_H
