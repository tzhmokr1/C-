#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
   string kommando = "dir s*.cpp";
   system(kommando.c_str());
   kommando.at(4) = 'a';
   system(kommando.c_str());
}

