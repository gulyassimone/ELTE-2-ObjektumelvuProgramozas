//Author:   Gregorics Tibor
//Date:     2017.12.15.
//Title:    implementation of class of polygon

#include "polygon.h"
#include <iostream>

using namespace std;

//Task: 	moving a polygon
//Input:    Polygon this   -  polygon
//          Point mp       -  moving vector
//Output:   Polygon this   -  polygon
//Activity: moving of all vertices of the polygon
void Polygon::move(const Point &mp)
{
    for(unsigned int i = 0; i<_vertices.size(); ++i) {
        _vertices[i] = _vertices[i] + mp;
    }
}

//Task: 	computing the center of a polygon polygon
//Input:    Polygon this   -  polygon
//Output:   Polygon this   -  polygon
//Activity: computing the sum of the vertices of the polygon and dividing it by the number of the vertices
Point Polygon::center() const
{
    Point center;
    for(const Point &vertex : _vertices) { center = center + vertex; }
    center = center / sides();
    return center;
}

//Task: 	creating a polygon based on a textfile
//Input:    ifstream inp   -  textfile
//Output:   Polygon this   -  polygon
//Activity: constracting a polygon and setting coordinates of its vertices
Polygon* Polygon::create(ifstream &inp)
{
    Polygon *p;
    try{
        int sides;
        inp >> sides;
        p = new Polygon(sides);
        for( int i=0; i < sides; ++i ){
            int x, y;
            inp >> x >> y;
            p->_vertices[i].setPoint(x,y);
        }
    }catch(Polygon::Errors e){
        if( e==Polygon::FEW_VERTICES ) cout << " … ";
    }
    return p;
}

//Task: 	writing the vertices of a polygon
//Input:    ostream o   -  output adatfolyam
//          Polygon p   -  polygon
//Output:   ostream o   -  output adatfolyam
//Activity: writing coordinates of all vertices of the polygon
std::ostream& operator<<(std::ostream &out, const Polygon &p)
{
    out << "<";
    for( const Point& vertex : p._vertices ) {  out << vertex; }
    out << ">";
    return out;
}

