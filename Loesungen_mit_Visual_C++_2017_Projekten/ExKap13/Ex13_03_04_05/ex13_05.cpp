// ------------------------------------------------------
// ex13_05.cpp
// Testet die Klasse PiggyBank.
// ------------------------------------------------------
#include "piggyBank.h"
#include <iostream>
using namespace std;

void showCoins(unsigned int c1,  unsigned int c10,
               unsigned int c50, unsigned int e1)
{
   if( c1  > 0)  cout << c1  << " 1-Cent Stuecke"  << endl;
   if( c10  > 0) cout << c10 << " 10-Cent Stuecke" << endl;
   if( c50 > 0)  cout << c50 << " 50-Cent Stuecke" << endl;
   if( e1 > 0)   cout << e1  << " 1-Euro Stuecke"  << endl;
}

int main()
{
   unsigned int c1=0, c10=0, c50=0, e1=0;
   PiggyBank myPiggy;
   myPiggy.init(500); 

   if(myPiggy.isEmpty())
      cout << "Das Sparschwein ist leer!" << endl;

   while( !myPiggy.isFull())
   {
     cout << "\nErsparnisse machen gluecklich!" << endl;
     cout << "Werfen Sie einige 1-Cent Stuecke ein: "; 
     if( !(cin >> c1) || myPiggy.add1Cents(c1) != 0) break;

     cout << "Werfen Sie einige 10-Cent Stuecke ein: ";
     if( !(cin >> c10) || myPiggy.add10Cents(c10) != 0) break;

     cout << "Werfen Sie einige 50-Cent Stuecke ein: ";
     if( !(cin >> c50) || myPiggy.add50Cents(c50) != 0) break;

     cout << "Werfen Sie einige Euros ein: ";
     if( !(cin >> e1) || myPiggy.add1Euros(e1) != 0)
        break;
     cout << "Vielen Dank!" << endl;
   }

   if( myPiggy.isFull())
      cout << "\nDas Sparschwein ist voll!" << endl;

   cout << "Das Sparschwein wird geschlachtet!" << endl;
   unsigned long cents = myPiggy.breakInto(c1, c10, c50, e1);

   cout << "Im Sparschwein waren: "
        << endl;
   showCoins( c1, c10, c50, e1);

   cout << "Das sind " << cents/100 << " Euros und "
        << cents%100 << " cents."
        << "\n\nGratuliere!" << endl;

   return 0;
}
