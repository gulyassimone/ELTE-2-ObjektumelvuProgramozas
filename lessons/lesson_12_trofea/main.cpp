#include <iostream>
#include <sstream>
#include "library/counting.hpp"
#include "library/enumerator.hpp"
#include "library/seqinfileenumerator.hpp"

using namespace std;

struct Trophy {
    string country;
    bool malelion;
};

istream& operator>>(istream& in, Trophy &e)
{
    string line;
    getline(in, line);
    istringstream is(line);

    is >> e.country;
    string date, species, gender;
    int weigth;
    is >> date >> species;
    if( species=="lion") { is >> weigth >> gender; e.malelion = (gender=="male"); }

    return in;
}

class MyCounting : public Counting<bool> {
public:
    bool cond(const bool &e) const override { return e; }
};

class BoolEnumerator : public Enumerator<bool> {
private:
    SeqInFileEnumerator<Trophy> _f;
    bool _cur, _end;
public:
    BoolEnumerator(const string& fname) : _f(fname) {}
    void first() override { _f.first(); next(); }
    void next() override;
    bool current() const override { return _cur; }
    bool end() const override { return _end; }
};

class MyOr : public Summation<Trophy, bool> {
private:
    string country;
public:
    MyOr(const string& name) : country(name) {}
    bool neutral() const override { return false; }
    bool add(const bool& a, const bool& b) const override { return a || b; }
    bool func(const Trophy& e) const override { return e.malelion; }

    void first() override {}
    bool whileCond(const Trophy& e) const override { return e.country == country;}
};

void BoolEnumerator::next()
{
    if ((_end = _f.end())) return;

    MyOr p(_f.current().country);
    p.addEnumerator(&_f);
    p.run();

    _cur = p.result();
}

int main(int argc, char* argv[])
{
    string inputfile_name = (argc==1)? "input.txt" : argv[1];

    try{
        MyCounting p;
        BoolEnumerator enor(inputfile_name);
        p.addEnumerator(&enor);

        p.run();

        cout << "Darab: " << p.result() << endl;
    }catch(SeqInFileEnumerator<Trophy>::Exceptions ex){
        cout << "Rossz file nev\n";
    }
    return 0;
}
