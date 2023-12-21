// --------------------------------------------------------
// ex10_03.cpp 
// Definiert (und testet) die Funktion distanceOf(), die 
// die positive Differenz von zwei double-Werten liefert.
// --------------------------------------------------------
#include <iostream>
using namespace std;

inline double distanceOf( double x, double y)
{
   return  ((x - y) >= 0 ? (x - y) : (y - x));
}

int main()
{
   double start = 0.0, end = 0.0; 

   cout << "\nGeben Sie zwei Zahlen ein:" << endl;
   cin >> start >> end;

   cout << "Die positive Differenz ist " << distanceOf( start, end) << endl;

   return 0;
}
