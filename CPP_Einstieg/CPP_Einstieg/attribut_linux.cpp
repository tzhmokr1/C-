#include <iostream>
#include <string>
#include <iomanip>
#include <sys/stat.h>
#include <ctime>
using namespace std;

void zeit(time_t *ttz)
{
   struct tm zugriff = *localtime(ttz);

   cout << setfill('0');
   cout << setw(2) << zugriff.tm_mday << ".";
   cout << setw(2) << zugriff.tm_mon + 1 << ".";
   cout << zugriff.tm_year + 1900 << " ";
   cout << setw(2) << zugriff.tm_hour << ":";
   cout << setw(2) << zugriff.tm_min << ":";
   cout << setw(2) << zugriff.tm_sec << endl;
}

int main()
{
   struct stat attr;
   if(stat("hallo.cpp", &attr))
   {
      cout << "Kein Zugriff auf Dateiattribute" << endl;
      return 1;
   }
   
   if(attr.st_mode & S_IFREG)
      cout << "Datei" << endl;
   else if(attr.st_mode & S_IFDIR)
      cout << "Verzeichnis" << endl;

   string vektor = "---------";
   if(attr.st_mode & S_IRUSR) vektor.at(0) = 'r';
   if(attr.st_mode & S_IWUSR) vektor.at(1) = 'w';
   if(attr.st_mode & S_IXUSR) vektor.at(2) = 'x';
   if(attr.st_mode & S_IRGRP) vektor.at(3) = 'r';
   if(attr.st_mode & S_IWGRP) vektor.at(4) = 'w';
   if(attr.st_mode & S_IXGRP) vektor.at(5) = 'x';
   if(attr.st_mode & S_IROTH) vektor.at(6) = 'r';
   if(attr.st_mode & S_IWOTH) vektor.at(7) = 'w';
   if(attr.st_mode & S_IXOTH) vektor.at(8) = 'x';
   cout << "Zugriffsrechte: " << vektor << endl;

   cout << "UID: " << attr.st_uid << endl;;
   cout << "GID: " << attr.st_gid << endl;;

   cout << "Byte: " << attr.st_size << endl;

   cout << "Letzter Zugriff: ";
   zeit(&(attr.st_atime));
   cout << "Letzte Aenderung: ";
   zeit(&(attr.st_mtime));
   cout << "Letzte Aenderung Status: ";
   zeit(&(attr.st_ctime));
}


