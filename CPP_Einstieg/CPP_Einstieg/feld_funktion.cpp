#include <iostream>
#include <array>
#include <vector>
using namespace std;

void ausgabeArray(const array<double,3> &preise)
{
   for(const double &p:preise)
      cout << p << " ";
   cout << endl;
}

void ausgabeVector(const vector<double> &preise)
{
   for(const double &p:preise)
      cout << p << " ";
   cout << endl;
}

int main()
{
   array<double,3> preiseEins = {1.45, 0.85, 0.75};
   ausgabeArray(preiseEins);

   vector<double> preiseZwei = {1.45, 0.85, 0.75};
   ausgabeVector(preiseZwei);
}

