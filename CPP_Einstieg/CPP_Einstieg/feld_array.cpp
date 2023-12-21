#include <iostream>
#include <array>
using namespace std;
int main()
{
   array<double,3> preise;

   preise.at(0) = 1.45;
   preise.at(1) = 0.85;
   preise.at(2) = 0.75;

   for(unsigned int index=0; index<preise.size(); index++)
      cout << "Element " << index << ": "
         << preise.at(index) << endl;

   double summe = 0.0;
   for(const double &p:preise)
      summe += p;
   cout << "Summe: " << summe << endl;
}

