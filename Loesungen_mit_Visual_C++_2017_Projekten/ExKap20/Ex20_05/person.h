// ---------------------------------------------------------
// person.h
// Definiert die Klasse Person.
// ---------------------------------------------------------
#ifndef _PERSON_
#define _PERSON_

#include <iostream>
#include <string>
using namespace std;

class Person
{
   private: 
     unsigned long pin;
     string name;

   public:
     Person( unsigned long id = 0, const string& n = "")
     : pin(id), name(n) {}

     // Gibt die Datenelemente auf dem Bildschirm aus:
     void display() { cout << pin << "   " << name << endl; }  

     // Konvertierungsfunktionen:
     // explicit 
     operator string () const { return name; }
     // explicit 
     operator long ()   const { return pin; }
};

#endif // _PERSON_