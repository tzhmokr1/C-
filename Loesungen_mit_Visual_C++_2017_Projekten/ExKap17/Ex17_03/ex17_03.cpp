// -----------------------------------------------------------
// ex17_03.cpp
// Definiert und testet die Funktion geoMean(), die das 
// geometrische Mittel von nicht-negativen Gleitpunktzahlen
// berechnet.
// -----------------------------------------------------------
#include <iostream>
using namespace std;

// Prototyp
double geoMean( double arr[], int len);

#define ARR_SIZE 10

int main()     // Testet die Funktion geoMean()
{
   double testArr[ARR_SIZE], gmean=0.0;
   int i, len = 0;

   cout << "  **** Geometrisches Mittel ****\n"
        << endl;

   cout << "Geben Sie positive Gleitpunktzahlen ein "
           "(Abbruch mit Buchstaben):" << endl;
   for( i = 0; i < ARR_SIZE; ++i)
      if( !(cin >> testArr[i]))
          break;
   len = i;

   gmean = geoMean( testArr, len);
   if( gmean > 0.0)
   {
     cout << "Das geometrische Mittel der Zahlen\n  ";
     for( i = 0; i < len; ++i)
        cout << testArr[i] << "   ";
     cout << "\nist " << gmean << endl;
   }
   else
       cout << "Unzulaessige Eingabe!" << endl;

   return 0;
}

// --------------------------------------------------------
// Die Funktion geoMean() 
//
#include <math.h>       // Prototyp von pow()

double geoMean( double arr[], int len)
{
   double product = 1.0; 

   if( len <= 0)
      return 0.0;

   for( int i = 0; i < len; ++i)
      if( arr[i] <= 0.0)
          return 0.0;
      else
          product *= arr[i];

   return pow( product, 1.0/len);
}
