//-----------------------------------------------------
// proxy.cpp
// Definition der Methoden request() und find() 
// der Klasse Proxy.
//-----------------------------------------------------

#include "proxy.h"

static string allowed[]={"Geschäftsführer", "Vorstand",
                         "Besitzer", ""}; 
       
bool Proxy::find(string name)
{ 
  for(int i=0; allowed[i] != ""; i++)
     if(allowed[i] == name)
        return true;
  return false;
}

void Proxy::request(string name)    
{ 
  if( !find(name))            // Zugriffskontrolle.
  {
    cout << "Kein Zugriff fuer " << name << endl; 
    return;
  }

  if( realSubject == NULL )              
  {                           // Objekt erst bei Bedarf 
    realSubject = new RealSubject();        // anlegen.
    cout << "Objekt angelegt." << endl;
  }

  realSubject->request(name);  // Request an Objekt 
                               // weiterleiten.
}
