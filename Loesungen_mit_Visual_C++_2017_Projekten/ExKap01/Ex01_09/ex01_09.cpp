// ---------------------------------------------------- 
// ex01_09.cpp
// Verfolgen Sie den Ablauf des folgenden C++-Programms 
// und beschreiben Sie, was auf dem Bildschirm 
// ausgegeben wird.
// ---------------------------------------------------- 
#include <iostream>
using namespace std;

void star1(), star2(), star3();

int main()
{
   star1();
   star2();
   star3();
   star2();
   star1();
   return 0;
}

void star1() {  cout << "****" << endl; }

void star2() {  cout << "********" << endl; }

void star3() {  cout << "************" << endl; }
