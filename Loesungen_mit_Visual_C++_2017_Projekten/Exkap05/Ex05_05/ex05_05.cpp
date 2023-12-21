// -------------------------------------------------------
// ex05_05.cpp
// Das Programm liest eine Anzahl von Sekunden ein und  
// gibt die entsprechende Anzahl Stunden, Minuten und  
// Sekunden aus.
// -------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
   unsigned long n = 0;
   int hours, minutes, seconds;

   cout << "Geben Sie die Anzahl Sekunden ein: ";
   cin >> n;

   seconds = n % 60;
   n       = n / 60;    // Gesamtzahl Minuten
   minutes = n % 60;
   hours   = n / 60;
/*
   // or:
   hours   = n/3600;
   minutes = (n - hours*3600) / 60;
   seconds = (n - hours*3600) % 60;
*/
   cout << "Stunden:  " << hours   << endl;
   cout << "Minuten:  " << minutes << endl;
   cout << "Sekunden: " << seconds << endl;

   return 0;
}
