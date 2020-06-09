#include <iostream>
#include <fstream>

using namespace std;

struct Kaktusz{
    string nev;
    string os;
    string szin;
};

enum Errors { WRONG_FILE_NAME };

ifstream openInputfile(const string &fnev);
ofstream openOutputfile(const string &fnev);
void valogat(ifstream &f, ofstream &g);

ifstream openInputfile(const string &fnev)
{
    ifstream f(fnev.c_str());
    if(f.fail()) throw WRONG_FILE_NAME;
    return f;
}
ofstream openOutputfile(const string &fnev)
{
    ofstream f(fnev.c_str());
    if(f.fail()) throw WRONG_FILE_NAME;
    return f;
}

void valogat(ifstream &x, ofstream &y, ofstream &z)
{
    Kaktusz e;
    while(x >> e.nev >> e.os >> e.szin){
        if( "piros" == e.szin)  y << e.nev << endl;
        if( "mexico"== e.os)    z << e.nev << endl;
    }
}

//#define NORMAL_MODE
#ifdef NORMAL_MODE

using namespace std;

int main()
{
    try{
        ifstream x = openInputfile("inp.txt");;
        ofstream y = openOutputfile("outpiros.txt");
        ofstream z = openOutputfile("outmexico.txt");
        valogat(x, y, z);
    } catch(Errors er){
        cout << "Rossz filenév\n";
    }
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("empty", "inp0.txt")
{
    ifstream x = openInputfile( "inp0.txt");  REQUIRE(!x.fail());
    ofstream y = openOutputfile("outP0.txt"); REQUIRE(!x.fail());
    ofstream z = openOutputfile("outM0.txt"); REQUIRE(!x.fail());
    valogat(x,y,z);

    int c;
    string str;

    ifstream f("outP0.txt");
    c = 0;
    while(getline(f,str)) ++c;
    CHECK(0==c);

    ifstream g("outM0.txt");
    c = 0;
    while(getline(g,str)) ++c;
    CHECK(0==c);
}

TEST_CASE("one", "inp1.txt")
{
    ifstream x = openInputfile( "inp1.txt");  REQUIRE(!x.fail());
    ofstream y = openOutputfile("outP1.txt"); REQUIRE(!x.fail());
    ofstream z = openOutputfile("outM1.txt"); REQUIRE(!x.fail());
    valogat(x,y,z);

    int c;
    string str;

    ifstream f("outP1.txt");
    c = 0;
    while(getline(f,str)) ++c;
    CHECK(1==c);

    ifstream g("outM1.txt");
    c = 0;
    while(getline(g,str)) ++c;
    CHECK(1==c);
}

TEST_CASE("two", "inp2.txt")
{
    ifstream x = openInputfile( "inp2.txt");  REQUIRE(!x.fail());
    ofstream y = openOutputfile("outP2.txt"); REQUIRE(!x.fail());
    ofstream z = openOutputfile("outM2.txt"); REQUIRE(!x.fail());
    valogat(x,y,z);

    int c;
    string str;

    ifstream f("outP2.txt");
    c = 0;
    while(getline(f,str)) ++c;
    CHECK(2==c);

    ifstream g("outM2.txt");
    c = 0;
    while(getline(g,str)) ++c;
    CHECK(1==c);
}

TEST_CASE("first", "inp3.txt")
{
    ifstream x = openInputfile( "inp3.txt");  REQUIRE(!x.fail());
    ofstream y = openOutputfile("outP3.txt"); REQUIRE(!x.fail());
    ofstream z = openOutputfile("outM3.txt"); REQUIRE(!x.fail());
    valogat(x,y,z);

    int c;
    string str;

    ifstream f("outP3.txt");
    c = 0;
    while(getline(f,str)) ++c;
    CHECK(1==c);

    ifstream g("outM3.txt");
    c = 0;
    while(getline(g,str)) ++c;
    CHECK(1==c);
}

TEST_CASE("last", "inp4.txt")
{
    ifstream x = openInputfile( "inp4.txt");  REQUIRE(!x.fail());
    ofstream y = openOutputfile("outP4.txt"); REQUIRE(!x.fail());
    ofstream z = openOutputfile("outM4.txt"); REQUIRE(!x.fail());
    valogat(x,y,z);

    int c;
    string str;

    ifstream f("outP4.txt");
    c = 0;
    while(getline(f,str)) ++c;
    CHECK(1==c);

    ifstream g("outM4.txt");
    c = 0;
    while(getline(g,str)) ++c;
    CHECK(1==c);
}

#endif
