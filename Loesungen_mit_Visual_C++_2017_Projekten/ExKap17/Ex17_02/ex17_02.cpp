// --------------------------------------------------------------
// ex17_02.cpp
// Was gibt das Programm auf dem Bildschirm aus?
// --------------------------------------------------------------
#include <iostream>
using namespace std;

char arr[] = "open sea";

int main()
{
   char *p = arr, 
        *q = arr + 4;

   cout << q - p << *q;
   
   p = ++q;
   while( p < q+3)
     cout << *p++;

   cout << *q << *arr << *(q-2) << *q << endl;

   return 0;
}
