#include <iostream>
using namespace std;
int main()
{
   int tag, monat, jahr;

   cout << "Tag des Datums eingeben: ";
   cin >> tag;

   cout << "Monat des Datums eingeben: ";
   cin >> monat;

   cout << "Jahr des Datums eingeben: ";
   cin >> jahr;

   if(monat == 4 || monat == 6 || monat == 9 || monat == 11)
   {
      cout << "Letzter Tag: 30" << endl;
      if(tag < 0 || tag > 30)
         cout << "Falsches Datum" << endl;
      else
         cout << "Richtiges Datum" << endl;
   }
   else if(monat == 2)
   {
      if(jahr%4 == 0 && jahr%100 != 0 || jahr%400 == 0)
      {
         cout << "Letzter Tag: 29" << endl;
         if(tag < 0 || tag > 29)
            cout << "Falsches Datum" << endl;
         else
            cout << "Richtiges Datum" << endl;
      }
      else
      {
         cout << "Letzter Tag: 28" << endl;
         if(tag < 0 || tag > 28)
            cout << "Falsches Datum" << endl;
         else
            cout << "Richtiges Datum" << endl;
      }
   }
   else
   {
      cout << "Letzter Tag: 31" << endl;
      if(tag < 0 || tag > 31)
         cout << "Falsches Datum" << endl;
      else
         cout << "Richtiges Datum" << endl;
   }
}

