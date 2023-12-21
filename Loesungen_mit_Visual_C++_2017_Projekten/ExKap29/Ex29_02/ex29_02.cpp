// ---------------------------------------------------------
// ex29_02.cpp
// Die Programmteile der Aufgabe 29.2.
// ---------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

struct Record { long id; /* ... */ }; 

void frage_a();
void frage_b();
void frage_c();

int main()
{
   // Datei Records.dat mit einem Datensatz erzeugen.
   fstream fs("Records.dat", ios::out | ios::binary); 
   if(!fs)
   {
       cerr << "Fehler beim Oeffnen!" << endl;
       return 1;
   }
   Record rec = { 123456 };
   fs.write((char*)&rec, sizeof(rec));
   fs.close();

   cout << "Frage a)" << endl;
   frage_a();
   cout << "Frage b)" << endl;
   frage_b();
   cout << "Frage c)" << endl;
   frage_c();

   return 0;
}

void frage_a()
{
    Record rec;
    fstream fs("Records.dat", ios::in | ios::out | ios::binary);
    if(!fs)
        cerr << "Fehler beim Oeffnen!" << endl;
    else
    {  fs.seekg(0);
       fs.read( (char*)&rec, sizeof(rec));       // 1. Datensatz.
       if(!fs)
           cerr << "Fehler beim Lesen!" << endl;
       else
       {   
           cout << "Datensatz-ID: " << rec.id << endl; 
           // 1. Datensatz aktualisieren ...
           rec.id = 234567;
           // und dann zurück schreiben:
           fs.seekp(0);
           if( !fs.write( (char*)&rec, sizeof(rec)) )
              cerr << "Fehler beim Schreiben!" << endl;
       }
       fs.close();
    }
}

void frage_b()
{
    Record rec;
    fstream fs("Records.dat", ios::in | ios::out | ios::binary ); 
if(!fs)
{
    cerr << "Fehler beim Oeffnen!" << endl;
    return;
}
    if( fs)
    {  // 1. Datensatz lesen:
       if( fs.read( (char*)&rec, sizeof(rec)) )
       {
         // Auf 2. Datensatz positionieren und zurück schreiben:
         fs.seekp(sizeof(rec));
         fs.write( (char*)&rec, sizeof(rec));
         fs.close();
       }
    }
}

float daten[5] =       // Vektor mit Messwerten
      { 10.11F, 9.92F, 9.83F, 10.24F, 10.05F };
unsigned int daten_len = sizeof(daten) / sizeof(daten[0]);

void frage_c()
{
    extern float daten[];             // Vektor mit Messwerten
    extern unsigned int daten_len;    // Anzahl Messwerte.

    ofstream ofs("Messwerte.dat", ios::out | ios::binary ); 
    if( ofs)
    {   // Messwerte in Datei speichern.
        ofs.write( (char*)daten, daten_len*sizeof(daten[0]) );
        ofs.close();
    }
    else
    {   cerr << "Fehler beim Oeffnen!" << endl;
        return;
    }

    ifstream ifs("Messwerte.dat", ios::in | ios::binary ); 
    if( ifs)
    {   // Messwerte einzeln einlesen:
        int count = 0; float x;
//       while( ifs >> x )
        while( ifs.read( (char*)&x, sizeof(x)) )
        {   ++count;  
            /* Wert in x verarbeiten. */ 
            cout << x << endl;
        }
        ifs.close();
        cout << "Anzahl Messwerte: " << count << endl;
    }
    else
       cerr << "Fehler beim Oeffnen zum Lesen!" << endl;
}
