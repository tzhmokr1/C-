// --------------------------------------------------------
// ex04_05.cpp
// Das Programm gibt
//   die größte darstellbare Zahl vom Typ unsigned int und 
//   die Zahl -1 in dezimaler, oktaler und hexadezimaler
//   Darstellung 
// linksbündig in ein Feld der Breite 15 aus. 
// --------------------------------------------------------
#include <iostream>
#include <climits>
#include <iomanip>      // Falls setw() benutzt wird.
using namespace std;

int main()
{
    cout << left;                     // Ausgabe linksbündig
    // oder: cout.setf(ios::left, ios::adjustfield);

    // Mit dem Manipulator setw():
    cout << setw(15) << "Dezimal"
         << setw(15) << "Oktal  "
         << setw(15) << "Hexadezimal" << endl;

    cout << uppercase                 // Für Hex-Ziffern
         << setw(15) << UINT_MAX 
         << setw(15) << oct  << UINT_MAX
         << setw(15) << hex  << UINT_MAX << endl;

    cout << setw(15) << dec  << -1 
         << setw(15) << oct  << -1 
         << setw(15) << hex  << -1 << endl;
/*
    // Oder mit der Methode width():
    cout.width(15);  cout << "Dezimal";
    cout.width(15);  cout << "Oktal  ";
    cout.width(15);  cout << "Hexadezimal" << endl;

    cout << uppercase;                 // Für Hex-Ziffern
    cout.width(15);  cout << UINT_MAX;
    cout.width(15);  cout << oct  << UINT_MAX;
    cout.width(15);  cout << hex  << UINT_MAX << endl;

    cout.width(15);  cout << dec  << -1;
    cout.width(15);  cout << oct  << -1;
    cout.width(15);  cout << hex  << -1 << endl;
*/
    return 0;
}
