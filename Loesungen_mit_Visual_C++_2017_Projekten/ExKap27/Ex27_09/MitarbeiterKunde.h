// --------------------------------------------------
// MitarbeiterKunde.h
// Klassen Person, Kunde, Mitarbeiter und 
// MitarbeiterKunde
// --------------------------------------------------

#include <string>
#include <iostream>
using namespace std;

class Person
{
  private:
   string name;

  public:

   Person(const string& s= "") : name(s) 
   { 
      cout << "Konstruktor von Person." << endl; 
   }

   const string&  getName() const { return name; }
   void setName( const string& s) { name = s; }
};

class Kunde : virtual public Person
{
  private:
   string adresse;

  public:
 
   Kunde(const string& adr= "", const string& s= "") 
         : adresse(adr), Person(s)
   {
     cout << "Konstruktor von Kunde." <<  endl;
   }
   
   const string& getAdresse() const { return adresse;}
   void   setAdresse(const string& adr){ adresse=adr;}
};

class Mitarbeiter: virtual public Person
{
  private:
   string bank;

  public:
   Mitarbeiter(const string& b ="",const string& s= "")
              : bank(b), Person(s)
   {
     cout << "Konstruktor von Mitarbeiter." << endl;
   }

   const string& getBank() const { return bank;}
   void  setBank(const string& k) { bank = k; }
};

class MitarbeiterKunde: public Mitarbeiter, public Kunde
{
  public:
   MitarbeiterKunde (const string& s = "", 
                     const string& adr = "",  
                     const string& b = "")
   : Mitarbeiter(b), Kunde(adr), Person(s)
   {
     cout << "Konstruktor von MitarbeiterKunde." << endl;
   }
};

inline ostream& operator<<(ostream& os, 
                           const MitarbeiterKunde& m)
{ 
    os <<   "Name:    "  << m.getName() 
       << "\nAdresse: "  << m.getAdresse() 
       << "\nBank:    "  << m.getBank() << endl;
    return os;
}

