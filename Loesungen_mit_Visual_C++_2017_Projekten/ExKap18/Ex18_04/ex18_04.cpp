// ---------------------------------------------------------
// ex18_04.cpp
// Die Funktion readID() die ID einer Datei. Die ID ist eine
// Zahl, die binär in den ersten vier Bytes der Datei 
// gespeichert ist.
// ---------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

bool readID( const char file[], long& id)
{
   bool ok = true;

   // Oeffnet die Datei zum Lesen im Binaermodus:
   fstream infile( file, ios::in | ios::binary);
   
   if(infile.fail())       // Falls die Datei nicht existiert
   {                       // oder falls ein Fehler beim
      id = -1;             // Oeffnen auftritt.
      ok = false;
   }
   else
   {                       // ID lesen.
      if( !infile.read((char*)&id, sizeof(long)) )
         ok = false;       // Fehler beim Lesen.
      infile.close();
   }
   return ok;
}

bool writeID( const char file[], long id)
{
   bool ok = true;

   // Oeffnet die Datei zum Schreiben im Binaermodus.
   // Falls die Datei bereits existiert, geht der
   // alte Inhalt verloren.
   fstream outfile( file, ios::out | ios::binary);

   if(!outfile)
   {
      ok = false;         // Fehler beim Oeffnen der Datei.
   }
   else
   {
      if( !outfile.write((char*)&id, sizeof(long)) )
         ok = false;      // Fehler beim Schreiben.
      outfile.close();
   }
   return ok;
}

char filename[] = "employee.dat";
long nID = 0L;

int main()
{
   if( !readID( filename, nID))
      if( nID < 0)
      {
         cout << "Die Datei " << filename << " existiert nicht!\n"
              << "Es wird eine neue Datei erzeugt!" << endl;
         if( !writeID( filename, 12345678))
         {
            cout << "Fehler beim Schreiben in die Datei " 
                 << filename << endl;
         }
         return 1;
      }
      else
      {
         cout << "Fehler beim Lesen der Datei " << filename << endl;
         return 2;
      }

   cout << "ID: " << nID << endl;

   return 0;
}
