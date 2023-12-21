// ---------------------------------------------------------
// ex19_07.cpp
// Liest Pr�fungsergebnisse von Studenten aus einer Datei 
// und zeigt sie auf dem Bildschirm an. Es werden die
// �berladenen Operatoren << und >> verwendet.
// ---------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define N_SCORES  4        // Anzahl Pr�fungsergebnisse.
struct StudentScores { long id; 
                       short testScores[N_SCORES]; };

// Operatorfunktionen:
istream& operator>>(istream& is, StudentScores& s)
{
    is >> s.id;
    for( int i = 0; i < N_SCORES; ++i)
    {
       if( !(is >> s.testScores[i]) )
          break;
    }
    return is;
}

ostream& operator<<(ostream& os, const StudentScores& s)
{
    os << s.id;
    for( int i = 0; i < N_SCORES; ++i)
    {
       if( !(os << '\t' << s.testScores[i]) )
          break;
    }
    return os;
}

// inline-Funktionen:
inline void openError( const char* s)
{  cerr << "Fehler beim Oeffnen der Datei " << s << endl;
   exit(1); 
}

inline void readError( const char* s)
{  cerr << "Fehler beim Lesen der Datei " << s << endl;
   exit(3); 
}

char filename[] = "testScores.txt";

int main()
{
   // ID und Pr�fungsergebnisse eines Studenten: 
   StudentScores student;

   ifstream ifile(filename);           // �ffnet die Datei 
   if( !ifile)                         // zum Lesen.
       openError(filename);

   cout << "\nID      Pruefungsergebnisse\n"
           "---------------------------------------------"
        << endl;

   while( ifile >> student)           // Liest die Daten ein 
       cout << student << endl;       // und gibt sie aus.

   cout << "---------------------------------------------"
        << endl;

   if( !ifile.eof())
      readError(filename);
   ifile.close();                     // Schlie�t die Datei.
   return 0;
}
