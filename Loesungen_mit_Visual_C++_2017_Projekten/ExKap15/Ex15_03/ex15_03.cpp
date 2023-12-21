// ------------------------------------------------------
// ex15_03.cpp
// Was gibt folgendes Programm auf dem Bildschirm aus?
// ------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

class M
{
    string name;
  public:
    M( const string& n) : name(n) {}
    ~M(){ cout <<"Destruktor von " << name << endl; }
};



class Team
{
    M member1, member2;
  public:
    Team( const M& m1, const M& m2)    // Konstruktor
        : member1(m1), member2(m2) {}
    ~Team()
    { cout << "Destruktor der Klasse Team!" << endl; }
};



int main()
{
   M chief("Oliver"), poodle("Stan");
   Team aTeam( chief, poodle);
   cout << "Grossartiges Team!" << endl;
   return 0;
}
