#include <iostream>
#include <string>
#include <sys/stat.h>
using namespace std;

void rechte(string datei)
{
   struct stat attr;
   string vektor = "---------";
   stat(datei.c_str(), &attr);
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
}

int main()
{
   char datei[] = "hallo.cpp";
   rechte(datei);
   chmod(datei, S_IRUSR);
   rechte(datei);
   chmod(datei, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR);
   rechte(datei);
}

