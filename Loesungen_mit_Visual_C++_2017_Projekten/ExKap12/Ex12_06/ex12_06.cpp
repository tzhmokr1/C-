// -------------------------------------------------------
// ex12_06.cpp
// Die Funktion quot_rem() berechnet den ganzzahligen 
// Quotienten und den Divisionsrest von zwei 
// Gleitpunktzahlen
// -------------------------------------------------------
#include <math.h>

bool quot_rem( double x, double y, double& q, double& r)
{
   if( y == 0.0)
       return false;
   else
   {
     r = fmod(x,y);
     q = (x - r)/y;
     return true;
   }
}

#include <iostream>
using namespace std;

int main()
{
   cout << "\n\t***  Quotient und Divisionsrest  ***"
        << endl;

   double x, y, iquot, rem;
   while(true)
   {
     cout << "\nGeben Sie zwei Gleitpunktzahlen ein (Abbruch mit Buchstaben): ";
     if( !(cin >> x >> y))
         break;

     if( !quot_rem( x, y, iquot, rem))
        cerr << "Fehler beim Berechnen des ganzzahligen Quotienten "
             << " und Divisionsrests!" << endl;
     else
        cout << "\nGanzzahliger Quotient: " << iquot
             << "\nDivisionsrest:         " << rem << endl;
   }

   return 0;
}

