// -------------------------------------------------
// ex26_10.cpp
// Klasse PrioQueue testen.
// -------------------------------------------------

#include "prioQueue.h"

char menu();

int main()
{
   PrioQueue pq;
   char choice;
   int prio;
   string s, a;

   while( (choice = menu()) != '0')
   {
    switch(choice)
    {
      case '1':
        cout << "\nPrioritaet: ";  cin >> prio;
        cin.ignore(256, '\n');       // Rest der Zeile ignorieren.

        cout << "\nName:       ";  getline( cin, s);

        if( !pq.insert(prio, s))
            cout << "\nPrioritaet schon vergeben.";
        break;

       case '2':
         cout << "\nPrioritaet: "; cin >> prio;
         cin.ignore(256, '\n');       // Rest der Zeile ignorieren.

         cout << "\nName:       ";  getline( cin, s);
         cout << "\nAnamnese:   ";  getline( cin, a);
         if( !pq.insert(prio, s, a))
            cout << "\nPriorität schon vergeben.";
         break;

       case '3':
         {
           string s; 
           pq.deleteMax(s);
           if( s == "")
               cout << "\n\tKein Patient da." << endl;
           else
               cout << "\n\tNaechster Patient: Herr/Frau " 
                    << s << endl;
           break;
         }

         case '4':
           cout << "\n\t********  Wartende Patienten"
                << "*******\n";
           pq.display();
           break;
     }
   }

   return 0;
}

char menu()
{

  char choice = '0';

  cout << "\n\n\t ******  Notaufnahme Patienten  ******\n"
       << endl;

  cout << "\t 1 = Neuen Patient ohne Anamnese registrieren\n"
       << "\t 2 = Patient mit Anamnese registrieren\n"
       << "\t 3 = Naechsten Patienten aufrufen\n"
       << "\t 4 = Wartende Patienten anzeigen\n"
       << "\t 0 = Programm beenden\n";

  do
  {
    cout << "\nIhre Wahl: ";
    cin >> choice;
  }
  while( choice < '0' || choice > '4');
  cin.ignore(256, '\n');       // Rest der Zeile ignorieren.
 
  return choice;
}
