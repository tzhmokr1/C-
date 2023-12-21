#include <iostream>
using namespace std;

int main(int anzahl, char *para[])
{
   cout << "Anzahl: " << anzahl << endl;

   for(int i=0; i<anzahl; i++)
      cout << i << ": " << para[i] << endl;
}

