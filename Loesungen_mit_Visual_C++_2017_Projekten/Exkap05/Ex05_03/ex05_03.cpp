// ------------------------------------------------------
// ex05_03.cpp
// Das Programm konvertiert eine Temperatur von 
// Fahrenheit in Celsius (und umgekehrt).
// ------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
   double cels = 0.0, fahr = 0.0;

   cout << "\nGeben Sie eine Temperatur in Fahrenheit ein: ";
   cin >> fahr;

   cels = 5.0*(fahr-32.0)/9.0;

   cout << fixed;  cout.precision(2);
   cout << fahr << " Fahrenheit entsprechen " 
	    << cels << " Grad Celsius." << endl;

   cout << "\nGeben Sie eine Temperatur in Celsius ein: ";
   cin >> cels;

   fahr = 9.0/5.0 * cels + 32.0;

   cout << cels << " Celsius entsprechen " 
	    << fahr << " Grad Fahrenheit." << endl;

   return 0;
}
