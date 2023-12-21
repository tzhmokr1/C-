#include <iostream>
using namespace std;
int main()
{
   double preisApfel = 1.45, preisBirne = 0.85, preisBanane = 0.75;

   if(preisBirne < 1.0 && preisBanane < 1.0)
      cout << "Beide Artikel sind preiswert" << endl;

   if(preisApfel >= 1.0 || preisBirne >= 1.0)
      cout << "Mindestens einer der Artikel ist teuer" << endl;

   if(!(preisBanane >= 1.0))
      cout << "Artikel ist nicht teuer" << endl;
}

