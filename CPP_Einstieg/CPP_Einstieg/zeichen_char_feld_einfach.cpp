#include <iostream>
#include <cstring>
using namespace std;
int main()
{
   char zEins[20];
   zEins[0] = 'H';
   zEins[1] = 'a';
   zEins[2] = 'l';
   zEins[3] = 'l';
   zEins[4] = 'o';
   zEins[5] = '\0';
   cout << "Erstellen: " << zEins << endl;
   
   strcat(zEins, " Welt");
   cout << "Erweitern: " << zEins << endl;

   cout << "Anzahl der Zeichen: " << strlen(zEins) << endl;

   for(int i=0; i<=10; i++)
      cout << (int)zEins[i] << " ";
   cout << endl;

   strcpy(zEins, "Bonjour");
   cout << "Zuweisen: " << zEins << endl;

   if(!strcmp(zEins, "Bonjour"))
      cout << "Beide Texte sind gleich" << endl;

   char zZwei[] = "Good morning"; 
   cout << "Erstellen: " << zZwei << endl;

   if(strcmp(zEins, zZwei) < 0)
      cout << zEins << " steht vor " << zZwei << endl;
}

