// ---------------------------------------------------------
// customer.cpp
// Definiert die Methoden der Klassen Customer und 
// CustomerFile, die nicht inline definiert sind.
// ---------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS    // F�r VC++ und strncpy()
#include "customer.h"
#include <cstring>

// --- Class CustomerFile ----------------------------------
// Konstruktor:
CustomerFile::CustomerFile( const char* s)
{ 
   strncpy(filename, s, 127); filename[127] = '\0';
   count = 0;
   // Die Datei zum Lesen �ffnen:
   file.open(filename, ios::in | ios::binary);
   if( !file.fail())            // Falls die Datei existiert:
   {                            // Die Anzahl Datens�tze in
      Customer buffer;          // der Datei lesen.
      while( buffer.read(file))
         ++count;
      if( !file.eof())
         error("beim Lesen");
       
      file.close();
   }
   file.clear();                // Fehlerflags zur�cksetzen.
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

      file.clear();                 // Fehlerflags zur�cksetzen.
      file.close();
   }
}
