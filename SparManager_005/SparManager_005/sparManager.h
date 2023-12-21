#ifndef SPARMANAGER_H
#define SPARMANAGER_H

#include "kasse.h"
#include "sparQuelle.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

class SparManager
{
public:
	// Konstruktoren ---
	SparManager();
	~SparManager();
	// ---

	// Methoden ---
	void start();
	Kasse* findeKasse( size_t &kassenId ) ;
	// ---

private:
	// Static ---
	static string kassenDateiName;
	static string sparquellenDateiName;
	static string verteilungDateiName;
	// ---

	// Deletes ---
	SparManager( SparManager &obj ) = delete;
	SparManager& operator=( SparManager &obj ) = delete;
	// ---

	// Methoden ---
	void kassenDatenSpeichern() ;		// kassen.txt
	void sparquellenDatenSpeichern() ;	// sparquellen.txt
	void verteilungsDatenSpeichern() ;	// verteilung.txt
	void alleDatenSpeichern() ;
	void gebeMeldungAus( string message ) ;

	// Menüs
	void printMenu_hauptMenu() ;
	void printMenu_einstellungen() ;
	void printMenu_kontoAendern() ;
	void printMenu_sparQuelleAendern() ;
	void printMenu_verteilKnotenAendern() ;

	// Menü-Funktionen
	void menuPunkt_hauptMenu();

	void menuPunkt_einsparen();
	void menuPunkt_verteilen();
	void menuPunkt_einstellungen();

	void menuPunkt_kontoHinzufuegen();
	void menuPunkt_kontoAendern();
	void menuPunkt_kontoLoeschen();

	void menuPunkt_sparQuelleHinzufuegen();
	void menuPunkt_sparQuelleAendern();
	void menuPunkt_sparQuelleLoeschen();

	void menuPunkt_verteilKnotenHinzufuegen();
	void menuPunkt_verteilKnotenAendern();
	void menuPunkt_verteilKnotenLoeschen();

	void menuPunkt_kontoNameAendern();
	void menuPunkt_SparquellenNameAendern();
	void menuPunkt_verteilAnteilAendern();

	SparQuelle* findeSparQuelle( size_t &sparQuellenId ) ;
	bool setVerteilAnteil( size_t &sparQuellenId, size_t &kassenId, float &verteilAnteil );
	// ---

	// Eigenschaften ---
	vector<Kasse*> kassen;
	vector<SparQuelle*> sparQuellen;
	// ---
};

#endif