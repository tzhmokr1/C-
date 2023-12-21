// -----------------------------------------------------
// ex22_11_12.cpp
// Die Klasse MeasureArr testen.
// -----------------------------------------------------

#include "measureArr.h"
#include <iostream>
#include <iomanip>
using namespace std;
 
MeasureArr test(const MeasureArr& ma);     // Prototyp

int main()
{
    MeasureArr v(10), w(5);    

    for(int i = 0; i <= 9; i++)   // Messwerte in v einfügen.
      v.append( Measure(i/10.0));

    cout << "Der Vektor v: " << endl;
    cout << setw(5) << v << endl;
    cin.get();
                 // Aufrufe: 1. Kopierkonstruktor
    w = test(v); //          2. Move-Konstruktor u. Destruktor
                 //          3. Move-Zuweisung u. Destruktor

    w[0] = 9.9;              // Messwert überschreiben.
    cout << "Der Vektor w: " << endl;
    cout << setw(5) << w << endl;
    cin.get();

    MeasureArr z(test(w)); // Aufrufe: 1. Kopierkonstruktor 
                           // 2. Move-Konstruktor u. Destruktor

    z[2] = 8.8; 
    cout << "Der Vektor z: " << endl;
    cout << setw(5) << z << endl;

    return 0;
}

MeasureArr test(const MeasureArr& ma)
{
    cout << "In der Funktion test()." << endl;
    MeasureArr temp(ma);
    temp[1] = Measure(77.7);  // Messwert überschreiben.
    return temp;
}
