// ---------------------------------------------------------
// ex22_05.cpp
// Verwendet die Klasse JobList.
// ---------------------------------------------------------
#include <iostream>
#include "jobList.h"
using namespace std;

int main()
{
   JobList myJobs;
   const Job aJob("Mails beantworten.");

   // Jobs einfuegen;
   myJobs.pushBack( aJob);
   myJobs.pushBack( Job("Chef zurueckrufen!"));
   myJobs.pushBack( Job("Meeting vorbereiten."));

   cout << "\n\t *****  Auftragsliste  *****\n" << endl;

   myJobs.print();          // Alle Auftraege anzeigen.

   // Kopie der Liste anlegen:
   JobList yourJobs(myJobs);

   yourJobs.print();          // Alle Auftraege anzeigen.
   cout << "Die Liste hat " << yourJobs.getCount()
        << " Auftraege." << endl;

   // Zuweisung testen:
   JobList mainJobs;
   mainJobs.pushBack( Job("Ausfuehrung der Jobs kontrollieren!"));
   mainJobs.pushBack( Job("Urlaub planen!"));

   myJobs = mainJobs;
   cout << "\nMeine neuen Jobs:\n";
   myJobs.print();
 
   return 0;
}
