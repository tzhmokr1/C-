// ---------------------------------------------------------
// customer.h
// Definition der Klasse Customer.
// ---------------------------------------------------------
#ifndef _CUSTOMER_
#define _CUSTOMER_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Customer
{
   private: 
     unsigned long pin;
     string name;

   public:
     Customer( unsigned long id = 0, const string& n = "")
     : pin(id), name(n) {}

     // Zugriffsmethoden:
     const string& getName() const { return name; }
     void  setName( const string& n) { name = n; }

     unsigned long getPIN() const { return pin; }
     void setPIN( unsigned long id) { pin = id;}

     // Die Daten am Bildschirm anzeigen:
     void display() const { cout << setw(10) << pin << "   " << name << endl; }  

     // Die Daten in die Datei schreiben:
     ostream& write( ostream& os) const
     { 
        os.write((char*)&pin, sizeof(pin));
        os << name << '\0';
        return os;
     }
     // Die Daten aus der Datei einlesen:
     istream& read( istream& is) 
     {
        is.read((char*)&pin, sizeof(pin));
        getline( is, name, '\0');
        return is;
     }
};

#endif  //  _CUSTOMER_

