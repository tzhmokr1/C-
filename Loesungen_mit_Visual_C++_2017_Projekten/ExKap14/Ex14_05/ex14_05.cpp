// ------------------------------------------------------
// ex14_05.cpp
// Objekte der Klasse Random verwenden.
// ------------------------------------------------------
#include "random.h"
#include <iostream>
using namespace std;

int main()
{
    Random luckynumber;      // Default-Konstruktor
    Random balance(1000);    // Konstruktor mit einem Parameter
    Random lottery(1, 49);   // Konstruktor zwei Parametern
    int i = 0;

    cout << "\nZufallszahlen im Bereich von 0 bis " << RAND_MAX << endl;
    for( i = 0; i < 6; ++i)
        cout << luckynumber.random() << "  ";
    cout << endl;    

    cout << "\nZufallszahlen im Bereich von  -1000 bis 1000" << endl;
    for( i = 0; i < 6; ++i)
        cout << balance.random() << "  ";
    cout << endl;

    cout << "\nZufallszahlen im Bereich von  1 bis 49" << endl;
    for( i = 0; i < 6; ++i)
        cout << lottery.random() << "  ";
    cout << endl;    

    return 0;
}
