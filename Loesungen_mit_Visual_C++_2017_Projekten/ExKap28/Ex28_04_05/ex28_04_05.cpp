// --------------------------------------------
// ex28_04_05.cpp
// Testet die Fehlerklasse MyException.
// --------------------------------------------

#include <iostream>
using namespace std;

#include "myException.h"

void otherfunc();

void func(int e)
{
   switch(e)
   {
    case 1 : throw exception();
             break;
    case 2 : throw MyException(  
                   (string)"MyException-Fehler.");
             break;
    case 3 : otherfunc();
   }
}

void otherfunc()
{
   throw (string)"Fehler in otherfunc()";
}

int main()
{
   for(int i = 0; i <= 3; i++)
     try 
     {
       func(i);
     }
     catch( MyException& de)
     {
       cerr << de.what() << endl;
     }
     catch( exception& de)
     {
       cerr << de.what() << endl;
     }
     catch( ... ) 
     {
       cerr << "Anderer Fehler" << endl;
     }

   return 0;
}
