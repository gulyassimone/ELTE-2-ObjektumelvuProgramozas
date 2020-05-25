#include <iostream>
#include <fstream>

#include "enor.h"

using namespace std;

int main()
{
    Enor t("input.txt");

    ofstream y("output.txt");

    for(t.first(); !t.end(); t.next())
    {
        if(t.current().egy<-100000)
        {
            y << t.current().szaml << " " << t.current().egy << endl;
        }
    }

    return 0;
}
