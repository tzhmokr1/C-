// ---------------------------------------------------- 
// ex01_10.cpp
// Modifizierung des Programms aus Übung 1.9.
// ---------------------------------------------------- 
#include <iostream>
using namespace std;

void star1(), star2(), star3();

int main()
{
   star3();    // Gibt 3*4 = 12 Sterne aus.
   star2();    // Gibt 2*4 = 8  Sterne aus.
   star1();    // Gibt 4  Sterne aus.
   star2();    // Gibt 8  Sterne aus.
   star3();    // Gibt 12 Sterne aus.
   return 0;
}

void star1() {  cout << "****" << endl; }

void star2() {  cout << "********" << endl; }

void star3() {  cout << "************" << endl; }
