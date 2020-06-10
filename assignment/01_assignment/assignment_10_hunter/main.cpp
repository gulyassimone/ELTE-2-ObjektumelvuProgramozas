#include <iostream>
#include "hunter.h"

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    try
    {

        Hunter hunter("inp.txt");
        cout<< hunter.getName() << " vadász " << hunter.MaleLionTrophiesCount() << " db oroszlánt ejtett el." << endl;
    }
    catch (Hunter::error err)
    {
        if(Hunter::WRONG_FILENAME==err)
        {
            cout << "Wrong filename!" << endl;
        }
        if(Hunter::UNEXPECTED_SPIECES==err)
        {
            cout << "Unexpected spieces!" << endl;
        }
        if(Hunter::UNEXPECTED_DATA==err)
        {
            cout << "Unexpected data!" << endl;
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

        Hunter hunter("inp0.txt");
        CHECK(0==hunter.MaleLionTrophiesCount());
    }
    catch (Hunter::error err)
    {
        if(Hunter::WRONG_FILENAME==err)
        {
            cout << "Wrong filename!" << endl;
        }
        if(Hunter::UNEXPECTED_SPIECES==err)
        {
            cout << "Unexpected spieces!" << endl;
        }
        if(Hunter::UNEXPECTED_DATA==err)
        {
            cout << "Unexpected data!" << endl;
        }
    }
}
TEST_CASE("Wrong filename error", "inp100.txt")
{

    try
    {
        Hunter hunter("inp100.txt");
    }
    catch (Hunter::error err)
    {
        CHECK(Hunter::WRONG_FILENAME==err);
    }
}
TEST_CASE("Unexpected spieces error", "inp1.txt")
{

    try
    {

        Hunter hunter("inp1.txt");
    }
    catch (Hunter::error err)
    {
        CHECK(Hunter::UNEXPECTED_SPIECES==err);
    }
}
TEST_CASE("Unexpected data error", "inp2.txt")
{

    try
    {

        Hunter hunter("inp2.txt");
    }
    catch (Hunter::error err)
    {
        CHECK(Hunter::UNEXPECTED_DATA==err);
    }
}
TEST_CASE("First is a lion", "inp3.txt")
{
    try
    {

        Hunter hunter("inp3.txt");
        CHECK(1==hunter.MaleLionTrophiesCount());
    }
    catch (Hunter::error err)
    {
        if(Hunter::WRONG_FILENAME==err)
        {
            cout << "Wrong filename!" << endl;
        }
        if(Hunter::UNEXPECTED_SPIECES==err)
        {
            cout << "Unexpected spieces!" << endl;
        }
        if(Hunter::UNEXPECTED_DATA==err)
        {
            cout << "Unexpected data!" << endl;
        }
    }
}
TEST_CASE("Last is a lion", "inp4.txt")
{
    try
    {

        Hunter hunter("inp4.txt");
        CHECK(3==hunter.MaleLionTrophiesCount());
    }
    catch (Hunter::error err)
    {
        if(Hunter::WRONG_FILENAME==err)
        {
            cout << "Wrong filename!" << endl;
        }
        if(Hunter::UNEXPECTED_SPIECES==err)
        {
            cout << "Unexpected spieces!" << endl;
        }
        if(Hunter::UNEXPECTED_DATA==err)
        {
            cout << "Unexpected data!" << endl;
        }
    }
}
TEST_CASE("Not exists male lion", "inp5.txt")
{
    try
    {

        Hunter hunter("inp5.txt");
        CHECK(0==hunter.MaleLionTrophiesCount());
    }
    catch (Hunter::error err)
    {
        if(Hunter::WRONG_FILENAME==err)
        {
            cout << "Wrong filename!" << endl;
        }
        if(Hunter::UNEXPECTED_SPIECES==err)
        {
            cout << "Unexpected spieces!" << endl;
        }
        if(Hunter::UNEXPECTED_DATA==err)
        {
            cout << "Unexpected data!" << endl;
        }
    }
}
#endif
