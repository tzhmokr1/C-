// -----------------------------------------------------------
// studentScores.h
// Definiert die Struktur StudentScores und 
// einige inline-Funktionen.
// -----------------------------------------------------------
#ifndef _STUDENTSCORES_
#define _STUDENTSCORES_

#include <iostream>
#include <cstdlib>
using namespace std;

#define STUD_NUM  5      // Anzahl Studenten

struct StudentScores { long id;  short testScores[4]; }; 

inline void openError( const char* s)
{  cerr << "Fehler beim Oeffnen der Datei " << s << endl;
   exit(1);
}
inline void writeError( const char* s)
{  cerr << "Fehler beim Schreiben in die Datei " << s << endl;
   exit(2);
}
inline void readError( const char* s)
{  cerr << "Fehler beim Lesen aus der Datei " << s << endl;
   exit(3);
}
inline void closeError( const char* s)
{  cerr << "Fehler beim Schließen der Datei " << s << endl;
   exit(4);
}
#endif    // _STUDENTSCORES_
