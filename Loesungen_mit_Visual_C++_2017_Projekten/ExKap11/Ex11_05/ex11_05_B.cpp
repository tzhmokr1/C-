// -------------------------------------------------------------
// ex11_05_B.cpp
// Definiert die Funktion display().
// -------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

extern string name;
extern int age; 

void display( )
{
   cout << "Hallo " << name << "," << endl;
   cout << "Sie sind " << age << " Jahre alt." << endl;
}

