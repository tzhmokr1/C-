// ---------------------------------------------------------
// ex21_09.cpp
// Verwendet die Klasse JobList.
// ---------------------------------------------------------
#include <iostream>
#include "JobList.h"
using namespace std;

int main()
{
   JobList* pMyJobs = new JobList;

   const Job aJob("Mails beantworten.");

   // Jobs einfuegen;
   pMyJobs->pushBack( aJob);
   pMyJobs->pushBack( Job("Chef zurueckrufen!"));
   pMyJobs->pushBack( Job("Meeting vorbereiten."));

   cout << "\n\t *****  Auftragsliste  *****\n" << endl;

   pMyJobs->print();        // Alle Auftraege anzeigen.

   // Das erste Element entnehmen und nochmal anzeigen:
   Job job("");
   pMyJobs->popFront( job);
   cout << "\nDer Auftrag\n" << job
        << "\nist erledigt!" << endl; 
   cout << "\nEs gibt in der Liste noch " 
        << pMyJobs->getCount() << " Auftraege.\n" << endl;

   delete pMyJobs;

   return 0;
}
