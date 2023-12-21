// ---------------------------------------------
// ex28_09_10.cpp
// Schachteln von Ausnahmebehandlungen.
// ---------------------------------------------

#include <iostream>
#include <ctime>
#include <cstdlib>

//#include "addressError.h"
#include "addressError.h"

using namespace std;

bool scan()
{
   int i;
               // Zeitverzögerung für Scannen:
   for(long j=0; j < 100000000; j++);    

               // Zufallszahl zwischen 1 und 7:
   srand((unsigned int)time(NULL));
   i = 1 + rand() % 7;

   if(i < 4)
        throw AddressError(i);  // Fehler
   else  
       return true;
}

int main()
{
   bool success;        // Return-Wert von scan()
   char c;              // Weiter-Taste

   while (true)
   {
     success = false;

     try
     {
       try 
       {                // Brief einscannen:
         cout << "Brief wird gescannt." << endl;
         success = scan();
       }
       catch( AddressError& de)
       {
         if(de.getErrorID() == 1)
         {
           cerr << de.what() << endl;
           cerr << "Nochmal einscannen." << endl;
           success = scan();
         }
         else throw;
       }
    }
    catch( AddressError& de)
    {
      cerr << de.what() << endl;

      switch(de.getErrorID())
      {
        case 1 : cerr << "Zurueck an Absender.\n";
                 break;
        case 2 :
        case 3 : cerr << "Weiter zur manuellen "
                      << " Korrektur" << endl;
                 break;
        default : cerr << "Unbekannter Fehler\n";
      }
    }
    catch( ... ) 
    {
       cerr << "Unbekannter Fehler." << endl;
    }

   if(success)
        cout << "\nScan-Vorgang erfolgreich.\n";
   
   cout << "\nWeiter mit beliebiger Taste und Return"  
        << " (Abbruch mit 'q')" << endl;
   cin >> c;
   if(c == 'q') break;
  }
 
   return 0;
}
