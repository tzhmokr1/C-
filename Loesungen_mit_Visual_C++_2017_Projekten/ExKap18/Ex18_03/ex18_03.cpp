// ---------------------------------------------------------
// ex18_03.cpp
// Das Programm liest einige Zeilen Text von der Tastatur
// und schreibt die aktuelle Zeit und den Text in die Datei
// "memo.txt".
// ---------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS      // Für VC++ und ctime()
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

char filename[] = "memo.txt";

inline void openError( char* s)
{  cerr << "Fehler beim Oeffnen der Datei " << s << endl; exit(1); }

inline void writeError(char* s)
{  cerr << "Fehler beim Schreiben in die Datei " << s << endl; exit(2); }

inline void readError(char* s)
{  cerr << "Fehler beim Lesen der Datei " << s << endl; exit(3); }

int main()
{
   char line[100];
   const int size = sizeof(line);
   int number = 0;

   fstream memoFile( filename, ios::out | ios::app);
   if( !memoFile)
       openError(filename);

   time_t sec = time(NULL);
   memoFile << ctime( &sec );    // Schreibt die aktuelle Zeit in die Datei

   cout << "Geben Sie Ihre Notiz ein:\n"
        << "(Ende mit einem Punkt in einer neuen Zeile)" << endl;
   
   while(cin.getline( line, size))  // Liest einige Zeilen Text von der Tastatur
   {                                // und schreibt sie in die Datei "memo.txt"
      if( line[0] == '.')
         break;
      if( !(memoFile << line << endl) )
         writeError(filename);
   }
   memoFile.close() ;

   memoFile.open( filename, ios::in);
   if( !memoFile)
      openError(filename);

   while(memoFile.getline(line, size))  // Gibt den Inhalt der Datei 
   {                                    // mit Zeilennummern am
      cout.width(5);                    // Bildschirm aus.
      cout << ++number << ": " << line << endl;
   }
   if( !memoFile.eof())
      readError(filename);

   return 0;
}
