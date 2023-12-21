#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
   string kommando = "ls -l s*.cpp";
   system(kommando.c_str());
   kommando.at(6) = 'a';
   system(kommando.c_str());
}

