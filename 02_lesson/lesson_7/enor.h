#ifndef ENOR_H
#define ENOR_H

#include <string>
#include <fstream>


class Enor
{
    enum Error{FILEERROR};
    public:
        Enor(const std::string &str);

        void first() {read(); next();};
        void next();
        bool current() const {return _akt;};
        bool end() const {return _vege;};


    private:
        enum Status {abnorm,norm};
        struct Trofea {
            std::string nev;
            std::string fajta;
            int suly;
        };
        std::ifstream _x;
        Trofea _dx;
        Status _sx;
        bool _akt;
        bool _vege;

        void read();
};

#endif // ENOR_H
