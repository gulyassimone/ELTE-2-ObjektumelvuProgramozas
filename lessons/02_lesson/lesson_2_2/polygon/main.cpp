//Author:   Gregorics Tibor
//Date:     2017.12.15.
//Title:    Moving polygons and computing their center (type-oriented version)

#include <iostream>
#include <fstream>
#include <vector>
#include "polygon.h"
#include "point.h"

using namespace std;

//Activity:  Creating polygons based on a textfile,
//           moving them and then computing their center,
int main()
{
    cout << "file name: "; string fn; cin>> fn;
    ifstream inp(fn);
    if(inp.fail()) { cout << "File open error\n"; exit(1);}

    int n; inp >> n;
    vector<Polygon*> t(n);
    for ( int i=0; i<n; ++i ) t[i] = Polygon::create(inp);

    int x, y; inp >> x >> y;
    Point mp(x, y);

    for ( Polygon* p : t ){
        p->move(mp);
        cout << p << endl;
        cout << p->center() << endl;
    }

//    for ( Polygon* p : t ) delete p;
    return 0;
}

