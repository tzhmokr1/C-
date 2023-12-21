// ---------------------------------------------------------
// ex18_10.cpp
// Mischt zwei sortierte Dateien.
// ---------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

char inFile1[] = "SortedNum1.txt",
     inFile2[] = "SortedNum2.txt",
     outFile[] = "Merged.txt";

inline void openError( const char* s)
{  cerr << "Fehler beim Oeffnen der Datei " << s << endl;
   exit(1);
}
inline void writeError( const char* s)
{  cerr << "Fehler beim Schreiben in die Datei " << s << endl;
   exit(2);
}
inline void readError( const char* s)
{  cerr << "Fehler beim Lesen der Datei " << s << endl; 
   exit(3);
}

int main()
{
   cout << "Mischt die Dateien " << inFile1 << " und " << inFile2
        << endl;

   ifstream inf1( inFile1),         // Zum Lesen Öffnen
            inf2( inFile2);
   if( !inf1) 
     openError( inFile1);
   if( !inf2) 
     openError( inFile2);
   
   ofstream outf( outFile);         // Zum Schreiben öffnen
   if( !outf) 
     openError( outFile);

   // Das Mischen starten:
   int num1, num2, min;

   if( !(inf1 >> num1))
     readError( inFile1);

   if( !(inf2 >> num2))
     readError( inFile2);

   do
   {
       if( num1 <= num2)
       {
           min = num1;
           inf1 >> num1;
       }
       else
       {
           min = num2;
           inf2 >> num2;
       }
       outf << min << endl;        // Schreibt die kleinere Zahl
       if( !outf)                  // in die Ausgabedatei.
         writeError( outFile);
       
   }
   while( !inf1.fail() && !inf2.fail());

   if( inf1.eof())                 // Ende der ersten DAtei erreicht.
   {                               // Restliche Zahlen aus der zweiten
       do                          // Datei anhängen.
       { 
          outf << num2 << endl;
          if( !outf)
            writeError( outFile);
       }
       while( inf2 >> num2);
       if( !inf2.eof())
          readError( inFile2);
   }
   else if( inf2.eof())            // Ende der zweiten DAtei erreicht.
   {                               // Restliche Zahlen aus der ersten
       do                          // Datei anhängen.
       { 
          outf << num1 << endl;
          if( !outf)
            writeError( outFile);
       }
       while( inf1 >> num1);
       if( !inf1.eof())
          readError( inFile1);
   }

   cout << "\nMischen beendet!"
        << "\nDas Ergebnis steht in der Datei " << outFile
        << endl;

   // Die Dateien werden automatisch bei der Beendigung des Programms geschlossen.
   return 0;
}

