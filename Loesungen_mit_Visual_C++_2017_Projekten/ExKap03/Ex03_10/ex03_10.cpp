// --------------------------------------------------------
// ex03_10.cpp
// Was gibt folgendes Programm auf dem Bildschirm aus?
// --------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
   string s1 = "Nichts ist ";
   string s2 = "so ";
 
   cout << s1 + s2 + "einfach ";
   s2 = "wie es aussieht"; 
   cout << s2 + " (Murphy's Gesetz)" << endl;

   return 0;
}
