// ---------------------------------------------------------
// ex18_05W.cpp
// Schreibt Prüfungsergebnisse in die Datei testScores.txt.
// ---------------------------------------------------------
#include <iostream>
#include <fstream>
#include "studentScores.h"
using namespace std;

char filename[] = "testScores.txt";

int main()
{
   int count = 0;
   // IDs von Studenten und die Prüfungsergebnisse:
   StudentScores students[STUD_NUM] = {
       { 12345, 82, 56, 67, 95}, 
       { 54321, 92, 69, 85, 59},
       { 23456, 92, 97, 89, 96},
       { 65432, 58, 62, 70, 59}, 
       { 34567, 91, 69, 84, 69}
   };

   ofstream ofile(filename);        // Datei zum Schreiben 
   if( !ofile)                      // öffnen.
       openError(filename);

   for(int i = 0; i < 5; i++)       // Daten in die Datei 
   {                                // schreiben. 
      ofile << students[i].id;
      for( int j = 0; j < 4; j++)
      {
         if( !(ofile << '\t' << students[i].testScores[j]) )
            writeError(filename);
      }
      ofile << endl;
      ++count;
   }
   ofile.close();                   // Datei schließen.
   if( !ofile)
       closeError(filename);

   cout << "\nAnzahl Datensätze, die in die Datei "
        << filename << " geschrieben wurden: "
        << count << endl; 

   return 0;
}
