// ------------------------------------------------------
// ex14_10.cpp
// Testet die Klasse RGB_Color.
// ------------------------------------------------------
#include "color.h"
#include <iostream>
using namespace std;

int main()
{
    const RGB_Color cyan(0,255,255),
                    yellow(255,255,0),
                    magenta(255,0,255);

    cout << "Tuerkis:" << endl; 
    cyan.display();
    cout << "Gelb:" << endl; 
    yellow.display();
    cout << "Magenta:" << endl; 
    magenta.display();

    RGB_Color myColor;
    cout << "Meine Lieblingsfarbe:" << endl; 
    myColor.setR(128);
    myColor.display();

    myColor.chooseColor();
    myColor.display();
    return 0;

}
