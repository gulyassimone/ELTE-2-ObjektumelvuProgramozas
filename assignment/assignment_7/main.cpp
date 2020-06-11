#include <iostream>
#include "enor.h"

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    try
    {
        bool sugarMeter=true;
        Enor t("inp2.txt");

        for(t.first(); sugarMeter && !t.end() ; t.next())
        {
            sugarMeter = t.current().needsSugar;
        }
        cout << (sugarMeter? "Every recipe needs sugar" : "Not all recipes need sugar.") << endl;

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("empty", "inp0.txt")
{

    try
    {
        bool sugarMeter=true;
        Enor t("inp0.txt");
        int c=0;

        for(t.first(); sugarMeter && !t.end() ; t.next())
        {
            c++;
        }

        CHECK(0==c);

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("firsttrue", "inp1.txt")
{

    try
    {
        bool sugarMeter=true;
        Enor t("inp1.txt");

        for(t.first(); sugarMeter && !t.end() ; t.next())
        {
            sugarMeter =  t.current().needsSugar;
        }

        CHECK(sugarMeter==true);

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("middletrue", "inp2.txt")
{

    try
    {
        bool sugarMeter=true;
        Enor t("inp2.txt");

        for(t.first(); sugarMeter && !t.end() ; t.next())
        {
            sugarMeter =  t.current().needsSugar;
        }

        CHECK(sugarMeter==true);

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("lasttrue", "inp3.txt")
{

    try
    {
        bool sugarMeter=true;
        Enor t("inp3.txt");

        for(t.first(); sugarMeter && !t.end() ; t.next())
        {
            sugarMeter =  t.current().needsSugar;
        }

        CHECK(sugarMeter==true);

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("firstfalse", "inp4.txt")
{

    try
    {
        bool sugarMeter=true;
        Enor t("inp4.txt");

        for(t.first(); sugarMeter && !t.end() ; t.next())
        {
            sugarMeter = t.current().needsSugar;

        }

        CHECK(sugarMeter==false);

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("midlefalse", "inp5.txt")
{

    try
    {
        bool sugarMeter=true;
        Enor t("inp5.txt");

        for(t.first(); sugarMeter && !t.end() ; t.next())
        {
            sugarMeter = t.current().needsSugar;
        }

        CHECK(sugarMeter==false);

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("lastfalse", "inp6.txt")
{

    try
    {
        bool sugarMeter=true;
        Enor t("inp6.txt");

        for(t.first(); sugarMeter && !t.end() ; t.next())
        {
            sugarMeter = t.current().needsSugar;
        }

        CHECK(sugarMeter==false);

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("exception", "inp100.txt")
{

    try
    {
        bool sugarMeter=true;
        Enor t("inp100.txt");

        for(t.first(); sugarMeter && !t.end() ; t.next())
        {
            sugarMeter =  t.current().needsSugar;
        }

    }
    catch(Enor::Errors err)
    {
        CHECK(err==Enor::FILEERROR);
    }
}
#endif
