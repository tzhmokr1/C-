#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector<vector<int>> zFeld;

   int zeilenAnzahl;
   cout << "Anzahl der Zeilen: ";
   cin >> zeilenAnzahl;

   int spaltenAnzahl;
   cout << "Anzahl der Spalten: ";
   cin >> spaltenAnzahl;

   zFeld.resize(zeilenAnzahl);
   for(unsigned int i=0; i<zFeld.size(); i++)
      zFeld.at(i).resize(spaltenAnzahl);

   for(unsigned int i=0; i<zFeld.size(); i++)
      for(unsigned int k=0; k<zFeld.at(i).size(); k++)
         zFeld.at(i).at(k) = 10 + i*10 + k;

   for(vector<int> &zeile:zFeld)
   {
      for(int &wert:zeile)
         cout << wert << " ";
      cout << endl;
   }
}

