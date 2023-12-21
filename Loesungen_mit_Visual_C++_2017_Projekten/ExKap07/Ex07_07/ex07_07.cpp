// -------------------------------------------------------
// ex07_07.cpp
// Definiert und testet die Makros MIN2() und MIN3().
// -------------------------------------------------------

#include <iostream>
using namespace std;

#define MIN2(a,b)    ((a) < (b) ? (a) : (b))
#define MIN3(a,b,c)  ((a) < (b) ? MIN2(a,c) : MIN2(b,c))

int main()
{
   int n1=0, n2=0, n3=0;

   cout << "Geben Sie zwei Ganzzahlen ein: ";
   cin >> n1 >> n2;
   cout << "\nDas Minimum von " << n1 << " und " << n2 
        << " ist: " << MIN2( n1, n2) << endl;

   cout << "Geben Sie eine dritte Ganzzahl ein: ";
   cin >> n3;
   cout << "Das Minimum von " << n1 << ", " << n2 
        << " und " << n3 << " ist: " << MIN3( n1, n2, n3)
        << endl;

   return 0;
}
