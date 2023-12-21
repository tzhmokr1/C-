#include <iostream>
// #include <sys/stat.h>
#include <unistd.h>
// #include <linux/limits.h>
// #include <sys/syslimits.h>
// #define PATH_MAX 255
using namespace std;
int main()
{
   char vFeld[PATH_MAX];
   cout << "Max. Pfadname: " << PATH_MAX << endl;
   if(!getcwd(vFeld, PATH_MAX))
   {
      cout << "Keine Abfrage des Verzeichnisnamens" << endl;
      return 1;
   }
   cout << vFeld << endl;

   if(mkdir("neu"))
   // if(mkdir("neu", S_IRUSR | S_IWUSR | S_IXUSR))  // Linux
   {
      cout << "Kein Erzeugen des Verzeichnisses" << endl;
      return 1;
   }

   if(chdir("neu"))
   {
      cout << "Kein Wechsel des Verzeichnisses";
      return 1;
   }

   getcwd(vFeld, PATH_MAX);
   cout << vFeld << endl;
   chdir("..");

   if(rmdir("neu"))
   {
      cout << "Kein Entfernen des Verzeichnisses" << endl;
      return 1;
   }

   getcwd(vFeld, PATH_MAX);
   cout << vFeld << endl;
}

