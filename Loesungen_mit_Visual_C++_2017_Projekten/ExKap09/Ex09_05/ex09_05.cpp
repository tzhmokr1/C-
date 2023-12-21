// -------------------------------------------------------------
// ex09_05.cpp 
// Was wird auf dem Bildschirm ausgegeben, wenn die Anweisungen
//   int n;  string s;
//   cin >> n >> s;
//   cout << s << '-' << n << endl;
// mit folgenden Eingaben ausgeführt werden?
// a)  4.5 times 2
// b)  4 times 2
// c)  5times2
// --------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
   int n;  string s;

   cout << "Geben Sie eine Zahl und einen Text ein:"
        << endl;
   cin >> n >> s;
   cout << s << '-' << n << endl;

   return 0;
}
