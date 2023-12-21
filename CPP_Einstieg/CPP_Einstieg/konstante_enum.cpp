#include <iostream>
using namespace std;
int main()
{
   enum farbe { SCHWARZ, GELB, BLAU=8, ORANGE };
   farbe fa;
   fa = GELB;
   cout << "Farbe: " << fa << endl;
   fa = ORANGE;
   cout << "Farbe: " << fa << endl;
}
