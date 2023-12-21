#include <iostream>
#include <string>
#include <sys/stat.h>
#include <dirent.h>
using namespace std;

void listeVerzeichnis(string verzeichnisName)
{
   DIR *verzeichnisZeiger;
   struct dirent *eintragZeiger;
   struct stat attr;
   string pfadName;

   verzeichnisZeiger = opendir(verzeichnisName.c_str());
   while((eintragZeiger = readdir(verzeichnisZeiger)))
   {
      string dn = eintragZeiger->d_name;
      if(dn != "." && dn != "..")
      {
         pfadName = verzeichnisName + "/" + dn;
         cout << pfadName << endl;

         stat(pfadName.c_str(), &attr);
         if(attr.st_mode & S_IFDIR)
            listeVerzeichnis(pfadName);
      }
   }
   closedir(verzeichnisZeiger);
}

int main()
{
   listeVerzeichnis("C:/Temp");
}

