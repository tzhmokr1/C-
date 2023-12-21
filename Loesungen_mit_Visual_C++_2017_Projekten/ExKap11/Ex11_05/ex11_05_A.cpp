// ------------------------------------------------------
// ex11_05_A.cpp
// Definiert zwei globale Variablen und eine
// main() Funktion.
// -------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

string name = "Noname";
int    age  = 0; 

void display();

int main( )
{
   cout << "Ihr Name: ";
   getline( cin, name);
   cout << "Ihr Alter:  ";
   cin >> age;

   display();

   return 0;
}
