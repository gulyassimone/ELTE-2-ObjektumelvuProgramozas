//Author:   Gregorics Tibor
//Date:     2017.12.15.
//Title:    competition of creatures (with design patterns)

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include "creature.h"

using namespace std;

//Activity: Populating creaturess and creating a court based on a textfile,
//          simulating the competition and writing the result,
//          destroying the dynamic objects
int main()
{
    ifstream f("inp.txt");
    if(f.fail()) { cout << "Wrong file name!\n"; return 1;}

    // populating creatures
    int n; f >> n;
    vector<Creature*> creatures(n);
    for( int i=0; i<n; ++i ){
        char ch; string name; int p;
        f >> ch >> name >> p;
        switch(ch){
            case 'G' : creatures[i] = new Greenfinch(name, p); break;
            case 'D' : creatures[i] = new DuneBeetle(name, p); break;
            case 'S' : creatures[i] = new Squelchy(name, p);   break;
        }
    }

    // populating courts
    int m; f >> m;
    vector<Ground*> courts(m);
    for( int j=0; j<m; ++j ) {
        int k; f >> k;
        switch(k){
            case 0 : courts[j] = new Sand;  break;
            case 1 : courts[j] = new Grass; break;
            case 2 : courts[j] = new Marsh; break;
        }
    }

    // Competition
    try{
    for( int i=0; i < n; ++i ){
        for( int j=0; creatures[i]->alive() && j < m; ++j ){
            creatures[i]->transmute(courts[j]);
        }
        if (creatures[i]->alive() ) cout << creatures[i]->name() << endl;
    }
    }catch(exception e){
        cout << e.what() << endl;
    }

   // destroying creatures
    for(int i=0; i<n; ++i) delete creatures[i];

   // destroying courts
    for(int j=0; j<m; ++j) delete courts[j];

   return 0;
}
