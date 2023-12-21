// -------------------------------------------
// PersonalProdukt.h
// Klassen Produkt und PersonalProdukt 
// -------------------------------------------

#include "MitarbeiterKunde.h"

#define MAX 3

class Produkt
{
  private:
    string prod;
  public:
    Produkt(const string& p = "") : prod(p) {}

    void setProdukt(const string& p){ prod = p;}
    const string& getProdukt() const{ return prod;}
};

inline ostream& operator<<(ostream& os, const Produkt& p)
{ 
    os << "  Produkt: "  << p.getProdukt() << endl; 
    return os;
}

inline istream& operator>>(istream& is, Produkt& p)
{ 
    string s;
    cout << "Produkt eingeben: " << endl;
    if(is >> s)                        // Einlesen
       p.setProdukt(s);

    return is;
}


class PersonalProdukt
{
  private:
    MitarbeiterKunde mkv[MAX];
    Produkt pv[MAX];
    int len;
  
  public:
    PersonalProdukt() : len(0) {}

    int  length() const { return len; }
    bool add(const MitarbeiterKunde& m, const Produkt& p)
    {
       if(len < MAX)
       {
         mkv[len] = m;
         pv[len] = p;
         len++;
         return true;
       }
       else 
         return false;
     }

    const Produkt& getProdukt(int i) const 
    { 
       if(i >=0 && i < len) 
         return pv[i]; 
       else
         cerr << "Unzulaessiger Index ", exit(1); 
    }

    const MitarbeiterKunde& getMitarbeiterKunde(int i)
                                                const 
    { 
       if(i >=0 && i < len) 
          return mkv[i];
       else
          cerr << "Unzulässiger Index ", exit(1); 
    }
};

inline ostream& operator<<( ostream& os, 
                            const PersonalProdukt& p)
{ 
    for(int i= 0; i < p.length(); i++)
        os <<  p.getMitarbeiterKunde(i)
           <<  p.getProdukt(i) << endl;
    return os;
}

inline istream& operator>>(istream& is, 
                           PersonalProdukt& p)
{ 
    MitarbeiterKunde mk;
    Produkt pr;

    cin >> mk;
    cin >> pr; 
 
    if(!p.add(mk, pr))
        cerr << "Fehler: Vektor voll!" << endl;

    return is;
}
