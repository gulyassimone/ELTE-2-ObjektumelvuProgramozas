#include <iostream>
#include <fstream>
#include <vector>
#include "airStratum.h"
#include "weather.h"

using namespace std;

int main()
{

    ifstream f("input.txt");
    if(f.fail())
    {
        cout << "Wrong file name!" << endl;
        return 1;
    }

//Populating air-Stratum
    int n;
    f>>n;
    cout << n << endl;
    vector<AirStratum*> airStratum;
    for(int i=0; i<n; i++)
    {
        char ch;
        int s;
        f >> ch >> s;
        switch(ch)
        {
        case 'x' :
            airStratum[i] = new Oxygen(ch,s);
            break;
        case 'z' :
            airStratum[i] = new Ozone(ch,s);
            break;
        case 's' :
            airStratum[i] = new CarbonDioxide(ch,s);
            break;
        }

    }

    for(int j=0;j<n;j++)
    {
        cout << airStratum[j]->getName() << " " << airStratum[j]->getSize()<< endl;
    }



    return 0;
}
