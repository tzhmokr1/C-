// ------------------------------------------------------
// ex23_07.cpp
// Klasse Mail verwenden.
// ------------------------------------------------------

#include "mail.h"

int main()
{
   Mail aMail(1020304);

   cout << "Bitte Absender angeben:" << endl;
   if( !aMail.scanFrom())
      cout << "Ungueltige Eingabe!" << endl;

   cout << "und der Empfaenger:" << endl;
   if( !aMail.scanTo())
      cout << "Ungueltige Eingabe!" << endl;

   cout << aMail << endl;

   cout << "... Post mit der ID " << aMail.getID();
   if( aMail.deliver())
      cout << " wurde an " << aMail.getTo().getName()
           << " ausgeliefert!" << endl;
   else
      cout << " konnte nicht ausgeliefert werden!" << endl;

   return 0;
}
