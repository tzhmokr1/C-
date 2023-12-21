#include <iostream>
using namespace std;
int main()
{
   double preis = 1.45;
   int preisKategorie;

   preisKategorie = preis >= 1.0 ? 2 : 1;
   cout << "Kategorie: " << preisKategorie << " von 2" << endl;

   preisKategorie = preis >= 1.0 ? (preis >= 2.0 ? 3 : 2) : 1;
   cout << "Kategorie: " << preisKategorie << " von 3" << endl;

   cout << (preis >= 1.0 ? "Ein teurer Artikel"
      : "Ein preiswerter Artikel") << endl;
}

