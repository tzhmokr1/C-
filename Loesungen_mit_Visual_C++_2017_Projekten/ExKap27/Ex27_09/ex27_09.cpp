// ----------------------------------------------------
// ex27_09.cpp
// Testet MitarbeiterKunde mit virtueller Basisklasse
// ----------------------------------------------------

#include "MitarbeiterKunde.h"

int main()
{
   MitarbeiterKunde mk("Mayer", "Muenchen", "DKB");

   cout << mk << endl;

   mk.setName("Mayer"); 
   mk.setAdresse("Berlin");
   mk.setBank("IngDiBa");

   cout << mk << endl;

   return 0;
}
