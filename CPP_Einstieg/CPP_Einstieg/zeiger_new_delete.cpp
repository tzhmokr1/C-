#include <iostream>
using namespace std;
int main()
{
   /* Einfacher Zeiger auf einzelne Variable */
   int *zi = new int;
   *zi = 42;
   cout << "Variable: " << *zi << endl;
   delete zi;

   /* Einfacher Zeiger auf einfaches dynamisches Feld von int */
   int *zf, anzahl;
   cout << "Anzahl der Elemente: ";
   cin >> anzahl;

   zf = new int[anzahl];
   cout << "Werte: ";
   for(int i=0; i<anzahl; i++)
   {
      zf[i] = 10 * i;
      cout << zf[i] << " ";
   }
   cout << endl;
   delete[] zf;
}
