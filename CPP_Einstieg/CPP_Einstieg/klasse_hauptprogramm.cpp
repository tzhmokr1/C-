#include <iostream>
#include <string>
using namespace std;

#include "klasse_methoden.cpp"

int main()
{
   postenTyp pEins;
   pEins.werteZuweisen(2, 1.45, "Apfel");
   pEins.ausgeben();
   
   postenTyp pZwei = pEins;
   pZwei.ausgeben();
}

