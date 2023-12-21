// ---------------------------------------------------------
// ex17_09.cpp
// Das Programm ruft die Standardfunktion strtok() auf, 
// um einen Vektor mit Zeigern auf die in einem String
// enthaltenen Worte zu erzeugen.
// ---------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS     // Für VC++ und strtok()
#include <cstring>
#include <iostream>
using namespace std;

char text[] = "  Anything\t:takes,,?longer;?than \n"
              "you?? \tthink! ";
char delim[] = " \t\n,.:;!?";    // Wortbegrenzer
char *words[100];                // Vektor von Zeigern

int main()
{
   int count = 0;                    // Anzahl Worte

   cout << "Der urspruengliche String: \n\n" << text << endl;

   // Das erste Wort: 
   char *ptr = strtok( text, delim);

   while(ptr != NULL && count < 100) // Noch ein Wort?
   {
      words[count++] = ptr;
      // Das nächste Wort:
      ptr = strtok( NULL, delim );
   }

   cout << "\nDie im String enthaltenen Worte:\n"
        << endl;
   for( int i=0; i < count; ++i)
       cout << words[i] << endl;
   cout << endl;

   return 0;
}
