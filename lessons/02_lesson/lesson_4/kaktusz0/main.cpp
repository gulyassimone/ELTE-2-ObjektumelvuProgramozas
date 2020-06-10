#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    bool err=false;
    ifstream x("inp.txt");      if(x.fail()) { cout << "Rossz fajlnev!\n"; err=true; }
    ofstream y("outpiros.txt"); if(y.fail()) { cout << "Rossz fajlnev!\n"; err=true; }
    ofstream z("outmexico.txt");if(z.fail()) { cout << "Rossz fajlnev!\n"; err=true; }
    if(err) return 1;

    string nev, os, szin;
    while(x >> nev >> os >> szin){
        if( "piros" == szin)  y << nev << endl;
        if( "mexico"== os)    z << nev << endl;
    }
    return 0;
}
