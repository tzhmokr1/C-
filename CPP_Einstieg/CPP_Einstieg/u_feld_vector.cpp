#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector<double> zahlen;
   double eingabe;
   int weiter, nr = 1;

   do
   {
      cout << "Eingabe " << nr << ". Zahl " << ": ";
      cin >> eingabe;
      zahlen.push_back(eingabe);

      cout << "Noch eine Zahl (Ja=1, Nein=0)? ";
      cin >> weiter;
      nr++;
   }
   while(weiter == 1);

   cout << "Feld in umgekehrter Reihenfolge:" << endl;
   for(int index=zahlen.size()-1; index>=0; index--)
      cout << zahlen.at(index) << " ";
   cout << endl;
}

