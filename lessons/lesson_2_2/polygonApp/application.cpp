//Author:   Gregorics Tibor
//Date:     2017.12.15.
//Title:    implementation of application class

#include "application.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Task: 	creating application with polygons
//Input:    textfile with data of polygons
//Output:   Application this   -  application
//Activity: creating an instance of Application
Application::Application(){
    cout << "file name: "; string fn; cin>> fn;
    ifstream inp(fn);
    if(inp.fail()) {
        cout << "File open error\n"; exit(1);
    }
    int n; inp >> n;
    t.resize(n);
    for(int i=0; i<n; ++i)
        t[i] = Polygon::create(inp);
    int x, y; inp >> x >> y;
    mp.setPoint(x, y);
}

//Task: 	destroying the application
//Input:    Application this   -  application
//Output:   -
//Activity: destroying the instance of Application
Application::~Application()
{
    for ( Polygon* p : t ) delete p;
}

//Task: 	running the application
//Input:    Application this   -  application
//Output:   Application this   -  application
//Activity: moving the polygons of the application and computing their center
//          and writing the results
void Application::run(){
    for ( Polygon* p : t ){
        p->move(mp);
        cout << *p << endl;
        cout << p->center() << endl;
    }
}

