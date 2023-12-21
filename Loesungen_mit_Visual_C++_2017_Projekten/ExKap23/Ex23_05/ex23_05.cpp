// ------------------------------------------------------
// ex23_05.cpp
// Klassen Rectangle und Square verwenden.
// ------------------------------------------------------

#include "shape2D.h"

int main()
{
    Rectangle rect( -1.0, 1.0, 2.0, 1.0);
    Square sqr( 0.0, 0.0, 2.0);

    rect.print();
    cout << "Die Flaeche des Rechtecks: " << rect.getArea()
         << endl;

    sqr.print();
    cout << "Die Flaeche des Quadrats: " << sqr.getArea()
         << endl;

    sqr.move( 0.5, -2.1);                 // Verschieben
    cout << "Der neu Bezugspunkt des Quadrats: ";
    sqr.Shape2D::print();

    sqr.setSideLength(1.5);
    cout << "Die neue Seitenlaenge: " << sqr.getSideLength()
         << endl;
    cout << "Das Quadrat als Rechteck:\n";
    sqr.Rectangle::print();

    return 0;
}
