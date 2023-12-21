#include <iostream>
using namespace std;
int main()
{
   double preisApfel = 1.45, preisBirne = 0.85, preisKiwi = 1.45;
   int anzahlApfel = 3, anzahlBirne = 5, anzahlKiwi = 3;

   if(preisApfel > preisBirne)
      cout << "Apfel kostet mehr als Birne" << endl;

   if(preisBirne < preisKiwi)
      cout << "Birne kostet weniger als Kiwi" << endl;

   if(anzahlBirne >= anzahlKiwi)
      cout << "Mindestens so viele Birnen wie Kiwis" << endl;

   if(anzahlKiwi <= anzahlBirne)
      cout << "Maximal so viele Kiwis wie Birnen" << endl;

   if(anzahlApfel == anzahlKiwi)
      cout << "Anzahl gleich" << endl;

   if(anzahlBirne != anzahlKiwi)
      cout << "Anzahl unterschiedlich" << endl;
}

