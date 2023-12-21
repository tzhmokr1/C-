// ---------------------------------------------------------
// ex18_05R.cpp
// Liest Prüfungsergebnisse aus der Datei testScores.txt.
// ---------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include "studentScores.h"
using namespace std;

char filename[] = "testScores.txt";

int main()
{
   int i=0, j=0;
   // IDs von Studenten und die Prüfungsergebnisse:
   StudentScores students[STUD_NUM];

   ifstream ifile(filename);           // Datei zum Lesen 
   if( !ifile)                         // öffnen.
       openError(filename);

   for(i = 0; i < STUD_NUM; i++)       // Daten aus der 
   {                                   // Datei einlesen. 
      ifile >> students[i].id;
      for( j = 0; j < 4; j++)
      {
         if( !(ifile >> students[i].testScores[j]) )
            break;
      }
   }
   if( i < 5)
       readError(filename);
   ifile.close();                      // Datei schließen.
   if( !ifile)
       closeError(filename);

   // Daten anzeigen:
   cout << "\n Nr | Student's id |    Test scores"
           "\n---------------------------------------------"
        << endl;
   for(i = 0; i < STUD_NUM; i++)
   {
      cout << setw(3)  << i << " | "   
           << setw(12) << students[i].id << " | ";  // ID 
      for( j = 0; j < 4; j++)                       // Prüfungsergebniss
         cout << setw(5) << students[i].testScores[j];
      cout << endl;
   }

   return 0;
}
