// -------------------------------------------------------
// ex04_04.cpp
// Das Programm liest eine Gleitpunktzahl im Dialog ein 
// und gibt die Zahl in Gleitpunktdarstellung und in
// exponentieller Notation mit zwei Ziffern hinter dem 
// Dezimalpunkt aus.
// -------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
   double x;

   cout << "Geben Sie eine Gleitpunktzahl ein: ";
   cin >> x;
   
   cout.precision(2);
   cout << fixed << x << endl;
   cout << scientific << x << endl;
   
   return 0;
}
