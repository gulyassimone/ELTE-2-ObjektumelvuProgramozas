#include "hunter.h"
#include <iostream>
#include "fstream"

using namespace std;

Hunter::Hunter(string filename)
{
    ifstream x;
    x.open(filename);
    if(x.fail())
        throw WRONG_FILENAME;

    x>>name>>age;

    string spieces, spot, date, special1;
    int weight, special2, special3;


    while(x>>spieces>>spot>>date>>weight)
    {
        if("lion"==spieces)
        {
            x>>special1;
            lionTrophies.push_back(new Lion(spieces, spot, date, weight, special1));
        }
        else if("elephant"==spieces)
        {
            x>>special2>>special3;
            IvoryLength ivoryLength(special2, special3);

            elephantTrophies.push_back(new Elephant(spieces, spot, date, weight, ivoryLength));
        }
        else if("rhino"==spieces)
        {
            x>>special2;
            rhinoTrophies.push_back(new Rhino(spieces, spot, date, weight, special2));
        }
        else
            throw UNEXPECTED_SPIECES;
        }
        if(x.fail() && !x.eof()) throw UNEXPECTED_DATA;
}

int Hunter::MaleLionTrophiesCount()
{
    int _count = 0;
    for(auto i:lionTrophies)
    {
        if("male"==i->getSpecialAttribute())
        {
            _count++;
        }
    }
    return _count;
}
