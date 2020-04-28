#include "hunter.h"
#include "fstream"

using namespace std;

Hunter::Hunter(string filename)
{
    ifstream x;
    if(x.open())throw WRONG_FILENAME

    x>>name>>age;

    string spieces, spot, date, special1, special2;
    int weight;

    while(x>>spieces>>spot>>date>>weight)
    {

        if("lion"==spieces)
        {
            x>>special1;
            trophies.push_back(new Lion(spot, date, special1));
        }
        else if("elephant"==spieces)
        {
            x>>special1>>special2;
            trophies.push_back(new Elephant(spot, date, special1,special2));
        }
        else if("rhino"==spieces)
        {
            x>>special1;
            trophies.push_back(new Rhino(spot, date, special1));
        }
        else throw UNEXPECTED_SPIECES
    }
}

int Hunter::MaleLionTrophyCount()
{
    _count = 0;
    for(auto i:trophies)
    {
        if("lion"==i.spieces && "male"==i.getSpecialAttribute)
        {
            _count++;
        }
    }
    return _count;
}
