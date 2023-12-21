
// ---------------------------------------------------------
// ex20_07.cpp
// Verwendet die Konvertierungsfunktion und den überladenen
// Operator <<, um Prüfungsergebnisse und den Durchschnitt
// auszugeben.
// ---------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

#define N_SCORES  4            // Anzahl Prüfungsergebnisse.

struct StudentScores
{   long id;
    short testScores[N_SCORES];
    operator double() const;   // Konvertierungsfunktion
}; 

StudentScores::operator double() const
{
    double sum = 0.0;
    for( int i=0; i < N_SCORES; ++i)
        sum += testScores[i];
    return sum / N_SCORES;
}

// Ausgabe in einen Stream:
ostream& operator<<(ostream& os, const StudentScores& s)
{
    os << s.id << " :";
    for( int i = 0; i < N_SCORES; ++i)
    {
       if( !(os << setw(5) << s.testScores[i]) )
          break;
    }
    return os;
}

void evaluation( const StudentScores& ss)
{
   double average = ss;           // = (double)ss
   cout << "Student " << ss.id;
   if( average > 90.0)
      cout << " hat die Pruefung mit Bravour bestanden!" 
           << endl;
   else if( average > 50.0)
      cout << " hat die Pruefung bestanden!" << endl;
   else
      cout << " hat die Pruefung nicht bestanden!" << endl;
}    

int main()
{
   // ID und Prüfungsergebnisse von zwei Studenten: 
    StudentScores student1 = { 13456, 91, 97, 89, 96},
                  student2 = { 25132, 41, 62,  0, 59}; 

   cout << "\nID        Pruefungsergebnisse      Durchschnitt\n"
           "---------------------------------------------------"
        << endl;
   cout << student1 << "        " << (double)student1 << endl;
   cout << student2 << "        " << (double)student2 << endl;
   cout << "---------------------------------------------------"
        << endl;

   cout << "\nAuswertung:" << endl;
   evaluation( student1);
   evaluation( student2);

   return 0;
}
