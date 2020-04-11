#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Result
{
    string anglerID;
    string competetiveID;
    string fish;
    int sizeOfFish;
};

enum Status {abnorm, norm};

bool read(ifstream &f, Result &e, Status &st);

int main()
{
    ifstream x("inp1.txt");
    if (x.fail() )
    {
        cout << "hibas fajlnev!\n";
        return 1;
    }

    Result dx;
    Status sx;
    dx.sizeOfFish=0;
    while(read(x,dx,sx));
    cout << "The best Fisherman : " << dx.anglerID << " and where the miracle happened:"<< dx.anglerID << endl;
    return 0;
}

bool read(ifstream &f, Result &e, Status &st)
{
    string line;
    getline(f,line);
    if (!f.fail() && line!="")
    {
        st = norm;
        istringstream in(line);

        string anglerID, competetiveID, fish;
        int sizeOfFish;

        while( in >> anglerID >> competetiveID >> fish >> sizeOfFish )
        {
            if(e.sizeOfFish<sizeOfFish)
            {
                e.anglerID=anglerID;
                e.competetiveID=competetiveID;
                e.fish=fish;
                e.sizeOfFish=sizeOfFish;
            }
        };
    }
    else
        st=abnorm;

    return norm==st;
}
