#include <iostream>
using namespace std;
int main()
{
   bool x;
   x = true;   cout << "true:  " << x << endl;
   x = false;  cout << "false: " << x << endl;
   x = 1;      cout << "1:     " << x << endl;
   x = 0;      cout << "0:     " << x << endl;
   x = -1.5;   cout << "-1.5:  " << x << endl;

   double preisApfel = 1.45, preisBirne = 0.85, preisBanane = 0.75;
   bool apfelTeuer = preisApfel >= 1.0;
   bool birneTeuer = preisBirne >= 1.0;
   bool bananeTeuer = preisBanane >= 1.0;

   if(apfelTeuer || birneTeuer)
      cout << "Mindestens einer der Artikel ist teuer" << endl;
   if(!bananeTeuer)
      cout << "Artikel ist nicht teuer" << endl;
   if(!birneTeuer && !bananeTeuer)
      cout << "Beide Artikel sind nicht teuer" << endl;
}

