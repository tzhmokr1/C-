// ----------------------------------------------
// phoneCall.cpp
// Definiert die Methoden der Klasse PhoneCall
// ----------------------------------------------

#include "phoneCall.h"

bool PhoneCall::initCall(const string& n) 
{ 
   if(OutCall::getNr() == "0")  
   {                           // Falls Leitung frei: 
      OutCall::setNr(n);// Tel-Nr. des Anrufers setzen
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
      return true;
   }
   else return false;
}
        
bool PhoneCall::answerCall()
{
   if( OutCall::getFlag() && !InCall::getFlag())  
   {
      OutCall::setFlag(false); // Aufbau fertig,
      InCall::setFlag(true);   // Verbindung besteht.
      return true;
   }
   else return false;
}

bool PhoneCall::hangUp()
{
   if( OutCall::getNr() != "0" )  // Sitzung existiert?
   {
      OutCall::setFlag(false);
      InCall::setFlag(false);
      InCall::setNr("0");
      OutCall::setNr("0");
      return true;
   }
   else return false;
}
