#include <iostream>
#include <array>
using namespace std;
int main()
{
   array<double,3> preise = {1.45, 0.85, 0.75};

   try
   {
      cout << "Element 5 mit []: " << preise[5] << endl;
      cout << "Element 5 mit at(): " << preise.at(5) << endl;
      cout << "Ende des try-Blocks" << endl;
   }
   catch(exception &e)
   {
      cout << "Fehler: " << e.what() << endl;
   }
   
   cout << "Nach der Ausnahmebehandlung" << endl;
}

