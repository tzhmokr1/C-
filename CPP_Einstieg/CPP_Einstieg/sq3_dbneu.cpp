#include <iostream>
#include <cstring>
#include <sqlite3.h>
using namespace std;

int main()
{
   sqlite3 *con;
   char sql[255];
   char *meldung;

   if(sqlite3_open("firma.db", &con))
   { cout << "Fehler bei Verbindung" << endl; return 1; }

   strcpy(sql, "CREATE TABLE IF NOT EXISTS personen("
      "name TEXT, "
      "vorname TEXT, "
      "personalnummer INTEGER PRIMARY KEY, "
      "gehalt REAL, "
      "geburtstag TEXT)");

   if(sqlite3_exec(con, sql, NULL, NULL, &meldung))
   { cout << "Fehler: " << meldung << endl; return 1; }

   sqlite3_close(con);
}

