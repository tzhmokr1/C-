//==============================================================================
//        * Letsch Informatik *       www.LetsInfo.ch       CH-8636 Wald
//          Beratung, Ausbildung und Realisation in Software-Engineering
//==============================================================================
// Project   : Master of Advanced Studies in Software-Engineering MAS-SE 2019
// Modul     : C++
// Title     : Übung Zeiger/Referenzen und "Klasse Person": Lösung
// Author    : Thomas Letsch
// Tab-Width : 2
/*///===========================================================================
* Description: Detaildesign mit Zeigern und Referenzen.
*              Klasse implementieren und erweitern aufgrund applikatorischer
*              Anforderungen.
* $Revision  : 1.28 $  $Date: 2019/10/31 10:19:23 $
/*///===========================================================================
//       1         2         3         4         5         6         7         8
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//==============================================================================

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "Person.h"

using namespace std;

void aufgabe1();
void aufg1_funcPtr(string** str);
void aufg1_funcRef(string*& str);
void aufgabe2();
void aufgabe3();
void aufgabe4();

int main(int argc, char* argv[]) {
  aufgabe1();
  aufgabe2();
  aufgabe3();
  aufgabe4();
  return 0;
}


void aufgabe1() {
  // Detaildesign mit Zeigern und Referenzen:
  cout << endl << "Aufgabe 1:" << endl;

  string* strPtr = new string("NOT DONE YET");
  aufg1_funcPtr(&strPtr);
  cout << "str mit Zeiger   = " << *strPtr << endl;
  strPtr = new string("NOT DONE YET");
  aufg1_funcRef(strPtr);
  cout << "str mit Referenz = " << *strPtr << endl;

}


void aufg1_funcPtr(string** str) {
  string* tmpStrPtr = new string("funcPtr");
  *str = tmpStrPtr;
}


void aufg1_funcRef(string*& str) {
  str = new string("funcRef");
}


void aufgabe2() {
  // Klasse, Strings, char-Array, Arrays von Objekten:
  cout << endl << "Aufgabe 2:" << endl;

  const int MAX_ARR = 5;

  Person persArr[MAX_ARR];

  cout << endl << "Personen-Array:" << endl;
  for (int i = 0; i < MAX_ARR; i++) {
    cout << persArr[i].getNr() << ": " << persArr[i].getName() << endl;
  }
  persArr[0].setName("Miller");
  persArr[0].setNr(1);
  persArr[1].setName("Bond");
  persArr[1].setNr(007);
  cout << endl << "Personen-Array:" << endl;
  for (int i = 0; i < MAX_ARR; i++) {
    cout << persArr[i].getNr() << ": " << persArr[i].getName() << endl;
  }

  // Ausgabe des Personen-Arrays wie oben mit for-Schleifen, jetzt aber mit
  // Funktion 'printPersArr()':
  cout << endl << "Personen-Array mit \'printPersArr()\':" << endl;
  printPersArr(persArr, MAX_ARR);
}


void aufgabe3() {
  // Untersuchung wieviel Zeit Objekt-Allozierungen auf Stack und Heap benoetigen:
  cout << endl << "Aufgabe 3: Stack vs. Heap:" << endl;

  chrono::time_point<std::chrono::high_resolution_clock> start, end;
  const int MAX_LOOP = 10000000;

  // Allozierung auf dem Stack:
  start = chrono::high_resolution_clock::now();
  for (int i = 0; i < MAX_LOOP; i++) {
    Person pers(i, "John");
  }
  end = chrono::high_resolution_clock::now();
  int64_t timeStack = chrono::duration_cast<chrono::milliseconds>(end-start).count();
  cout << std::left << setw(12) << "Stack" << "= " << timeStack << " ms" << endl;

  // Allozierung auf dem Heap:
  start = chrono::high_resolution_clock::now();
  for (int i = 0; i < MAX_LOOP; i++) {
    Person* pers = new Person(i, "John");
    delete pers;
  }
  end = chrono::high_resolution_clock::now();
  int64_t timeHeap = chrono::duration_cast<chrono::milliseconds>(end-start).count();
  cout << std::left << setw(12) << "Heap: new()" << "= " << timeHeap << " ms" << endl;
}


void aufgabe4() {
  // Links-Shift-Operator (<<) und 'const':
  cout << endl << "Aufgabe 4:" << endl;

  Person tom(1, "Tom");
  Person john = "John Smith";
  cout << tom << endl;
  cout << john << endl;

  const Person bond(4711, "James Bond");
  cout << bond << endl;
  cout << bond.getNr();
}

/* Session-Log:

$ make clean all
rm -f Person.o PersonTest.o appl.exe
g++ -g -std=c++11 -c Person.cpp
g++ -g -std=c++11 -c PersonTest.cpp
g++ -g -std=c++11 -o appl.exe Person.o PersonTest.o

$ ./appl.exe

Aufgabe 1:
str mit Zeiger   = funcPtr
str mit Referenz = funcRef

Aufgabe 2:

Personen-Array:
-1:
-1:
-1:
-1:
-1:

Personen-Array:
1: Miller
7: Bond
-1:
-1:
-1:

Personen-Array mit 'printPersArr()':
1: Miller
7: Bond
-1:
-1:
-1:

Aufgabe 3: Stack vs. Heap:
Stack       = 126 ms
Heap: new() = 523 ms

Aufgabe 4:
Name: Tom                   Nr: 1
Name: John Smith            Nr: -1
Name: James Bond            Nr: 4711
4711

$

*/
