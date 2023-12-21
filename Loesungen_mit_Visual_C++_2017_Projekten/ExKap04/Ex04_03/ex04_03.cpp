// --------------------------------------------------------
// ex04_03.cpp
// Das Programm zeigt die Zahl 9.876 wie folgt an:
// 9.88
// 9.87600
// 10
// --------------------------------------------------------
#include <iostream>
#include <iomanip>    // Falls setprecision() benutzt wird.
using namespace std;

int main()
{
   double x = 9.876;

   cout.precision(3); 
   cout << x << endl;
   // or: cout << setprecision(3) << x << endl;
 
   cout.precision(6); 
   cout << showpoint << x << endl;
   // or:  cout << setprecision(5) << showpoint   << x << endl;

   cout.precision(0); 
   cout << fixed << noshowpoint << x << endl;
   // or: cout << setprecision(0) << fixed << noshowpoint << x << endl;

   return 0;
}
