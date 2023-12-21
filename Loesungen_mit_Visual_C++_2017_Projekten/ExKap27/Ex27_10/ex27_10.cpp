// ----------------------------------------------------
// ex27_10.cpp
// Testet die Klasse PersonalProdukt 
// ----------------------------------------------------

#include "PersonalProdukt.h"

int main()
{
   PersonalProdukt sp;
   MitarbeiterKunde mk;
   string s;
   bool found = false;

   for(int i = 0; i < MAX; i++)  // Daten einlesen
      cin >> sp;
  
   cout << sp;                   // Daten ausgeben

   cout << "\nGeben Sie einen Namen ein: "; cin >> s;
                                 // Namen suchen:    
   for(int i=0; i < sp.length(); i++)
   {
       mk = sp.getMitarbeiterKunde(i);
       if(s == mk.getName())
       {
          found = true;         // Name gefunden
          cout << mk << sp.getProdukt(i);
       }
   }
   
   if(!found)
       cout << "Name existiert nicht." << endl;

   return 0;
}
