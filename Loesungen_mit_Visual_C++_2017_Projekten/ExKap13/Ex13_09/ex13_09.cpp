// ------------------------------------------------------
// ex13_09.cpp
// Definiert und testet die Struktur Point. 
// ------------------------------------------------------
#include <iostream>
using namespace std;

struct Point { double x, y; };
void printPoint( Point &p)
{
    cout << '(' << p.x << ", " << p.y << ')';
}

int main()
{
    Point p1 = { -1.1, 3.5},
          p2 = { 2.4, -0.7};

    double m = 0.0, c = 0.0,
           dx = p2.x - p1.x, dy = p2.y - p1.y;

    cout << "\nErster Punkt:  P1 = ";  printPoint(p1);
    cout << "\nZweiter Punkt: P2 = ";  printPoint(p2);
    cout << endl;

    if( dx == 0)
       cout << "\nDie Gerade durch beide Punkte"
               " P1 und P2 ist eine senkrechte Linie."
            << endl;
    else
    {
       double m = dy/dx,
              c = p1.y - m * p1.x;

       cout << "\nFuer die Gerade y = m*x + c \n"
               "durch beide Punkte P1 und P2 gilt:\n"
            << "m = " << m << "  und c = " << c << endl;
    }
    return 0;
}
