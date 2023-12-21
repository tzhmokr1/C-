//==============================================================================
//        * Letsch Informatik *       www.LetsInfo.ch       CH-8636 Wald
//          Beratung, Ausbildung und Realisation in Software-Engineering
//==============================================================================
// Project   : Master of Advanced Studies in Software-Engineering MAS-SE 2019
// Title     : Klasse "Bruch"
// Author    : Thomas Letsch
// Tab-Width : 4
/*///===========================================================================
* Description: Test-Applikation zu Beispiel-Klasse "Bruch" (Musterlösung).
* $Revision  : 1.30 $  $Date: 2019/10/30 17:22:07 $
/*///===========================================================================
//       1         2         3         4         5         6         7         8
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//==============================================================================

#include <iostream>

using std::cout;

#include "Bruch.h"


int main() {

    Bruch bruch1;
    Bruch bruch2 = Bruch(1, 2) ;     // Definition  und Initialisierung
    Bruch bruch3(2, 5);              // andere Variante der Initialisierung

    bruch1.drucke();                 // Ausgabe via Funktion
    cout << "bruch1 = " << bruch1;   // Ausgabe via Operator
    cout << "bruch2 = " << bruch2;
    cout << "bruch3 = " << bruch3;

    // verschiedene Beispiele mit dem Multiplikator-Operator
    cout << "bruch2 * bruch3           = " << bruch2 * bruch3;
    cout << "bruch1 * bruch2 * bruch3  = " << bruch1 * bruch2 * bruch3;
    cout << "bruch2 * 4                = " << bruch2 * 4;

    cout << "bruch2 / bruch3           = " << bruch2 / bruch3;
    cout << "Bruch(3, 4) / Bruch(2, 3) = " << Bruch(3, 4) / Bruch(2, 3);
    cout << "bruch2 + bruch3           = " << bruch2 + bruch3;
    cout << "bruch2 - bruch3           = " << bruch2 - bruch3;
    cout << "!bruch3                   = " << !bruch3;
    cout << "Bruch(12, 27).kuerze()    = " << Bruch(12, 27).kuerze();

    return 0;

}


/* Session-Log:
$
$ g++ -o appl.exe Bruch.cpp BruchAppl.cpp
$
$ appl.exe
Bruch (0/1)
bruch1 = Bruch (0/1)
bruch2 = Bruch (1/2)
bruch3 = Bruch (2/5)
bruch2 * bruch3           = Bruch (2/10)
bruch1 * bruch2 * bruch3  = Bruch (0/10)
bruch2 * 4                = Bruch (4/2)
bruch2 / bruch3           = Bruch (5/4)
Bruch(3, 4) / Bruch(2, 3) = Bruch (9/8)
bruch2 + bruch3           = Bruch (9/10)
bruch2 - bruch3           = Bruch (1/10)
!bruch3                   = Bruch (5/2)
Bruch(12, 27).kuerze()    = Bruch (4/9)
$

*/
