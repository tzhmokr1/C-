// -------------------------------------------------
// ex27_06.cpp
// Testet die Klassen für Telefonverbindungen
// -------------------------------------------------
#include <iostream>
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
      cout << "Die Nummer " << p.InCall::getNr() 
           << " wurde gewaehlt. " << endl;
   else
      cout << "Anschluss belegt." << endl;
/*
   if(p.hangUp())
      cout << "Ein Teilnehmer haengt ein." << endl;
   else
      cout << "Kein Gespraech in der Leitung." << endl;
*/
   if(p.answerCall())   // Anruf wird entgegengenommen. 
      cout << "Teilnehmer hat Hoerer abgenommen. "
           << "Verbindung besteht." << endl;
   else
      cout << "Verbindung misslungen." << endl;

   if(p.hangUp())       // Gespräch beenden:
      cout << "Ein Teilnehmer hat eingehaengt. "
           << "Verbindung beendet." << endl;
    else
      cout << "Verbindung existiert nicht." << endl;

   return 0;
}
