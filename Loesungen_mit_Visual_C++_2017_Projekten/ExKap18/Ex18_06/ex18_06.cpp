// ---------------------------------------------------------
// ex18_06.cpp
// Testet die Klasse Customer.
// ---------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "customer.h"
using namespace std;

char filename[] = "customer.dat";

Customer arrCustomer[] = { Customer( 123456, "Michael Smith"),
                           Customer( 234567, "Jack Ripper"),
                           Customer( 345678, "Alexa Queen"),
                           Customer( 456789, "John Little") };

int arrLen = sizeof(arrCustomer) / sizeof(Customer);

inline void openError( const char* s)
{  cerr << "Fehler beim Oeffnen der Datei " << s << endl; exit(1); }

inline void writeError(char* s)
{  cerr << "Fehler beim Schreiben in die Datei " << s << endl; exit(2); }

inline void readError(char* s)
{  cerr << "Fehler beim Lesen der Datei " << s << endl; exit(3); }

int main()
{
   int i = 0;                          // Zum Schreiben oeffnen:
   ofstream outfile( filename, ios::out | ios::binary);

   if( !outfile) 
     openError( filename);

   for( i = 0;  i < arrLen;  ++i)      // Die Daten in die Datei schreiben.
      if( ! arrCustomer[i].write( outfile) )
        writeError( filename);

   outfile.close();
                                       // Zum Lesen oeffnen:
   ifstream infile( filename, ios::in | ios::binary);
   if( !infile) 
     openError( filename);

   Customer aCustomer;
   int count = 0;
   while( aCustomer.read(infile))      // Die Daten aus der Datei lesen
   {
      aCustomer.display();             // und am Bildschirm anzeigen.
      ++count;
   }
   cout << "\nAnzahl gelesener Objekte: " << count << endl;   

   if( !infile.eof())
     readError( filename);
   infile.close();

   return 0;
}
