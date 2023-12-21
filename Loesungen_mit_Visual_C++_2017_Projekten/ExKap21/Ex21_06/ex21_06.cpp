// ---------------------------------------------------------
// ex21_06.cpp
// Definiert die Funktion sumUp(), die zwei gleich langer 
// double-Vektoren elementweise addiert und das Ergebnis  
// in einem neu erzeugten Vektor zurückgibt.
// Der Aufrufer gibt den Speicher für den neuen Vektor frei,
// wenn dieser nicht mehr benötigt wird. 
// ---------------------------------------------------------

double* sumUp(double* v, double* w, int n)
{
   double* sum = new double[n];

   for(int i=0; i < n; ++i)
     sum[i] = v[i] + w[i];

   return sum;
}

#include <iostream>
#include <iomanip>
using namespace std;

int main()                 // Die Funktion sumUp() testen
{
    double v1[] = { -1.1,  0.2,  1.3, 2.4},
           v2[] = { 10.1, 20.2, 30.3, 40.4};
    int len = sizeof(v1)/ sizeof(double);

    double *sum = sumUp( v1, v2, len);

    cout << "\n   *** Test der Funktion sumUp() *** \n"
         << "\nDie Summe der zwei Vektoren:" << endl;
    for( int i = 0; i < len;  ++i)
        cout << setw(8) << sum[i];
    cout << endl;
    delete sum;

    return 0;
}
