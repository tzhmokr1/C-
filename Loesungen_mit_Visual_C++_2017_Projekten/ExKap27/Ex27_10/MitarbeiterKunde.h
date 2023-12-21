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
    Person(const string& s= "") : name(s) {}
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
    {}
   
   const string& getAdresse() const { return adresse;}
   void  setAdresse(const string& adr) { adresse=adr;}
};

class Mitarbeiter: virtual public Person
{
  private:
    string bank;

  public:
    Mitarbeiter(const string& k ="", const string& s= "")
    : bank(k), Person(s)
    {}

   const string& getBank() const { return bank;}
   void  setBank(const string& k) { bank = k; }
};

class MitarbeiterKunde: public Mitarbeiter,
                        public Kunde
{
  public:
    MitarbeiterKunde (const string& s = "", 
                      const string& adr = "",  
                      const string& b = "")
    : Mitarbeiter(b), Kunde(adr), Person(s)
    {}
};

inline ostream& operator<<(ostream& os, 
                           const MitarbeiterKunde& m)
{ 
    os <<   "Name:    "  << m.getName() 
       << "\nAdresse: "  << m.getAdresse() 
       << "\nBank:    "  << m.getBank() << endl;
    return os;
}

inline istream& operator>>( istream& is, 
                            MitarbeiterKunde& m)
{ 
    string s1, s2, s3;
    cout << "Name der Person, Adresse "
            " und Bank eingeben: " << endl;
    if(is >> s1 >> s2 >> s3)      // Einlesen
    {
        m.setName(s1);
        m.setAdresse(s2);
        m.setBank(s3);
    }
    return is;
}
