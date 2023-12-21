// -------------------------------------------------------
// ex05_01.cpp
// Das Programm liest zwei Ganzzahlen im Dialog ein und
// gibt ihr Produkt, den Quotienten und Divisionsrest aus.
// -------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
   int n1 = 0, n2 = 0;

   cout<< endl;
   cout << "Geben Sie zwei Ganzzahlen ein:       ";
   cin >> n1 >> n2;

   cout << "Das Produkt von " << n1 << " und " << n2 
        << " ist:       " << n1 * n2 << endl;
   cout << "Der Quotient von " << n1 << " und " << n2 
        << " ist:      " << n1 / n2 << endl;
   cout << "Der Divisionsrest von " << n1 << " und " << n2 
        << " ist: " << n1 % n2 << endl;

   return 0;
}
