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
    vector<AirStratum*> airStratum;
    for(int i=0; i<n; i++)
    {
        char ch;
        int s;
        f >> ch >> s;
        switch(ch)
        {
        case 'x' :
            airStratum[i] = new Oxygen(s);
            break;
        case 'z' :
            airStratum[i] = new Ozone(s);
            break;
        case 's' :
            airStratum[i] = new CarbonDioxide(s);
            break;
        }
    }
//Populating weather
    string m;
    vector<Weather*> weather;
    for(unsigned i=0; i<m.length(); i++)
    {
        switch(m[i])
        {
        case 'm' :
            weather[i] = new Else;
            break;
        case 'z' :
            weather[i] = new Rain;
            break;
        case 'n' :
            weather[i] = new Sunny;
            break;
        }
    }
//Simulation
    try
    {
        for(int i=0; i<n; i++)
        {
            int j=0;
            while(airStratum[i]->remaining())
            {
                weather[i]->transmute(airStratum[j]);

                if(airStratum[i]->remaining())
                    cout << airStratum[j]->getName() << " " <<  endl;
                j++;
                if(j==m.length())
                {
                    j==0;
                }
            }
        }
    }
    catch(exception e)
    {
        cout << e.what() << endl;
    }
//destroying air-stratum
    for(int i=0; i<n; i++)
        delete airStratum[i];
//destroying weather
    for(int i=0; i<m.length(); i++)
        delete weather[i];


    return 0;
}
