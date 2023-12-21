// ----------------------------------------------------------
// ex15_10.cpp
// Testet die neue Klasse RGB_Color mit den Konstanten
// vom Typ ColorID.
// ---------------------------------------------------------- 
#include "color.h"
#include <iostream>
using namespace std;

int main()
{
    RGB_Color myColor(BLUE);
    cout << "Meine Lieblingsfarbe:" << endl; 
    myColor.display();

    cout << "\nFuer diese Farben sind Konstanten definiert:"
         << endl; 
    ColorID clr = BLACK;
    do
    {
        myColor.setColor(clr);
        myColor.display();
        clr = (ColorID)(clr+1);
    }
    while( clr <= LIGHT_GRAY);

    return 0;
}
