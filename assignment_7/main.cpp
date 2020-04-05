#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    bool sugarMeter=false;
    Enor t("inp.txt");

    for(t.first(); !t.end() ; t.next())
    {
        sugarMeter = sugarMeter || t.current().needsSugar;
    }
    cout << (sugarMeter? "Every recipe needs sugar" : "Every recipe no needs sugar") << endl;
    return 0;
}
