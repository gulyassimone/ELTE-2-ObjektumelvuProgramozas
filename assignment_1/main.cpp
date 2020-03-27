//Author:   Gulyás Simone
//Date:     2020.03.09
//Title:    N matrix
#include <iostream>

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE
#include "menu.h"



int main()
{
    Menu menu;
    menu.run();
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include <fstream>
#include "catch.hpp"
#include "matrix.h"
#include "read.hpp"



TEST_CASE("create", "")
{
    Matrix b;
    ifstream y("inp1.txt");
    REQUIRE(!y.fail());
    y>>b;
    CHECK(b.write(0,0)==1);


    Matrix c;
    ifstream z("inp2.txt");
    REQUIRE(!z.fail());
    z>>c;
    CHECK(c.write(0,0)==1);
    CHECK(c.write(0,1)==0);
    CHECK(c.write(0,2)==1);
    CHECK(c.write(1,0)==1);
    CHECK(c.write(1,1)==1);
    CHECK(c.write(1,2)==1);
    CHECK(c.write(2,0)==1);
    CHECK(c.write(2,1)==0);
    CHECK(c.write(2,2)==1);

    Matrix d;
    ifstream v("inp3.txt");
    REQUIRE(!v.fail());
    v>>d;
    CHECK(d.write(0,0)==1);
    CHECK(d.write(0,1)==0);
    CHECK(d.write(0,2)==0);
    CHECK(d.write(0,3)==0);
    CHECK(d.write(0,4)==1);
    CHECK(d.write(1,0)==1);
    CHECK(d.write(1,1)==1);
    CHECK(d.write(1,2)==0);
    CHECK(d.write(1,3)==0);
    CHECK(d.write(1,4)==1);
    CHECK(d.write(2,0)==1);
    CHECK(d.write(2,1)==0);
    CHECK(d.write(2,2)==1);
    CHECK(d.write(2,3)==0);
    CHECK(d.write(2,4)==1);
    CHECK(d.write(3,0)==1);
    CHECK(d.write(3,1)==0);
    CHECK(d.write(3,2)==0);
    CHECK(d.write(3,3)==1);
    CHECK(d.write(3,4)==1);
    CHECK(d.write(4,0)==1);
    CHECK(d.write(4,1)==0);
    CHECK(d.write(4,2)==0);
    CHECK(d.write(4,3)==0);
    CHECK(d.write(4,4)==1);
}
TEST_CASE("getting and changing an element of the matrix", "")
{
    Matrix b;
    ifstream y("inp1.txt");
    REQUIRE(!y.fail());
    y>>b;
    CHECK(b.write(0,0) == 1);
    b.setElemValue(0,0,9);
    CHECK(b.write(0,0) == 9);
}

TEST_CASE("copy constructor", "inp2.txt")
{
    Matrix b;
    ifstream y("inp2.txt");
    REQUIRE(!y.fail());
    y>>b;

    Matrix a = b;

    CHECK(a.write(0,1)==0);
    CHECK(a.write(0,0)==1);
    CHECK(a.write(0,2)==1);
    CHECK(a.write(1,0)==1);
    CHECK(a.write(1,1)==1);
    CHECK(a.write(1,2)==1);
    CHECK(a.write(2,0)==1);
    CHECK(a.write(2,1)==0);
    CHECK(a.write(2,2)==1);
}

TEST_CASE("add", "inp0.txt inp4.txt inp5.txt")
{
    Matrix a,b,c,d,f,z;
    ifstream xd("inp0.txt");
    REQUIRE(!xd.fail());
    xd>>a;
    ifstream yd("inp4.txt");
    REQUIRE(!yd.fail());
    yd>>b;
    ifstream zd("inp5.txt");
    REQUIRE(!zd.fail());
    zd>>z;

    c = a + b;
    CHECK(c.write(0,0)==7);
    CHECK(c.write(0,1)==0);
    CHECK(c.write(0,2)==6);
    CHECK(c.write(1,0)==8);
    CHECK(c.write(1,1)==8);
    CHECK(c.write(1,2)==7);
    CHECK(c.write(2,0)==13);
    CHECK(c.write(2,1)==0);
    CHECK(c.write(2,2)==10);

    d = b + a;
    CHECK(d.write(0,0)==c.write(0,0));
    CHECK(d.write(0,1)==c.write(0,1));
    CHECK(d.write(0,2)==c.write(0,2));
    CHECK(d.write(1,0)==c.write(1,0));
    CHECK(d.write(1,1)==c.write(1,1));
    CHECK(d.write(1,2)==c.write(1,2));
    CHECK(d.write(2,0)==c.write(2,0));
    CHECK(d.write(2,1)==c.write(2,1));
    CHECK(d.write(2,2)==c.write(2,2));

    d = (a + b) + c;
    f = a + (b + c);
    CHECK(d.write(0,0)==f.write(0,0));
    CHECK(d.write(0,1)==f.write(0,1));
    CHECK(d.write(0,2)==f.write(0,2));
    CHECK(d.write(1,0)==f.write(1,0));
    CHECK(d.write(1,1)==f.write(1,1));
    CHECK(d.write(1,2)==f.write(1,2));
    CHECK(d.write(2,0)==f.write(2,0));
    CHECK(d.write(2,1)==f.write(2,1));
    CHECK(d.write(2,2)==f.write(2,2));

    c = a + z;
    CHECK(c.write(0,0)==a.write(0,0));
    CHECK(c.write(0,1)==a.write(0,1));
    CHECK(c.write(0,2)==a.write(0,2));
    CHECK(c.write(1,0)==a.write(1,0));
    CHECK(c.write(1,1)==a.write(1,1));
    CHECK(c.write(1,2)==a.write(1,2));
    CHECK(c.write(2,0)==a.write(2,0));
    CHECK(c.write(2,1)==a.write(2,1));
    CHECK(c.write(2,2)==a.write(2,2));
}

TEST_CASE("multiply", "inp0.txt inp4.txt inp5.txt")
{
    Matrix a,b,c,z;
    ifstream xd("inp0.txt");
    REQUIRE(!xd.fail());
    xd>>a;
    ifstream yd("inp4.txt");
    REQUIRE(!yd.fail());
    yd>>b;
    ifstream zd("inp5.txt");
    REQUIRE(!zd.fail());
    zd>>z;

    c = a * b;
    CHECK(c.write(0,0)==45);
    CHECK(c.write(0,1)==0);
    CHECK(c.write(0,2)==45);
    CHECK(c.write(1,0)==23);
    CHECK(c.write(1,1)==12);
    CHECK(c.write(1,2)==22);
    CHECK(c.write(2,0)==26);
    CHECK(c.write(2,1)==0);
    CHECK(c.write(2,2)==22);

    c = a * z;
    CHECK(c.write(0,1)==0);
    CHECK(c.write(0,0)==0);
    CHECK(c.write(0,2)==0);
    CHECK(c.write(1,0)==0);
    CHECK(c.write(1,1)==0);
    CHECK(c.write(1,2)==0);
    CHECK(c.write(2,0)==0);
    CHECK(c.write(2,1)==0);
    CHECK(c.write(2,2)==0);
}

TEST_CASE("exceptions", "")
{

    Matrix a;
    ifstream xd("inp0.txt");
    REQUIRE(!xd.fail());
    xd>>a;

    try
    {
        a.setElemValue(3,3,4);
    }
    catch(Matrix::matrixError ex)
    {
        CHECK(ex == Matrix::OVERINDEXED);
    }

    try
    {
        a.setElemValue(-1,3,4);
    }
    catch(Matrix::matrixError ex)
    {
        CHECK(ex == Matrix::OVERINDEXED);
    }

    Matrix b,c,d;
    ifstream y("inp1.txt");
    REQUIRE(!y.fail());
    y>>b;


    ifstream z("inp2.txt");
    REQUIRE(!z.fail());
    z>>c;

    try
    {
        d = b + c;
    }
    catch(Matrix::matrixError ex)
    {
        CHECK(ex == Matrix::INVALID_OPERATION);
    }

    try
    {
       d = b * c;
    }
    catch(Matrix::matrixError ex)
    {
        CHECK(ex == Matrix::INVALID_OPERATION);
    }

    try
    {
        c.setElemValue(0,1,4);
    }
    catch(Matrix::matrixError ex)
    {
        CHECK(ex == Matrix::NULLPART);
    }

}
#endif
