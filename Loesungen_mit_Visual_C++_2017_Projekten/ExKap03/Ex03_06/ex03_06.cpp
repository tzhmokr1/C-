// --------------------------------------------------------
// ex03_06.cpp
// Liest eine Ganzzahl im Dialog ein, um den Zufalls-
// zahlengenerator zu initialisieren. Zwei Zufallszahlen 
// und ihre Differenz werden ausgegeben.
// --------------------------------------------------------
#include <iostream>
#include <cstdlib>    // Prototypen von srand() und rand()
using namespace std;

int main()
{
  unsigned int seed;

  cout << "Geben Sie eine ganze Zahl ein: ";
  cin >> seed;

  srand(seed);    // Initialisiert den Zafallszahlengenerator

  int rn1 = rand(),
      rn2 = rand();
  cout << "\nZwei Zufallszahlen: " << rn1 << "    " << rn2
       << "\nund ihre Differenz: " << rn1 - rn2 
       << endl;

  return 0;
}
