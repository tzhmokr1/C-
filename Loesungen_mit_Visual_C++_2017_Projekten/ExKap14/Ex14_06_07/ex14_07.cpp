// --------------------------------------------------------------
// ex14_07.cpp
// Testet die überladenen Methoden addCoins() der Klasse PiggyBank.
// ---------------------------------------------------------------
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
    PiggyBank myPiggy(100),
              yourPiggy(100);
    unsigned int  c1=0, c10=0, c50=0, e1=0;
    unsigned long cents = 0;

    // Einige Münzen einwerfen:
    c1=5, c10=0, c50=30, e1=40;
    cout << "Diese Muenzen werfe ich in mein Sparschwein:" << endl;
    showCoins( c1, c10, c50, e1);
    if( !myPiggy.addCoins( c1, c10, c50, e1))
    {
       cout << "Mein Sparschwein ist voll!\n"
            << "Muenzen, die nicht in mein Sparschwein passten:" << endl;
       showCoins( c1, c10, c50, e1);
       return 0;
    }

    c1=0, c10=11, c50=22, e1=7;
    cout << "\nDiese Muenzen werfe ich in Dein Sparschwein:" << endl;
    showCoins( c1, c10, c50, e1);
    if( !yourPiggy.addCoins( c1, c10, c50, e1))
    {
       cout << "Dein Sparschwein ist voll!\n"
            << "Muenzen, die nicht in Dein Sparschwein passten:" << endl;
       showCoins( c1, c10, c50, e1);
    }

    cout << "\nLos, brechen wir Dein Sparschwein auf" 
         << " und werfen die gefundenen Muenzen in mein Sparschwein!" << endl;
    if( myPiggy.addCoins( &yourPiggy))
    {
       cout << "Vielen Dank fuer alle Deine Muenzen!" << endl;
    }
    else
    {
       cout << "\nNur ein Teil Deiner Muenzen passen in mein Sparschwein!" << endl;
       cout << "Die restlichen Muenzen aus Deinem Sparschwein: " << endl;
       yourPiggy.breakInto(c1,c10,c50,e1);
       showCoins( c1, c10, c50, e1);
    }

    cout << "\nLos, brechen wir mein Sparschwein auf!" << endl;
    
    cents = myPiggy.breakInto( c1, c10, c50, e1);

    cout << "Die Muenzen aus meinem Sparschwein: " << endl;
    showCoins( c1, c10, c50, e1);
    cout << "Das sind " << cents << " Cents." << endl;

    return 0;
}
