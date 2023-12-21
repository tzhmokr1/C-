// ---------------------------------------------------------
// customer.h
// Definition der Klassen Customer und CustomerFile.
// ---------------------------------------------------------
#ifndef _CUSTOMER_
#define _CUSTOMER_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "index.h"
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

class CustomerFile
{
   private:
     string  filename;      // Dateiname
     fstream  file;         // File-Stream
     unsigned long count;   // Aktuelle Anzahl Datensaetze in der Datei
     IndexFile indexFile;   // Mit Indexdatei!

     void createIndex();

     void error( const char *reason)
     {  cerr << "CustomerFile: Fehler " << reason << " der Datei "
             << filename << endl;
        exit(1);
     }

   public:
     CustomerFile( const string& s);
     unsigned long getCount() const { return count; }
     void append( const Customer& cust);
     bool retrieve( unsigned long pin, Customer& cust);
     void display();
};

#endif  // _CUSTOMER_
