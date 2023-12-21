#include <iostream>
#include <ctime>
using namespace std;
int main()
{
   clock_t clockStart, clockEnde;
   int wert = 1;
   double anzahl = 690e6, differenz, durchlauf;

   for(int k=1; k<=5; k++)
   {
      clockStart = clock();
      for(int i=0; i<anzahl; i++)
         wert = -wert;
      clockEnde = clock();
      differenz = 1.0 * (clockEnde - clockStart) / CLOCKS_PER_SEC;
      durchlauf = differenz / anzahl * 1e9;

      cout << "Gesamt: " << differenz << " s." << endl;
      cout << "Durchlauf: " << durchlauf << " ns." << endl;
   }
}

