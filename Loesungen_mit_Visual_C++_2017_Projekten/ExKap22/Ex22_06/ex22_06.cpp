// ---------------------------------------------------------
// ex22_06.cpp
// Verwendet die Klasse JobList mit Iteratoren.
// ---------------------------------------------------------
#include <iostream>
#include "jobList.h"
using namespace std;

int main()
{
   JobList myJobs;
   const Job aJob("Mails beantworten.");
   unsigned long jobID = aJob.getID();

   // Jobs einfuegen;
   myJobs.pushBack( aJob);
   myJobs.pushBack( Job("Chef zurueckrufen!"));
   myJobs.pushBack( Job("Meeting vorbereiten."));

   cout << "\n\t *****  Auftragsliste  *****\n" << endl;

   // Alle Auftraege mit einer Iterator-Schleife anzeigen.
   cout << "\nDie Auftraege in der Liste:\n";
   JobList::Iterator iter = myJobs.begin();
   for(  ;  iter != myJobs.end();  ++iter)
      cout << *iter << endl;

   // Eine Job-ID suchen:
   for( iter = myJobs.begin(); iter != myJobs.end(); ++iter)
      if( (*iter).getID() == jobID)
          break;
   if( iter != myJobs.end())
      cout << "\nAuftrag gefunden:\n" << *iter << endl;
   else
      cout << "\nAuftrag " << jobID << " nicht gefunden!\n" << endl;

   Job job("");
   myJobs.popFront( job);             // 1. Auftrag erledigen
   cout << "\nDer Auftrag" << job
        << "\nist erledigt!" << endl; 

   // Job-ID nochmal suchen:
   for( iter = myJobs.begin(); iter != myJobs.end(); ++iter)
      if( (*iter).getID() == jobID)
          break;
   if( iter != myJobs.end())
      cout << "\nAuftrag gefunden:\n" << *iter << endl;
   else
      cout << "\nAuftrag " << jobID << " nicht gefunden!\n" << endl;

   return 0;
}
