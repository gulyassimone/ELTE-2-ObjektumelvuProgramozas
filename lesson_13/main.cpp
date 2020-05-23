#include <iostream>
#include <sstream>
#include "summation.hpp"
#include "seqinfileenumerator.hpp"
#include "linsearch.hpp"
#include "stringstreamenumerator.hpp"

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

istream& operator >>(istream &is, Hunter &e)
{
    string line;
    getline(is, line);
    stringstream in(line);
    in>>e.name;

    MyLinSearch p;
    StringStreamEnumerator<Trophy> enor(in);
    p.addEnumerator(&enor);
    p.run();
    e.haslion = p.found();

    return is;
}

class List:public Summation<Hunter,ostream>
{
public:
    List(ostream *o) : Summation<Hunter,ostream>(o){}
protected:
    string func(const Hunter &e)const override { return e.name+"\n"; }
    bool cond (const Hunter& e ) const override {return e.haslion;}
};
int main(int argc, char* argv[])
{
    string fname = argc>1 ? argv[1] : "inut.txt";

    List p(&cout);
    SeqInFileEnumerator<Hunter> enor(fname);
    p.addEnumerator(&enor);
    p.run();

    return 0;
}
