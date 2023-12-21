// --------------------------------------------------------
// ex12_10.cpp
// Definiert und testet die Funktionen secToHMS(), die  
// eine Anzahl von Sekunden in die entsprechende Anzahl  
// von Stunden, Minuten und Sekunden umwandelt.
// --------------------------------------------------------
#include <iostream>
using namespace std;

void secToHMS(unsigned int& sec,     // Mit Referenz-Parametern
			  unsigned int& min,
              unsigned int& hours);

void secToHMS(unsigned int* psec,    // Mit Zeigern als Parametern
              unsigned int* pmin,
              unsigned int* phours);

void displayHMS(unsigned int s, unsigned int m, unsigned int h);

int main()
{
   unsigned int sec, seconds, minutes, hours;

   cout << "\nGeben Sie die Anzahl Sekunden ein: ";
   if( !(cin >> sec))
   {
       cerr << "Ungueltige Eingabe!" << endl;
       return 1;
   }

   // Ruft die Version mit Referenz-Parametern auf:
   seconds = sec;
   secToHMS( seconds, minutes, hours); 
   displayHMS( seconds, minutes, hours);

   // Ruft die Version mit Zeiger-Parametern auf:
   cout << "\nUnd jetzt mit der Zeiger-Version." << endl;
   seconds = sec;
   secToHMS( &seconds, &minutes, &hours); 
   displayHMS( seconds, minutes, hours);

   return 0;
}

void secToHMS( unsigned int& sec, unsigned int& min, 
               unsigned int& hours )
{
   unsigned int m = sec / 60;    // Anzahl Minuten
   sec   = sec % 60;
   min   = m % 60;
   hours = m / 60;
}

void secToHMS( unsigned int* psec, unsigned int* pmin, 
               unsigned int* phours ) 
{
   unsigned int m = *psec / 60;  // Anzahl Minuten
   *psec   = *psec % 60;
   *pmin   = m % 60;
   *phours = m / 60;
}

void displayHMS(unsigned int s, unsigned int m, unsigned int h)
{
   cout << "\n---------------------------"
        << "\nStunden:  " << h
        << "\nMinuten:  " << m
        << "\nSekunden: " << s << endl;
}

