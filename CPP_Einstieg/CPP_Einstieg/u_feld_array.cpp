#include <iostream>
#include <array>
using namespace std;
int main()
{
   array<double,5> zahlen;

   for(int index=0; index<zahlen.size(); index++)
   {
      cout << "Eingabe " << index+1 << ". Zahl" << ": ";
      cin >> zahlen.at(index);
   }

   cout << "Feld in umgekehrter Reihenfolge:" << endl;
   for(int index=zahlen.size()-1; index>=0; index--)
      cout << zahlen.at(index) << " ";
   cout << endl;
}

