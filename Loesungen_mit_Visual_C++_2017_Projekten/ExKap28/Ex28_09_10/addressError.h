// ----------------------------------------------
// addressError.h : Fehlerklasse zur Darstellung
//                  von fehlerhaften Adressen.
// ----------------------------------------------
#ifndef _ADRESSERROR_
#define _ADRESSERROR_

#include <string>
using namespace std;

class AddressError
{
  private:
   string ade; 
   int id;

  public:
   AddressError(int i) : id(i) 
   { 
     switch (i)
     {
      case 1 : ade = "Adressat unleserlich.";
               break;
      case 2 : ade = "Postleitzahl falsch.";
               break;
      case 3 : ade = "Hausnummer existiert nicht.";
               break;
      default : ade = "Unbekannter Fehler";
     }
   }

   int getErrorID() const { return id; }
   const char* what() const { return ade.c_str(); }
};

#endif // _ADRESSERROR_
