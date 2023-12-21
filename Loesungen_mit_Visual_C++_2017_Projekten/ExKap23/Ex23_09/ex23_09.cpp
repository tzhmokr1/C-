// ------------------------------------------------------
// ex23_09.cpp
// Klasse MailService verwenden.
// ------------------------------------------------------

#include "mail.h"

char menu();

int main()
{
   MailService quickMail;           // Ein Versandservice
   unsigned long id = 0;
   char choice;

   while( (choice = menu()) != '0')
   {
     switch( choice)
     {
       case '1':                   // Neuer Brief
          if( !quickMail.newLetter())
            cout << "Ungueltige Eingabe!" << endl;
          break;

       case '2':                  // Neues Paket
          if( !quickMail.newParcel())
            cout << "Ungueltige Eingabe!" << endl;
          break;

       case '3':                  // Alle Briefe anzeigen
          quickMail.printLetters();
          break;

       case '4':                  // Alle Pakete anzeigen
          quickMail.printParcels();
          break;

       case '5':                  // Post ausliefern
          {
            Mail *p;
            string m;
            cout << "\nID der Post? ";
            cin >> id;
            if( (p = quickMail.getLetter(id)) != NULL)
               m = "Brief";
            else if( (p = quickMail.getParcel(id)) != NULL)
               m = "Paket";
            else
               cout << "Post mit der ID " << id << " nicht vorhanden!"
                    << endl;
            if( p != NULL)
               if( p->deliver())
                 cout << m << " wurde ausgeliefer!" << endl;
               else
                 cout << "Ungueltiger Empfaenger!" << endl;
          }
          break;
     }
   }
   return 0;
}

char menu()                // Menue anzeigen und Kommando einlesen.
{
   char choice = '0';

   cout << "\n\t ***** Versandservice Express *****\n" << endl;

   cout << "\t 1 = Neuen Brief registrieren\n"
        << "\t 2 = Neues Paket registrieren\n"
        << "\t 3 = Alle Briefe anzeigen\n"
        << "\t 4 = Alle Paktete anzeigen\n"
        << "\t 5 = Post ausliefern\n"
        << "\t 0 = Programm beenden\n" << endl;
   cout << "Ihre Wahl: ";
   do
     cin >> choice;
   while( choice < '0' || choice > '5');
   cin.ignore(256,'\n');      // Rest der Zeile ignorieren

   return choice;
}
