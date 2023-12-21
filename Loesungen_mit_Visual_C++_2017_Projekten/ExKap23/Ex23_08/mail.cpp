// ---------------------------------------------------------
// mail.cpp
// Implementierung der Klassen
// Address, Mail, Letter und Parcel.
// ---------------------------------------------------------

#include "mail.h"

// -------------------------------------------------------
// Klasse Address

// Liest im Dialog eine neue Adresse ein.
bool Address::scan() 
{
    Address adr;                      // Puffer
    cout << "Nachname, Vorname:   ";
    getline( cin, adr.name);
    if( !cin  ||  adr.name == "")
       return false;
    cout << "Strasse mit Hausnr.: ";
    getline( cin, adr.street);
    if( !cin  ||  adr.street == "")
       return false;
    cout << "Postleitzahl Stadt:  ";
    getline( cin, adr.city);
    if( !cin  ||  adr.city == "")
       return false;
    cout << "Land:                ";
    getline( cin, adr.country);
    if( adr.country == "")
       adr.country = "Deutschland";
    *this = adr;                      // Adresse uebernehmen.
    return true;
}

ostream& Address::print( ostream& os) const
{
   os << '\t' << name << "\n\t" << street << "\n\t"
      << city << "\n\t" << country << endl;
   return os;
}

// -------------------------------------------------------
// Klasse Mail

ostream& Mail::print( ostream& os) const
{
   cout << "Mail-ID: " << id << endl;
   if( from.isValid())
      os << "Absender:\n" << from;
   else
      os << "Kein gueltiger Absender!" << endl;

   if( to.isValid())
      os << "Empfaenger:\n" << to;
   else
      os << "Kein gueltiger Empfaenger!" << endl;

   if( !delivered)
      os << "Post wurde noch nicht ausgeliefert!" << endl; 
   else
      os << "Post wurde an " << to.getName() << " ausgeliefert!"
         << endl;
   return os;
}

// -------------------------------------------------------
// Klasse Letter

ostream& Letter::print( ostream& os) const
{
   cout << "--- Brief-Daten ---\n"
        << "Kategorie: "
        << (ctg == STANDARD ? "Standard":"Express") << endl;
   Mail::print(os);
   return os;
}

// -------------------------------------------------------
// Klasse Parcel

ostream& Parcel::print( ostream& os) const
{
   cout << "--- Paket-Daten ---\n"
        << "Gewicht: " << weight << "  / "
        << (insured ? "Versichert.":"Nicht versichert.") << endl;
   Mail::print(os);
   return os;
}
