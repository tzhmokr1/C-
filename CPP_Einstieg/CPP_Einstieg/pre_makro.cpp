#include <iostream>
#define ANZAHL 5
#define QUADRAT(x) ( (x) * (x) )
#define BETRAG(x)  ( (x)>0 ? (x) : -(x) )
using namespace std;
int main()
{
   int a = 2;
   cout << ANZAHL << endl;
   cout << QUADRAT(4) << endl;
   cout << QUADRAT(2.5) << endl;
   cout << QUADRAT(4 + a) << endl;
   cout << BETRAG(-4) << endl;
   cout << BETRAG(-2.5) << endl;
   cout << 8 - BETRAG(a - 7) << endl;
   cout << "Zeile " << __LINE__ << " in Datei " << __FILE__ << endl;
   cout << "Kompiliert: " <<  __DATE__ << " " << __TIME__ << endl;
}

