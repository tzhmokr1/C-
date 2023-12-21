// ---------------------------------------------------
// ex03_04.cpp
// Liest eine Gleitpunktzahl im Dialog ein und
// gibt den Sinus und Cosinus dieser Zahl aus.
// ---------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double x;

  cout << "Geben Sie eine Gleitpunktzahl ein: ";
  cin >> x;

  cout << "Der Sinus von   " << x << " ist: " << sin(x) << endl;
  cout << "Der Cosinus von " << x << " ist: " << cos(x) << endl;

  return 0;
}
