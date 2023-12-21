//==============================================================================
//        * Letsch Informatik *       www.LetsInfo.ch       CH-8636 Wald
//          Beratung, Ausbildung und Realisation in Software-Engineering
//==============================================================================
// Project   : Master of Advanced Studies in Software-Engineering MAS-SE 2019
// Title     : Übung 1 / Aufgabe 2: Zeiger
// Author    : Thomas Letsch
// Tab-Width : 2
/*///===========================================================================
* Description: Einfache Anwendungen von Zeigern.
* $Revision  : 1.11 $  $Date: 2019/10/19 20:33:47 $
/*///===========================================================================
//       1         2         3         4         5         6         7         8
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//==============================================================================

#include <iostream>
using std::cout;
using std::endl;

int main() {

  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  cout << "Adresse der Variable \'i2\'         = " << &i2 << endl;
  cout << "Inhalt der Variable \'i2\'          = " <<  i2 << endl << endl;

  int* p;
  p = &i2;
  cout << "Adresse des Zeiger \'p\'            = " << &p << endl;
  cout << "Inhalt des Zeiger \'p\'             = " <<  p << endl;
  cout << "Inhalt worauf Zeiger \'p\' zeigt    = " << *p << endl << endl;

  int** pp;
  pp = &p;
  cout << "Adresse des Zeiger \'pp\'           = " <<  &pp << endl;
  cout << "Inhalt des Zeiger \'pp\'            = " <<   pp << endl;
  cout << "Inhalt worauf Zeiger \'pp\' zeigt   = " <<  *pp << endl;
  cout << "Inhalt worauf jener Zeiger zeigt,"              << endl;
  cout << "worauf Zeiger \'pp\' zeigt  ;-)     = " << **pp << endl << endl;

  // Zeiger-Arithmetik:
  p = p + 1;
  cout << "p = p + 1 :" << endl;
  cout << "Adresse des Zeiger \'p\'            = " << &p << endl;
  cout << "Inhalt des Zeiger \'p\'             = " <<  p << endl;
  cout << "Inhalt worauf Zeiger \'p\' zeigt    = " << *p << endl << endl;

  // Hinweis: Solche Zeiger-Arithmetik in dieser Art ist sehr gefährlich und sollte
  //           in 'produktivem' Code nicht gemacht werden!

  return 0;

}


/* Session-Log (Linux/g++/x86_64):

Adresse der Variable 'i2'         = 0x7fff0879e5f4
Inhalt der Variable 'i2'          = 2

Adresse des Zeiger 'p'            = 0x7fff0879e5e8
Inhalt des Zeiger 'p'             = 0x7fff0879e5f4
Inhalt worauf Zeiger 'p' zeigt    = 2

Adresse des Zeiger 'pp'           = 0x7fff0879e5e0
Inhalt des Zeiger 'pp'            = 0x7fff0879e5e8
Inhalt worauf Zeiger 'pp' zeigt   = 0x7fff0879e5f4
Inhalt worauf jener Zeiger zeigt,
worauf Zeiger 'pp' zeigt  ;-)     = 2

p = p + 1 :
Adresse des Zeiger 'p'            = 0x7fff0879e5e8
Inhalt des Zeiger 'p'             = 0x7fff0879e5f8
Inhalt worauf Zeiger 'p' zeigt    = 3

*/
