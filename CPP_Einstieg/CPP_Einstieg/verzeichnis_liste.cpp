#include <iostream>
#include <dirent.h>
using namespace std;

int main()
{
   DIR *verzeichnisZeiger;
   struct dirent *eintragZeiger;

   if(!(verzeichnisZeiger = opendir("C:/Temp")))
   {
      cout << "Kein Lesen des Verzeichnisses" << endl;
      return 1;
   }

   while((eintragZeiger = readdir(verzeichnisZeiger)))
      if(eintragZeiger->d_name[0] == 'b')
         cout << eintragZeiger->d_name << endl;

   rewinddir(verzeichnisZeiger);

   while((eintragZeiger = readdir(verzeichnisZeiger)))
      if(eintragZeiger->d_name[0] == 'k')
         cout << eintragZeiger->d_name << endl;

   closedir(verzeichnisZeiger);
}

