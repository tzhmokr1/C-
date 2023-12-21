#include <iostream>
using namespace std;
int main()
{
   int anzahl = 2;   cout << "Wert " << anzahl << endl;
   
   anzahl += 5;      cout << "+= 5 ergibt " << anzahl << endl;
   anzahl -= 3;      cout << "-= 3 ergibt " << anzahl << endl;
   anzahl *= 4;      cout << "*= 4 ergibt " << anzahl << endl;
   anzahl /= 2;      cout << "/= 2 ergibt " << anzahl << endl;
   
   anzahl++;         cout << "++ ergibt " << anzahl << endl;
   anzahl--;         cout << "-- ergibt " << anzahl << endl;
   ++anzahl;         cout << "++ ergibt " << anzahl << endl;
   --anzahl;         cout << "-- ergibt " << anzahl << endl;
}

