//==============================================================================
//        * Letsch Informatik *       www.LetsInfo.ch       CH-8636 Wald
//          Beratung, Ausbildung und Realisation in Software-Engineering
//==============================================================================
// Project   : Master of Advanced Studies in Software-Engineering MAS-SE 2019
// Title     : Übung 1 / Aufgabe 3: Swap
// Author    : Thomas Letsch
// Tab-Width : 2
/*///===========================================================================
* Description: Einfache Anwendungen von Referenzen u. Zeigern.
* $Revision  : 1.10 $  $Date: 2019/10/30 17:19:47 $
/*///===========================================================================
//       1         2         3         4         5         6         7         8
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//==============================================================================

#include <iostream>
using std::cout;
using std::endl;

int swapMaxRefs(int&, int&);
int swapMaxPtrs(int*, int*);

int main() {

  cout << "Swap with References:" << endl;
  int i1 = 1;
  int i2 = 2;
  int max = swapMaxRefs(i1, i2);

  cout << max << endl;    // Ausgabe: 2
  cout << i1 << endl;     // Ausgabe: 2
  cout << i2 << endl;     // Ausgabe: 1

  cout << "Swap with Pointers:" << endl;
  i1 = 1;
  i2 = 2;
  max = swapMaxPtrs(&i1, &i2);
  cout << max << endl;    // Ausgabe: 2
  cout << i1 << endl;     // Ausgabe: 2
  cout << i2 << endl;     // Ausgabe: 1

  return 0;

}

int swapMaxRefs(int& i1, int& i2) {
  int buffer = i1;
  i1 = i2;
  i2 = buffer;
  return i1 > i2 ? i1 : i2;
}

int swapMaxPtrs(int* i1, int* i2) {
  int buffer = *i1;
  *i1 = *i2;
  *i2 = buffer;
  return *i1 > *i2 ? *i1 : *i2;
}




/* Session-Log:

Swap with References:
2
2
1
Swap with Pointers:
2
2
1

*/
