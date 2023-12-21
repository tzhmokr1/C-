// ----------------------------------------------------------
// ex11_06.cpp
// Definiert und testet die Funktionen sumUp() und average().
// ----------------------------------------------------------
#include <iostream>
using namespace std;

double sumUp(double);
double average(double);

int main()         // Testet die Funktionen.
{
   double x;

   cout << "  **** Summe und Durchschnitt ****\n"
        << endl;

   cout << "Geben Sie Gleitpunktzahlen ein (Abbruch mit Buchstaben): "
        << endl;
   while( cin >> x)
   {
      cout << "Summe:        " << sumUp(x)   << endl;
      cout << "Durchschnitt: " << average(x) << endl;
   }

   return 0;
}

// --------------------------------------------------------
// Die Funktion sumUp() 
//
double sumUp(double x)
{
   static double sum = 0.0;
   return sum += x;
}

// --------------------------------------------------------
// Die Funktion average() 
//
double average(double x)
{
   static double sum = 0.0;
   static int count = 0;
   sum += x;
   ++count;
   return sum / count;
}
