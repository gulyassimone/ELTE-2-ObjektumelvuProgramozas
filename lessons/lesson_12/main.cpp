#include <iostream>
#include "library/counting.hpp"
#include "library/enumerator.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/summation.hpp"
#include <sstream>

using namespace std;

struct Trophy
{
    string country;
    bool malelion;
};

istream& operator>>(istream &in, Trophy &e)
{
    string line;
    getline(in, line);
    istringstream is(line);
    is>>e.country;
    string date,species,gender;
    is>>date>>species;

    if( species == "lion")
    {
        int weight;
        is >> weight >> gender;
        e.malelion = (gender=="male");
    }
    return in;
}

class MyCounting : public Counting<bool>
{
public:
    bool cond(const bool &e) const override
    {
        return e;
    };
};

class BoolEnumerator : public Enumerator<bool>
{
private:
    SeqInFileEnumerator<Trophy> _f;
    bool _cur, _end;
public:
    BoolEnumerator(const string &fname) : _f(fname) {}
    void first() override
    {
        _f.first();
        next();
    }
    void next() override;
    bool current() const override
    {
        return _cur;
    }
    bool end() const override
    {
        return _end;
    }
};
class MyOr : Summation <Trophy,bool>
{
private:
    string country;
public:
    MyOr(const string &name) : country(name){};
    bool neutral() const override { return false; }
    bool add(const bool &a, const bool&b) const override { return a || b; }
    bool func(const Trophy &e) const override { return e.malelion; }

    void first() override {};
    bool whileCond(const Trophy &e) const override {return e.country==country; }
};

void BoolEnumerator::next()
{
    if(_end == _f.end()) return;

    MyOr p(_f.current().country);
    p.addEnumerator(&_f);
    p.run();

    _cur=p.result();
}

int main()
{
    MyCounting p;
    BoolEnumerator enor("inp.txt");
    p.addEnumerator(&enor);

    p.run();

    cout << "Darab: " << p.result() << endl;

    return 0;
}
