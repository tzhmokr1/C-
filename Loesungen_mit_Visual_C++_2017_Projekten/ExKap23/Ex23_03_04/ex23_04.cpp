// ------------------------------------------------------
// ex23_04.cpp
// Klasse Circle verwenden.
// ------------------------------------------------------

#include "shape2D.h"

int main()
{
    Circle kreis( 0.0, 0.0, 1.0);

    kreis.print();

    kreis.setX(1.0);
    kreis.move(0.5, -1.2);     // Verschieben
    kreis.setRadius(2.5);      // Neuer Radius
    kreis.print();

    return 0;
}
