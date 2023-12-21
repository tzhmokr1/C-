// --------------------------------------------------------------
// ex16_05.cpp
// Liest Gleitpunktzahlen im Dialog ein und speichert sie
// in einem Vektor. Anschließend werden der größte und kleinste
// Wert gesucht und der Durchschnitt aller Vektorelemente 
// berechnet. Die Ergebnisse werden ausgegeben. 
// --------------------------------------------------------------
#include <iostream>
using namespace std;

#define MAX 50
double arr[MAX];

int main()
{
   int i, iMin = 0, iMax = 0, cnt = 0;   // Indizes, Zähler
   double sum = 0.0;

   cout << "Geben Sie bis zu 50 Gleitpunktzahlen ein \n"
        << "(Abbruch mit Buchstaben):" << endl;
   // Liest die Zahlen ein und berechnet die Summe:
   for( i=0; i < MAX && cin >> arr[i]; ++i)
      sum += arr[i]; 
   cnt = i;            // Anzahl Vektorelemente

   // Berechnet das Minimum und das Maximum:
   for( i = 1; i < cnt; ++i)
   {
     if( arr[i] > arr[iMax])
         iMax = i;
     if( arr[i] < arr[iMin])
         iMin = i;
   }
                                   // Ausgabe der Ergebnisse:
   cout << "Anzahl Vektorelemente:  " << cnt << endl;
   if( cnt > 0)
   {
      cout <<   "Kleinster Wert:  " << arr[iMin]
           << "\nGroesster Wert:  " << arr[iMax]
           << "\nDurchschnitt:    " << sum/cnt
           << endl;
   }
   return 0;
}
