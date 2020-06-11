#include <iostream>
#include "angler.h"
#include "contest.h"
#include <sstream>

using namespace std;


angler firstQuestion(string filename)
{
    Angler t(filename);
    angler winner;
    winner.isCatfish=false;

    for(t.first(); !t.end(); t.next())
    {
        if(! t.current().isCatfish) ;
        else if( t.current().isCatfish && winner.isCatfish)
        {
            if(winner.sizeOfFish<t.current().sizeOfFish)
            {
                winner.anglerId=t.current().anglerId;
                winner.contestId=t.current().contestId;
                winner.sizeOfFish=t.current().sizeOfFish;
            }
        }
        else if(t.current().isCatfish && !winner.isCatfish)
        {
            winner.anglerId=t.current().anglerId;
            winner.contestId=t.current().contestId;
            winner.isCatfish=true;
            winner.sizeOfFish=t.current().sizeOfFish;
        }
    }
    return winner;
}
string secondQuestion(string filename)
{
    Contest t(filename);
    string contestIds;
    t.first();
    while(  !t.end())
    {
        if(t.current().isCatfish&&t.current().isNotCatfish)
        {
            contestIds += t.current().contestId + " ";

        }
        t.next();
    }
    return contestIds;
}
//#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    try
    {

        string filename = "inp.txt";
        angler winner;
        winner = firstQuestion(filename);

        cout << "A legnagyobb harcsa fogó dij nyertese: " << endl;
        if (!winner.isCatfish)
        {
            cout << "Nincs olyan, aki fogott harcsát" << endl;

        }
        else
        {
            cout << winner << endl;
        }
        string contestIds = secondQuestion(filename);
        cout << "Azok a vesenyek, ahol fogtak harcsát is: "<< endl;
        cout << (contestIds.length()==0?"Nem volt ilyen veseny":contestIds)<<endl;
    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("first task empty file", "inp0.txt")
{

    try
    {
        angler winner = firstQuestion("inp0.txt");
        CHECK_FALSE(winner.isCatfish);

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("first task 1 angler", "inp1.txt")
{

    try
    {
        angler winner = firstQuestion("inp1.txt");
        CHECK (winner.anglerId=="JANIBÁ");

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("first task 2 angler", "inp2.txt")
{

    try
    {
        angler winner = firstQuestion("inp2.txt");
        CHECK (winner.anglerId=="ANNA");

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("first task 3 angler", "inp3.txt")
{

    try
    {
        angler winner = firstQuestion("inp3.txt");
        CHECK (winner.anglerId=="JANIBÁ");

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("first task first catch", "inp1.txt")
{

    try
    {
        angler winner = firstQuestion("inp1.txt");
        CHECK (winner.anglerId=="JANIBÁ");

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("first task last catch ", "inp4.txt")
{

    try
    {
        angler winner = firstQuestion("inp1.txt");
        CHECK (winner.anglerId=="JANIBÁ");

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("first task exists winner ", "inp4.txt")
{

    try
    {
        angler winner = firstQuestion("inp1.txt");
        CHECK (winner.anglerId=="JANIBÁ");

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("first task not exists winner ", "inp5.txt")
{

    try
    {
        angler winner = firstQuestion("inp5.txt");
        CHECK_FALSE(winner.isCatfish);

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("first task exists more winner ", "inp6.txt")
{

    try
    {
        angler winner = firstQuestion("inp6.txt");
        CHECK (winner.anglerId=="ANNA");


    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("first task exists angler with no catch", "inp7.txt")
{

    try
    {
        angler winner = firstQuestion("inp7.txt");
        CHECK (winner.anglerId=="JANIBÁ");


    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("first task exists angler with one catch", "inp7.txt")
{

    try
    {
        angler winner = firstQuestion("inp7.txt");
        CHECK (winner.anglerId=="JANIBÁ");


    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("first task exists angler with more catch", "inp7.txt")
{

    try
    {
        angler winner = firstQuestion("inp7.txt");
        CHECK (winner.anglerId=="JANIBÁ");


    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("first task first winner", "inp1.txt")
{

    try
    {
        angler winner = firstQuestion("inp1.txt");
        CHECK (winner.anglerId=="JANIBÁ");

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("first task last winner ", "inp4.txt")
{

    try
    {
        angler winner = firstQuestion("inp1.txt");
        CHECK (winner.anglerId=="JANIBÁ");

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("first task more winner ", "inp8.txt")
{

    try
    {
        angler winner = firstQuestion("inp8.txt");
        CHECK (winner.anglerId=="ANNA");

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("Second task empty file", "inp0.txt")
{

    try
    {
        string contestIds = secondQuestion("inp0.txt");
        CHECK(0==contestIds.length());
    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("Second task 1 contest", "inp1.txt")
{

    try
    {
        string contestIds = secondQuestion("inp1.txt");
        CHECK ("Kiliti0512 "==contestIds);

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Second task 2 contest", "inp2.txt")
{

    try
    {
        string contestIds = secondQuestion("inp2.txt");
        CHECK ("Pilicsi0530 "==contestIds);

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Second task 3 contest", "inp3.txt")
{

    try
    {
        string contestIds = secondQuestion("inp3.txt");
        CHECK ("Kiliti0512 "==contestIds);

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Second task first contest with cat fish", "inp3.txt")
{

    try
    {
        string contestIds = secondQuestion("inp3.txt");
        CHECK ("Kiliti0512 "==contestIds);

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Second task last contest with cat fish", "inp4.txt")
{

    try
    {
        string contestIds = secondQuestion("inp4.txt");
        CHECK ("Kiliti0512 "==contestIds);

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Second task exists contest with cat fish", "inp4.txt")
{

    try
    {
        string contestIds = secondQuestion("inp4.txt");
        CHECK ("Kiliti0512 "==contestIds);

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Second task not exists contest with cat fish", "inp5.txt")
{

    try
    {
        string contestIds = secondQuestion("inp5.txt");
        CHECK(0==contestIds.length());

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Second task an angler with no catch", "inp7.txt")
{

    try
    {
        string contestIds = secondQuestion("inp7.txt");
        CHECK("Kiliti0512 Pilicsi0530 "==contestIds);

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Second task an angler with one catch", "inp7.txt")
{

    try
    {
        string contestIds = secondQuestion("inp7.txt");
        CHECK("Kiliti0512 Pilicsi0530 "==contestIds);

    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Second task an angler with two catch", "inp7.txt")
{

    try
    {
        string contestIds = secondQuestion("inp7.txt");
        CHECK("Kiliti0512 Pilicsi0530 "==contestIds);
    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("Second task more content", "inp7.txt")
{

    try
    {
        string contestIds = secondQuestion("inp7.txt");
        CHECK("Kiliti0512 Pilicsi0530 "==contestIds);
    }
    catch(Angler::error err)
    {
        if(err==Angler::FILE_NAME_ERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
#endif

