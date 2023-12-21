#include <iostream>
#include <cstdarg>
using namespace std;

void addieren(const int &anzahl, ...)
{
   double summe = 0.0;
   va_list liste;

   va_start(liste, anzahl);
   for(int i=1; i<=anzahl; i++)
      summe += va_arg(liste, double);
   va_end(liste);

   cout << "Summe: " << summe << endl;
}

int main()
{
   addieren(2, 6.0, 7.5);
   addieren(4, -4.5, 5.0, 1.5, 3.2);
}

