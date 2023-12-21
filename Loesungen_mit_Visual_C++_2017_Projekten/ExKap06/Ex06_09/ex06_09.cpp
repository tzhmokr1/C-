// --------------------------------------------------------
// ex06_09.cpp
// Liest Zeichen und Zahlen in Schleifen ein.
// --------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
// a)
   cout << "Geben Sie eine Textzeile ein:" << endl;
   char c = 0;
   while( cin.get(c) && c != '\n')
      cout.put(c);
   cout << endl;

// b)
   cout << "Geben Sie einige Zahlen ein (Abbruch mit Buchstaben): "
        << endl;
   long n = 0, sum = 0; 
   while( cin >> n)
      sum += n;
   cout << "Die Summe: " << sum << endl;
   cin.clear();
   while( cin.get() != '\n')     // Rest der Zeile überspringen
       ;
// c)
   cout << "Geben Sie Gleitpunktzahlen ein, bis die Summe 100 ueberschreitet: "
        << endl;
   double x = 0.0, sum2 = 0.0;
   while( cin >> x && (sum2 += x) < 100.0)
       ;
   // oder:
   // while( cin >> x)
   // { sum2 += x;
   //   if(sum2 >= 100.0) break; 
   // }
   // oder:
   // do
   // {  if( !(cin >> x) break; 
   //    sum2 += x;
   // }while( sum2 < 100.0);

//d)
   cout << "Geben Sie Ganzzahlen ein (Abbruch mit negativer Zahl): "
        << endl;
   int i = 0;
   while( cin >> i && i >= 0)
       ;

// e)
   int n1=1, n2=2, n3=3;
   cout << "Geben Sie drei verschiedene Ganzzahlen ein. " << endl;
   cout << "Die erste Ganzzahl:    ";
   cin >> n1;
   do 
   {   cout << "\nDie zweite Ganzzahl: ";
       cin >> n2;
   } while( n1 == n2);
   do
   {   cout << "\nDie dritte Ganzzahl:  ";
       cin >> n3;
   } while( n1 == n3 || n2 == n3);
   cout << "Ihre Eingabe: " << n1 << "   " << n2 << "   " << n3 << endl;

   return 0;
}
