#include <iostream>
#include <sstream>
#include "summation.hpp"
#include "seqinfileenumerator.hpp"
#include "linsearch.hpp"
#include "stringstreamenumerator.hpp"
#include "enumerator.hpp"

using namespace std;
struct Trophy
{
    string species;
    int weight;
};
istream& operator >>(istream &is, Trophy &e)
{
    is >> e.species >> e.weight;
    return is;
}
class MyLinSearch : public LinSearch<Trophy>
{
protected:
    bool cond(const Trophy &e) const override{ return e.species=="lion"; }
};
struct Hunter{
    string name;
    bool haslion;
};

class List:public Summation<Hunter,ostream>
{
public:
    List(ostream *o) : Summation<Hunter,ostream>(o){}
protected:
    string func(const Hunter &e)const override { return e.name+"\n"; }
    bool cond (const Hunter& e ) const override {return e.haslion;}
};
struct Hunt{
    string name;
    string date;
    bool haslion;
};
istream& operator >>(istream &is, Hunt &e)
{
    string line;
    getline(is, line);
    stringstream in(line);
    in>>e.name>>e.date;

    MyLinSearch p;
    StringStreamEnumerator<Trophy> enor(in);
    p.addEnumerator(&enor);
    p.run();
    e.haslion = p.found();
    return is;
}

class MyEnumerator : public Enumerator<Hunter>
{
private:
    SeqInFileEnumerator<Hunt> _f;
    Hunter _curr;
    bool _end;
public:
    MyEnumerator(const string &fn) : _f(fn) {}
    void first() {_f.first(); next(); }
    void next() override;
    Hunter current() const override { return _curr; }
    bool end() const override { return _end; }
};
class MyOr : public Summation<Hunt, bool>
{
private:
    string _name;
public:
    MyOr(const string &str) : _name(str) {}
protected:
    bool neutral() const override {return false; }
    bool add(const bool &a, const bool &b) const override {return a || b; }
    bool func(const Hunt &e) const override { return e.haslion; }
    void first() override {}
    bool whileCond(const Hunt &e) const override { return e.name == _name; }

};

void MyEnumerator::next()
{
    if(( _end = _f.end())) return;

    _curr.name = _f.current().name;
    MyOr p(_curr.name);
    p.addEnumerator(&_f);
    p.run();

    _curr.haslion = p.result();
}
int main(int argc, char* argv[])
{
    string fname = argc>1 ? argv[1] : "inut.txt";

    List p(&cout);
    MyEnumerator enor(fname);
    p.addEnumerator(&enor);
    p.run();

    return 0;
}
