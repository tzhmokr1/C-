#include <iostream>
#include <sstream>
using namespace std;

int main(int anzahl, char *para[])
{
   double zahl, summe = 0.0;
   istringstream eingabeStrom;

   for(int i=1; i<anzahl; i++)
   {
      eingabeStrom.str(para[i]);
      eingabeStrom >> zahl;
      summe += zahl;
      eingabeStrom.clear();
   }

   cout << "Summe: " << summe << endl;
}

