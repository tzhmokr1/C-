// ---------------------------------------------------------
// customer.cpp
// Definiert die Methoden der Klassen Customer und 
// CustomerFile, die nicht inline definiert sind.
// ---------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS    // Für VC++ und strncpy()
#include "customer.h"
#include <cstring>

// --- Class CustomerFile ----------------------------------
// Konstruktor:
CustomerFile::CustomerFile( const char* s)
{ 
   strncpy(filename, s, 127); filename[127] = '\0';
   count = 0;
   // Die Datei zum Lesen öffnen:
   file.open(filename, ios::in | ios::binary);
   if( !file.fail())            // Falls die Datei existiert:
   {                            // Die Anzahl Datensätze in
      Customer buffer;          // der Datei lesen.
      while( buffer.read(file))
         ++count;
      if( !file.eof())
         error("beim Lesen");
       
      file.close();
   }
   file.clear();                // Fehlerflags zurücksetzen.
}

void CustomerFile::append( const Customer& cust)
{
   file.open(filename, ios::out | ios::app | ios::binary);
   if(!file) 
     error("beim Oeffnen");

   if( !cust.write(file))
     error("beim Schreiben");

   ++count;
   file.close();
}

void CustomerFile::display()
{
   if( count == 0)
      cout << " Kein Kunde vorhanden!" << endl;
   else
   {
      Customer buffer;

      file.open(filename, ios::in | ios::binary);
      if(!file) 
        error("beim Oeffnen");

      while( buffer.read(file))
          buffer.display();

      if( !file.eof())
         error("beim Lesen");

      file.clear();                 // Fehlerflags zurücksetzen.
      file.close();
   }
}

bool CustomerFile::retrieve( unsigned long pin, Customer& cust)
{
   bool found = false;
   if( count != 0)
   {
      Customer buffer;

      file.open(filename, ios::in | ios::binary);
      if(!file) 
        error("opening");

      while( found == false && buffer.read(file))
         if( buffer.getPIN() == pin)
            found = true;

      if( found == true)
         cust = buffer;
      else if(!file.eof())
         error("reading from");

      file.clear();                 // Fehlerflags zurücksetzen.
      file.close();
   }
   return found;
}
