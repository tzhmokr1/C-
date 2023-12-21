// --------------------------------------------------------------
// ex14_08.cpp
// Münzen werden in zwei Sparschweine geworfen und anschließend
// die Gewichte der Sparschweine mit der Methode compareWeight()
// verglichen.
// --------------------------------------------------------------
#include "piggyBank.h"
#include <iostream>
using namespace std;

void showCoins(unsigned int c1, unsigned int c10, unsigned int c50, unsigned int e1)
{
    if( c1  > 0)  cout << c1  << " 1-Cent Muenzen"  << endl;
    if( c10  > 0) cout << c10 << " 10-Cent Muenzen" << endl;
    if( c50 > 0)  cout << c50 << " 50-Cent Muenzen" << endl;
    if( e1 > 0)   cout << e1  << " 1-Euro Muenzen"  << endl;
}

int main()
{
    unsigned int  c1=0, c10=0, c50=0, e1=0;
    unsigned long cents = 0;

    PiggyBank myPiggy(100), yourPiggy(100);

    // Einige Münzen einwerfen:
    c1=5, c10=0, c50=30, e1=20;
    cout << "Ich werfe diese Muenzen in mein Sparschwein:" << endl;
    showCoins( c1, c10, c50, e1);
    if( !myPiggy.addCoins( c1, c10, c50, e1))
    {
       cout << "Mein Sparschwein ist voll!\n"
            << "Diese Muenzen passten nicht in mein Sparschwein:" << endl;
       showCoins( c1, c10, c50, e1);
       return 0;
    }

    c1=0, c10=11, c50=22, e1=17;
    cout << "\nDu wirfst diese Muenzen in Dein Sparschwein:" << endl;
    showCoins( c1, c10, c50, e1);
    if( !yourPiggy.addCoins( c1, c10, c50, e1))
    {
       cout << "Dein Sparschwein ist voll!\n"
            << "Diese Muenzen passten nicht in Dein Sparschwein:" << endl;
       showCoins( c1, c10, c50, e1);
    }

    cout << "\nVergleichen wir beide Gewichte!" << endl;
    if( myPiggy.isLighterThan( yourPiggy) )
       cout << "\nMein Sparschwein ist leichter!" << endl;
    else
       cout << "\nDein Sparschwein ist leichter!" << endl;

    return 0;
}
