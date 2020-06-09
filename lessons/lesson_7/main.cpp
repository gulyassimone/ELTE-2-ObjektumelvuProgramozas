#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("inp.txt");
    bool l = true;
    for(t.first(); l && !t.end(); t.next() )
    {
        l=t.current();
    }

    cout << (l?"Mindenki lott medvet" : "Nem lott mindenki medvet.") << endl;
    return 0;
}
