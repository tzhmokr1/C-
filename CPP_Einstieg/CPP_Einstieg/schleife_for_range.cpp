#include <iostream>
using namespace std;
int main()
{
   double preisBirne = 0.85;
   
   for(int anzahl:{15, 29, 13})
   {
      double preisGesamt = anzahl * preisBirne;
      cout << anzahl << " Birnen: "
         << preisGesamt << " Euro" << endl;
   }
}

