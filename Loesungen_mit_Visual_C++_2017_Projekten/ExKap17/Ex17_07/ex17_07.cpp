// -------------------------------------------------------------
// ex17_07.cpp
// Ruft die Funktion merge() auf, die zwei 
// in aufsteigender Reihenfolge sortierte Vektoren mischt.
// -------------------------------------------------------------
#include <iostream>
using namespace std;

// Prototyp
int merge( int arr1[], int len1, int arr2[], int len2, int dest[]);

int main()     // Testet die Funktion rfind()
{
   int testArr1[] = { -9, -2, 0, 4, 8, 14, 21, 27, 35, 40 },
       testArr2[] = { -11, 0, 5, 8, 12, 25 },
       result[20];

   int len1 = sizeof(testArr1) / sizeof(int),
       len2 = sizeof(testArr2) / sizeof(int),
       len3, i;

   cout << " **** Sortierte Vektoren mischen ****" << endl;

   cout << "\nDer erste Vektor:\n  ";
   for( i=0; i < len1; ++i)
       cout << testArr1[i] << "   ";
   cout << endl;

   cout << "\nDer zweite Vektor:\n  ";
   for( i=0; i < len2; ++i)
       cout << testArr2[i] << "   ";
   cout << endl;

   len3 = merge( testArr1, len1, testArr2, len2, result);
   if( len3 < 0)
      cout << "Fehler beim Mischen: Ein Vektor ist unsortiert!" << endl;
   else
   {
      cout << "\nDas Ergebnis:\n  ";
      for( i=0; i < len3; ++i)
         cout << result[i] << "   ";
      cout << endl;
   }
   return 0;
}
