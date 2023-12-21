// --------------------------------------------------------
// ex26_06.cpp
// Testet den Zugriffsproxy aus den Aufgaben 26.5 und 26.6
// --------------------------------------------------------
#include "proxy.h"

int main()
{
     Subject* p = new Proxy;  // Kommuniziert über das 
                              // polymorphe Interface.  

     p->request("Besitzer");
     p->request("Vorstand");
     p->request("Prokurist");
     p->request("Vorstand");
    
     return 0;
}
