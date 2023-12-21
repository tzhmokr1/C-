// ---------------------------------------------------------
// ex29_07.cpp
// Das Programm ermittelt alle Primzahlen mithilfe des Siebs 
// von Eratosthenes bis zu einer Obergrenze, die das Programm
// zunächst vom Anwender einliest.

// Um nicht durch die maximale Größe eines dynamisch 
// erzeugten Arrays begrenzt zu sein, verwendet das Programm 
// statt eines Arrays eine temporäre Datei.
// Die Primzahlen werden in der Textdatei "primes.txt"
// gespeichert (5 pro Zeile, durch Tabulatoren getrennt).
// Die Dateien werden im aktuellen Verzeichnis erstellt.  
// ---------------------------------------------------------
#include <cstdlib>   // Für exit() und atexit()
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

inline void openError( char* s)
{  cerr << "Fehler beim Oeffnen der Datei " << s << endl; exit(1); }

inline void writeError(char* s)
{  cerr << "Fehler beim Schreiben in die Datei " << s << endl; exit(2); }

inline void readError(char* s)
{  cerr << "Fehler beim Lesen der Datei " << s << endl; exit(3); }

inline void positionError(char* s)
{  cerr << "Fehler bei der Positionierung in der Datei " << s << endl; exit(4); }

char sieveFilename[]     = "sieve.txt",    // Die Datei zum "Sieben",
     primesTxtFilename[] = "primes.txt";   // zum Speichern der Primzahlen.

void cleanup()
{ 
    cerr << "Datei " << sieveFilename << " wird geloescht." << endl;
//    remove(sieveTmpFilename);      // Sieb-Datei löschen.
}

int main()
{
   long limit = 0,         // Obergrenze für die Primzahlen.
        filesize;          // Länge der Sieb-Datei.
   long n,                 // Eine Zahl <= limit. 
        count,             // Zähler für die Primzahlen.
        i, j;              // Positionen in der Sieb-Datei.

   atexit( cleanup);
   cout << "Bestimmung der Primzahlen mit dem Sieb des Eratosthenes\n\n"
        << "Bitte Obergrenze eingeben: ";
   if( !(cin >> limit) || limit < 2)
   {
       cerr << "Fehlerhafte Eingabe" << endl;
       return 1;
   }
   filesize = (limit+1)/2; 

   // Es werden nur ungerade Zahlen untersucht.
   // Position i in der "Sieb-Datei" entspricht der ungeraden Zahl n = 2*i+1
   // Position i speichert '1', falls die Zahl 2*i+1 eine Primzahl ist, sonst '0'.

   fstream sieveFile( sieveFilename, ios::in | ios::out | ios::trunc);
   if( !sieveFile)
       openError( sieveFilename);

   // Vorbelegung. 
   sieveFile.put('0');                // Zahl 1 ist keine Primzahl.

   for( i=1; i < filesize; ++i)       // Zum "sieben" mit '1' vorbelegen.
      if( !sieveFile.put('1') ) 
         writeError( sieveFilename);

   // Sieben:
   // Falls n eine Primzahl ist, werden alle ungeraden Vielfachen
   // von n "gestrichen", also 3*n, 5*n, ...
   char c = '0';
   for( i = 1; i <= filesize/3; ++i)
   {
      if( !sieveFile.seekg(i))
         positionError( sieveFilename);

      if( !sieveFile.get(c)  ) 
         readError( sieveFilename);

      if( c == '1')            // Ist n = 2*i+1 eine Primzahl?
      {                        // Ja -> ungerade Vielfache löschen.
         n = 2*i + 1;          // Die Positionen sind i+n, i+2n, ...
         for( j = i+n; j < filesize; j += n)
         {
            if( !sieveFile.seekp(j))
               positionError( sieveFilename);
            if( !sieveFile.put('0') ) 
               writeError( sieveFilename);
         }
      }
   }

   // Primzahlen als Text speichern:
   ofstream primesTxtFile( primesTxtFilename);
   if( !primesTxtFile)
       openError( primesTxtFilename);

   primesTxtFile << setw(10) << 2 << '\t';   // 2 ist die erste Primzahl.
   count = 1;

   if( !sieveFile.seekg(1))                  // Sieb durchlaufen.
      positionError( sieveFilename);
   
   for( i = 1; i < filesize; ++i)
   {
      if( !sieveFile.get(c)  ) 
         readError( sieveFilename);

      if( c == '1')            // Ist n = 2*i+1 eine Primzahl?
      {                        // Ja -> Zahl speichern.
         n = 2*i + 1;
         primesTxtFile << setw(10) << n;
         if( !primesTxtFile)
             writeError( primesTxtFilename);
         ++count;
         primesTxtFile << (count % 5 != 0 ? '\t' : '\n');
      }
   }
   primesTxtFile << '\n';

   sieveFile.close();
   cout << "Es gibt " << count << " Primzahlen kleiner oder gleich " 
        << limit << '.' << endl;
   cout << "Die Primzahlen wurden in der Textdatei " << primesTxtFilename
        << " gespeichert." << endl;

   return 0;       // Offene Dateien werden geschlossen und 
                   // die Sieb-Datei gelöscht.
}
