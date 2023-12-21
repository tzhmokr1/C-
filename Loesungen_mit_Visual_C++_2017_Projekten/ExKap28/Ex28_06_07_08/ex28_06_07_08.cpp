// ----------------------------------------------
// ex28_06_07_08.cpp
// Testet die Fehlerbehandlung für Textdateien.
// ----------------------------------------------

#include <string>
#include <iostream>
using namespace std;

#include "sms.h"

int main()
{
   char message[255];

   cout << "1. Versuch: " << endl;

   try
   {
      SMS mail1("Nachricht1.txt");
           // Falls Datei nicht existiert, Fehler:
      mail1.read(message);          
      cout << message << endl;
   }
   catch(OpenError& e)
   {
      cerr << e.what() << endl;
   }
   catch(ReadError& e)
   {
      cerr << e.what() << endl;
   }
   
   cout << "2. Versuch: " << endl;

   try
   {
     SMS mail1("Nachricht1.txt");
     mail1.write("Hallo Swen, kommst mit ins Kino?"
                 " Gruss, Heike");
      
     SMS mail2("Nachricht1.txt");
     mail2.read(message);   
     cout << message << endl;
   }
   catch(OpenError& e)
   {
      cerr << e.what() << endl;
   }
   catch(WriteError& e)
   {
      cerr << e.what() << endl;
   }
   catch(ReadError& e)
   {
      cerr << e.what() << endl;
   }
   
   return 0;
}
