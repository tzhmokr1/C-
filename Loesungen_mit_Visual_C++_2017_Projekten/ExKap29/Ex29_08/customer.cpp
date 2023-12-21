// ---------------------------------------------------------
// customer.cpp
// Definiert die Methoden der Klasse CustomerFile
// mit Indexdatei.
// ---------------------------------------------------------

#include "customer.h"
#include <algorithm>            // Für sort()

// --- Class CustomerFile ----------------------------------
// Konstruktor:
CustomerFile::CustomerFile( const string& s)
: filename(s+".dat"), indexFile(s+".ind"), count(0)
{ 
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
   file.clear();                 // Fehlerflags zurücksetzen.

   if(!indexFile.is_open())      // Indexdatei überprüfen.
       error("Indexdatei");
   indexFile.seekg(0,ios::end);  // An das Ende der Datei.
   long long pos = indexFile.tellg();
   if( count != pos/sizeof(IndexEntry) )
      createIndex();
   if(count > 0)
       indexFile.display();
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

// Indexdatei neu erzeugen:
void CustomerFile::createIndex()
{
   if(indexFile.is_open()) indexFile.close();

   indexFile.open(indexFile.getName(),    // Neu erzeugen.
                  indexFile.mode | ios::trunc);
   if(!indexFile.is_open())
       error("Indexdatei");

   if( count == 0) return;               // Nichts zu tun.

   // Primärdatei zum Lesen öffnen:
   file.open(filename, ios::in | ios::binary);
   if(!file.is_open())
       error("beim Oeffnen");

   IndexEntry *indArr = NULL;
   try {                                 // Platz zum Sortieren.
       indArr = new IndexEntry[count];
   } catch (const std::bad_alloc& e) {
       cerr << "Nicht genug Speicher: " << e.what() << endl;
       exit(-1);
   }
   // Jeden Kunden auslesen und Schlüssel, Position speichern.
   Customer buffer;
   long long pos = 0;
   unsigned long i;
   for( i = 0; i < count && buffer.read(file); ++i)
   { 
       indArr[i].setKey(buffer.getPIN() );
       indArr[i].setPos(pos);
       pos = file.tellg();   // Position des nächsten Kunden. 
   }
   if( i < count)      
       error("beim Lesen");  // Programm mit Fehlermeldung beenden.
   file.close();
   file.clear();             // Fehlerflags zurücksetzen.

   // Sortieren und in die Indexdatei schreiben:
   sort( indArr, indArr+count);
   indexFile.write((char*)indArr, sizeof(IndexEntry) * count);
   delete[] indArr;
}
