#include <iostream>
#include <fstream>

using namespace std;

struct Bank
{
    string azon;
    int egy;
};

enum Errors { WRONG_FILE_NAME };

ifstream openInputfile(const string &fnev);
ofstream openOutputfile(const string &fnev);
void feltetelesMin(ifstream &f, ofstream &y);

ifstream openInputfile(const string &fnev)
{
    ifstream f(fnev.c_str());
    if(f.fail())
        throw WRONG_FILE_NAME;
    return f;
}
ofstream openOutputfile(const string &fnev)
{
    ofstream f(fnev.c_str());
    if(f.fail())
        throw WRONG_FILE_NAME;
    return f;
}

void feltetelesMin(ifstream &x, ofstream &y)
{
    Bank e;
    bool l=false;
    int min;
    string azon;
    while(x >> e.azon >> e.egy )
    {
        if(e.egy<0)
        {

        }
        else if(l && e.egy>=0)
        {
            if(e.egy<min)
            {
                azon=e.azon;
                min=e.egy;
            }
        }
        else if(!l && e.egy>=0)
        {
            l=true;
            azon=e.azon;
            min=e.egy;
        }
    }
    if(l)
    {
        y << azon << endl;
    }
}

//#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    try
    {
        ifstream x = openInputfile("input.txt");;
        ofstream y = openOutputfile("azon.txt");
        feltetelesMin(x, y);
    }
    catch(Errors er)
    {
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
    feltetelesMin(x,y);

    int c;
    string str;

    ifstream f("outP0.txt");
    c = 0;
    while(getline(f,str)) ++c;
    CHECK(0==c);
}

TEST_CASE("one", "inp1.txt")
{
    ifstream x = openInputfile( "inp1.txt");  REQUIRE(!x.fail());
    ofstream y = openOutputfile("outP1.txt"); REQUIRE(!x.fail());
    feltetelesMin(x,y);

    string str;

    ifstream f("outP1.txt");
    while(getline(f,str));
    CHECK(str.compare("1"));
}

TEST_CASE("two", "inp2.txt")
{
    ifstream x = openInputfile( "inp2.txt");  REQUIRE(!x.fail());
    ofstream y = openOutputfile("outP2.txt"); REQUIRE(!x.fail());
    feltetelesMin(x,y);

    string str;

    ifstream f("outP2.txt");
    while(getline(f,str));
    CHECK(str.compare("2"));
}

TEST_CASE("first", "inp3.txt")
{
    ifstream x = openInputfile( "inp3.txt");  REQUIRE(!x.fail());
    ofstream y = openOutputfile("outP3.txt"); REQUIRE(!x.fail());
    feltetelesMin(x,y);

    string str;

    ifstream f("outP3.txt");
    while(getline(f,str));
    CHECK(str.compare("3"));
}

TEST_CASE("before last", "inp4.txt")
{
    ifstream x = openInputfile( "inp4.txt");  REQUIRE(!x.fail());
    ofstream y = openOutputfile("outP4.txt"); REQUIRE(!x.fail());
    feltetelesMin(x,y);


    string str;

    ifstream f("outP4.txt");
    while(getline(f,str));
    CHECK(str.compare("4"));

}

TEST_CASE("last", "inp4.txt")
{
    ifstream x = openInputfile( "inp4.txt");  REQUIRE(!x.fail());
    ofstream y = openOutputfile("outP5.txt"); REQUIRE(!x.fail());
    feltetelesMin(x,y);


    string str;

    ifstream f("outP5.txt");
    while(getline(f,str));
    CHECK(str.compare("5"));

}

#endif


