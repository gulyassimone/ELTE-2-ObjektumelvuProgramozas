#include <iostream>
#include "library/maxsearch.hpp"
#include "library/linsearch.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"

using namespace std;

struct Data {
    string date;
    int weigth;
    int distance;
};

istream& operator>>(istream& is, Data &e){
    is >> e.date >> e.weigth >> e.distance;
    cout << "date " <<  e.date << " weight " << e.weigth <<" distance "<< e.distance;;
    return is;
}

class MyLinSearch : public LinSearch<Data> {
protected:
    bool cond(const Data& e) const override { cout << " tav "<<e.distance <<endl; return e.distance < 3; }
};

struct BlackHole {
    string name;
    int weigth;
    bool isClosed;
};

istream& operator>>(istream& is, BlackHole &e)
{
    string line;
    getline(is, line);

    cout << "line " << line << endl;
    stringstream in(line);

    in >> e.name;
    cout << "name" <<e.name << endl;
    MyLinSearch p;
    StringStreamEnumerator<Data> enor(in);
    p.addEnumerator(&enor);
    p.run();
    e.isClosed = p.found();
    e.weigth = p.elem().weigth;
    cout << "found "<< p.found() << endl;

    return is;
}

class MyMaxSearch : public MaxSearch<BlackHole, int>
{

public:
protected:
    int  func(const BlackHole& e) const override
    {
        return e.weigth;
    }
};

int main(int argc, char* argv[])
{
    string fname = argc>1 ? argv[1] : "input.txt";

    MyMaxSearch p;
    SeqInFileEnumerator<BlackHole> enor(fname);
    p.addEnumerator(&enor);
    p.run();

    cout << p.optElem().name ;
    return 0;
}
