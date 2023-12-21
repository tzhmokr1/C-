// ----------------------------------------------
// phoneCall.cpp
// Definiert die Methoden der Klasse PhoneCall
// ----------------------------------------------
#include <iostream>
#include "phoneCall.h"
using namespace std;

bool PhoneCall::initCall(const string& n) 
{ 
   if(OutCall::getNr() == "0")  
   {                      // Falls Leitung frei: 
      OutCall::setNr(n);  // Tel-Nr. des Anrufers setzen
      dauer = 0;
      InCall::setTime(0);
      OutCall::setTime(0);
      return true;
   }
   else return false;
}

bool PhoneCall::dial(const string& n)
{
   if(InCall::getNr() == "0" && 
      OutCall::getNr() != "0")
   {
      InCall::setNr(n);        // Telefonnummer setzen
      OutCall::setFlag(true);  // Verbindung aufbauen
                               // Zeitstempel setzen:
      OutCall::setTime();      
      return true;
   }
   else return false;
}

bool PhoneCall::answerCall()
{
   if( OutCall::getFlag() && !InCall::getFlag())  
   {
      OutCall::setFlag(false); // Aufbau fertig.
      InCall::setFlag(true);   // Verbindung besteht.
      InCall::setTime();       // Zeitstempel setzen
      return true;
   }
   else return false;
}

bool PhoneCall::hangUp()
{
   if( OutCall::getNr() != "0") // Sitzung existiert?
   {                            // Beginn Verbindung:
      time_t begin = InCall::getTime();
                                // Verbindungsdauer:
      dauer = (begin == 0) ?  0 : 
              (long)time(NULL) - (long)begin;
      OutCall::setFlag(false);
      OutCall::setNr("0");
      InCall::setFlag(false);
      InCall::setNr("0");
      return true;
   }
   else 
      return false;
}
