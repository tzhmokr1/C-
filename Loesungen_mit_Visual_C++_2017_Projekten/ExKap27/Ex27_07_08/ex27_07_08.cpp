// -------------------------------------------------
// ex27_07_08.cpp
// Testet die Klassen für Telefonverbindungen
// -------------------------------------------------
#include <iostream>
#include <string>
#include "phoneCall.h"
using namespace std;

int main()
{
   PhoneCall p;
 
   if(p.initCall("2013078"))  // Anrufer nimmt Hörer ab.
      cout << "Anschluss " << p.OutCall::getNr() 
           << " baut Verbindung auf:" << endl;
   else
      cout << "Leitung nicht frei." << endl;

   if(p.dial("8703102"))      // Anrufer wählt Nummer.
   {
      cout << "Die Nummer " << p.InCall::getNr() 
           << " wurde gewaehlt. " << endl
           << "Zeitpunkt: " <<  p.OutCall::getTimeStr()
           << "\nIhr Telefon klingelt. "
           << "Hoerer abnehmen mit return." << endl;
   }
   else
      cout << "Anschluss belegt." << endl;
/*
   if(p.hangUp())
       cout << "Anrufer haengt ein." << endl
            << "Dauer des Gespraechs " << p.getDauer() 
           << endl;
   else
      cout << "Kein Gespraech in der Leitung." << endl;
*/

   cin.get();
   if(p.answerCall())   // Anruf wird entgegengenommen. 
   {
      cout << "Hoerer wurde abgenommen. "
           << "Verbindung besteht." << endl
           << "Zeitpunkt: " << p.InCall::getTimeStr() 
           << "Sprechen Sie jetzt. "
           << "Hoerer einhaengen mit return." << endl;
   }
   else
      cout << "Verbindung misslungen." << endl;

   cin.get();

   if(p.hangUp())       // Gespräch beenden:
      cout << "Hoerer wurde eingehaengt. "
           << "Verbindung beendet." << endl
           << "Gespraechsdauer: " << p.getDauer() 
           << " Sekunden." << endl;
   else
      cout << "Verbindung existiert nicht." << endl;
  
   return 0;
}
