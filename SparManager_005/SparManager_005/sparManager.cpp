#include "sparManager.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

#include <fstream>
using std::fstream;
using std::ios;

#include <sstream>
using std::stringstream;

#include <map>
using std::map;

// Static ---
string SparManager::kassenDateiName = "C:/Users/krist/myCloud/Documents/__repositories/c++/SparManager_001/SparManager_001/kassen.txt";
string SparManager::sparquellenDateiName = "C:/Users/krist/myCloud/Documents/__repositories/c++/SparManager_001/SparManager_001/sparquellen.txt";
string SparManager::verteilungDateiName = "C:/Users/krist/myCloud/Documents/__repositories/c++/SparManager_001/SparManager_001/verteilung.txt";
// ---

// Konstruktoren ---
SparManager::SparManager()
{
	// Initialisierungen ---
	this->kassen.resize( 0 );
	this->sparQuellen.resize( 0 );
	// ---

	// Laden der Datei "kassen.txt" ---
	fstream kassenDatei( SparManager::kassenDateiName, ios::in );

	if( kassenDatei.fail() )
	{
		exit( -1 );
	}

	while( !kassenDatei.eof() )
	{
		string zeile;
		getline( kassenDatei, zeile );

		stringstream zeilenStream;
		zeilenStream << zeile;

		string str_id;
		size_t id = 0;
		string kassenName;
		string str_betrag;
		long double betrag = 0.0;

		getline( zeilenStream, str_id, ',' );
		getline( zeilenStream, kassenName, ',' );
		getline( zeilenStream, str_betrag, ',' );

		// Konvertiere string-Typen, die getlinbe geholt hat in die richtigen Typen, die dahinter stecken
		stringstream konverter;
		konverter << str_id;
		konverter >> id;
		konverter.clear();
		konverter << str_betrag;
		konverter >> betrag;

		this->kassen.push_back( new Kasse( id, kassenName, betrag ) );
	}

	kassenDatei.close();
	// ---

	// Laden der Datei "verteilung.txt" ---
	map<size_t, string> verteilungen;

	fstream verteilungDatei( SparManager::verteilungDateiName, ios::in );

	if( verteilungDatei.fail() )
	{
		exit( -1 );
	}

	while( !verteilungDatei.eof() )
	{
		string zeile;
		getline( verteilungDatei, zeile );

		stringstream zeilenStream;
		zeilenStream << zeile;

		string str_id;
		size_t id = 0;
		string konfigurationsDaten;

		getline( zeilenStream, str_id, ',' );
		getline( zeilenStream, konfigurationsDaten );

		// Konvertiere string-Typen, die getlinbe geholt hat in die richtigen Typen, die dahinter stecken
		stringstream konverter;
		konverter << str_id;
		konverter >> id;
		konverter.clear();

		verteilungen.insert( std::pair<size_t, string>( id, konfigurationsDaten ) );
	}

	verteilungDatei.close();
	// ---

	// Laden der Datei "sparquellen.txt" ---
	fstream sparquellenDatei( SparManager::sparquellenDateiName, ios::in );

	if( sparquellenDatei.fail() )
	{
		exit( -1 );
	}

	while( !sparquellenDatei.eof() )
	{
		string zeile;
		getline( sparquellenDatei, zeile );

		stringstream zeilenStream;
		zeilenStream << zeile;

		string str_id;
		size_t id;
		string sparQuellenName;

		getline( zeilenStream, str_id, ',' );
		getline( zeilenStream, sparQuellenName, ',' );

		// Konvertiere string-Typen, die getlinbe geholt hat in die richtigen Typen, die dahinter stecken
		stringstream konverter;
		konverter << str_id;
		konverter >> id;
		konverter.clear();

		string str_konfiguration = verteilungen[id];

		// Erzeuge VerteilKnoten
		stringstream konfigurationen;
		konfigurationen << str_konfiguration;

		vector<VerteilKnoten*> verteilKnoten;

		while( !konfigurationen.eof() )
		{
			string konfigurationsDaten;
			getline( konfigurationen, konfigurationsDaten, ',' );

			size_t kassenId = 0;
			float verteilAnteil = 0.0f;

			konverter << konfigurationsDaten;
			konverter >> kassenId >> verteilAnteil;
			konverter.clear();

			Kasse *kasse = this->findeKasse( kassenId );
			if( kasse != nullptr )
			{
				verteilKnoten.push_back( new VerteilKnoten( kasse, verteilAnteil ) );
			}
		}

		// Erzeuge VerteilerKonfoiguration
		VerteilKonfiguration *vKonf = new VerteilKonfiguration( verteilKnoten );

		// Erzeuge SparQuelle
		this->sparQuellen.push_back( new SparQuelle( this, id, sparQuellenName, vKonf ) );
	}

	sparquellenDatei.close();
	// ---
}

SparManager::~SparManager()
{
	this->alleDatenSpeichern();

	// Speicher freigeben
	for( auto &k : this->kassen )
	{
		delete k;
	}

	for( auto &sq : this->sparQuellen )
	{
		delete sq;
	}
	// ---

	this->kassen.resize( 0 );
	this->sparQuellen.resize( 0 );
}
// ---

// Methoden ---
// kassen.txt
void SparManager::kassenDatenSpeichern() 		
{
	fstream kassenDatei( SparManager::kassenDateiName, ios::out | ios::ate );

	if( kassenDatei.fail() )
	{
		exit( -1 );
	}

	bool ersterDatensatz = true;

	for( auto &k : this->kassen )
	{
		if( ersterDatensatz )
		{
			ersterDatensatz = false;
		}
		else
		{
			kassenDatei << endl;
		}

		kassenDatei << k->getId() << ',' << k->getName() << ',' << k->getBetrag();
	}
	kassenDatei.close();
}

// sparquellen.txt
void SparManager::sparquellenDatenSpeichern() 
{
	fstream sparquellenDatei( SparManager::sparquellenDateiName, ios::out | ios::ate );

	if( sparquellenDatei.fail() )
	{
		exit( -1 );
	}

	bool ersterDatensatz = true;

	for( auto &sq : this->sparQuellen )
	{
		if( ersterDatensatz )
		{
			ersterDatensatz = false;
		}
		else
		{
			sparquellenDatei << endl;
		}

		sparquellenDatei << sq->getId() << ',' << sq->getName();
	}
	sparquellenDatei.close();
}

// verteilung.txt
void SparManager::verteilungsDatenSpeichern() 
{
	fstream verteilungDatei( SparManager::verteilungDateiName, ios::out | ios::ate );

	if( verteilungDatei.fail() )
	{
		exit( -1 );
	}

	bool ersterDatensatz = true;

	for( auto &sq : this->sparQuellen )
	{
		if( ersterDatensatz )
		{
			ersterDatensatz = false;
		}
		else
		{
			verteilungDatei << endl;
		}

		auto vKonf = sq->getVerteilKonfiguration();
		auto vKnoten = vKonf->getVerteilKnoten();

		verteilungDatei << sq->getId();

		for( auto &vk : vKnoten )
		{
			verteilungDatei << ',' << vk->getKasse()->getId() << ' ' << vk->getVerteilAnteil();
		}
	}
	verteilungDatei.close();
}

void SparManager::alleDatenSpeichern() 
{
	// Speichere Daten zurück in die Textdateien
	this->kassenDatenSpeichern();
	this->sparquellenDatenSpeichern();
	this->verteilungsDatenSpeichern();	
}

void SparManager::gebeMeldungAus( string message ) 
{
	system( "CLS" );

	cout << message;
	cout << "\n" << endl;

	system( "PAUSE" );
}

void SparManager::printMenu_hauptMenu() 
{
	system( "CLS" );

	cout << "---- Hauptmenü ----" << endl;
	cout << "(1) Einsparen" << endl;
	cout << "(2) Verteilen\n" << endl;

	cout << "(3) Einstellungen\n" << endl;

	cout << "(0) Programm beenden" << endl;
}

void SparManager::printMenu_einstellungen() 
{
	system( "CLS" );

	cout << "---- Einstellungen ----" << endl;
	cout << "(1) Kasse hinzufügen" << endl;
	cout << "(2) Kasse ändern" << endl;
	cout << "(3) Kasse löschen\n" << endl;

	cout << "(4) Sparquelle hinzufügen" << endl;
	cout << "(5) Sparquelle ändern" << endl;
	cout << "(6) Sparquelle löschen\n" << endl;

	cout << "(7) Verteil-Konfiguration anlegen" << endl;
	cout << "(8) Verteil-Konfiguration ändern" << endl;
	cout << "(9) Verteil-Konfiguration löschen\n" << endl;

	cout << "(0) zurück" << endl;
}

void SparManager::printMenu_kontoAendern() 
{
	system( "CLS" );

	cout << "---- Konto ändern ----" << endl;
	cout << "(1) Konto-Name ändern\n" << endl;

	cout << "(0) zurück" << endl;
}

void SparManager::printMenu_sparQuelleAendern() 
{
	system( "CLS" );

	cout << "---- Spar-Quelle ändern ----" << endl;
	cout << "(1) Sparquellen-Name ändern\n" << endl;

	cout << "(0) zurück" << endl;
}

void SparManager::printMenu_verteilKnotenAendern() 
{
	system( "CLS" );

	cout << "---- Verteil-Knoten ändern ----" << endl;
	cout << "(1) Verteil-Anteil ändern\n" << endl;

	cout << "(0) zurück" << endl;
}

void SparManager::menuPunkt_hauptMenu()
{
	int menuPunkt = -1;
	bool loop = true;

	do
	{
		this->printMenu_hauptMenu();

		cout << "\nEingabe: ";
		cin >> menuPunkt;

		cin.clear();
		cin.sync();

		switch( menuPunkt )
		{
		case 1: // Einsparen
			this->menuPunkt_einsparen();
			break;

		case 2: // Verteilen
			this->menuPunkt_verteilen();
			break;

		case 3: // Einstellungen
			this->menuPunkt_einstellungen();
			break;

		case 0: // Programm beenden
			this->gebeMeldungAus( "Programm wird beendet..." );
			loop = false;
			break;

		default:
			this->gebeMeldungAus( "FEHLER\nFalsche Eingabe!" );
			break;
		}

	} while( loop );
}

void SparManager::menuPunkt_einsparen()
{
	system( "CLS" );

	cout << "---- Einsparen ----" << endl;
	cout << "In welche Kasse?\n\nKassen:" << endl;

	for( auto &k : this->kassen )
	{
		cout << '(' << k->getId() << ") " << k->getName() << endl;
	}

	cout << "\n(0) zurück" << endl;

	cout << "\nEingabe: ";

	size_t eingabe = -1;
	cin >> eingabe;

	cin.clear();
	cin.sync();

	bool zurueck = false;

	if( eingabe == 0 )
	{
		zurueck = true;
	}

	if( !zurueck )
	{
		// finde SparQuelle
		Kasse *kasse = this->findeKasse( eingabe );

		if( kasse != nullptr )
		{
			cout << "Betrag: ";

			long double betrag = 0.0f;
			cin >> betrag;

			cin.clear();
			cin.sync();

			if( betrag > 0.0 )
			{
				if( ( dynamic_cast<Kasse*>( kasse ) )->einzahlen( betrag ) )
				{
					this->kassenDatenSpeichern();
					this->gebeMeldungAus( "Betrag in Höhe von - " +
						std::to_string( betrag ) +
						" Euro - erfolgreich in Kasse - " +
						kasse->getName() +
						" - eingezahlt!\nDaten wurden gespeichert.." );
				}
				else
				{
					this->gebeMeldungAus( "FEHLER\nBetrag in Höhe von - " +
						std::to_string( betrag ) +
						" Euro - wurde in Kasse - " +
						kasse->getName() +
						" - NICHT eingezahlt!" );
				}
			}
			else
			{
				this->gebeMeldungAus( "Der Betrag muss größer als 0.00 sein!" );
			}
		}
		else
		{
			this->gebeMeldungAus( "FEHLER\nKasse nicht gefunden!" );
		}
	}
}

void SparManager::menuPunkt_verteilen()
{
	system( "CLS" );
	cout << "---- Verteilen ----" << endl;
	cout << "Für Welche Spar-Quelle?\n\nSparquellen:" << endl;

	for( auto &sq : this->sparQuellen )
	{
		cout << '(' << sq->getId() << ") " << sq->getName() << endl;
	}

	cout << "\n(0) zurück" << endl;

	cout << "\nEingabe: ";

	int eingabe = -1;
	cin >> eingabe;

	cin.clear();
	cin.sync();

	bool zurueck = false;

	if( eingabe == 0 )
	{
		zurueck = true;
	}

	if( !zurueck )
	{
		// Finde SparQuelle
		SparQuelle *quelle = nullptr;

		for( auto &sq : this->sparQuellen )
		{
			if( sq->getId() == eingabe )
			{
				quelle = sq;
				break;
			}
		}

		if( quelle != nullptr )
		{
			cout << "Betrag: ";

			long double betrag = 0.0f;
			cin >> betrag;

			cin.clear();
			cin.sync();

			if( betrag > 0.0 )
			{
				if( quelle->verteilen( betrag ) )
				{
					this->kassenDatenSpeichern();
					this->gebeMeldungAus( "Betrag in Höhe von - " +
						std::to_string( betrag ) +
						" Euro - erfolgreich verteilt!\nDaten wurden gespeichert.." );
				}
				else
				{
					this->gebeMeldungAus( "FEHLER\nBetrag in Höhe von - " +
						std::to_string( betrag ) +
						" Euro - wurde NICHT verteilt!" );
				}
			}
			else
			{
				this->gebeMeldungAus( "Der Betrag muss größer als 0.00 sein!" );
			}
		}
		else
		{
			this->gebeMeldungAus( "FEHLER\nQuelle nicht gefunden!" );
		}
	}
}

void SparManager::menuPunkt_einstellungen()
{
	int menuPunkt = -1;
	bool loop = true;

	do
	{
		this->printMenu_einstellungen();

		cout << "\nEingabe: ";
		cin >> menuPunkt;

		cin.clear();
		cin.sync();

		switch( menuPunkt )
		{
		case 1: // Konto hinzufügen
			this->menuPunkt_kontoHinzufuegen();
			break;

		case 2: // Konto ändern
			this->menuPunkt_kontoAendern();
			break;

		case 3: // Konto löschen
			this->menuPunkt_kontoLoeschen();
			break;

		case 4: // Sparquelle hinzufügen
			this->menuPunkt_sparQuelleHinzufuegen();
			break;

		case 5: // Sparquelle ändern
			this->menuPunkt_sparQuelleAendern();
			break;

		case 6: // Sparquelle löschen
			this->menuPunkt_sparQuelleLoeschen();
			break;

		case 7: // Verteil-Knoten hinzufügen
			this->menuPunkt_verteilKnotenHinzufuegen();
			break;

		case 8: // Verteil-Knoten ändern
			this->menuPunkt_verteilKnotenAendern();
			break;

		case 9:// Verteil-Knoten löschen
			this->menuPunkt_verteilKnotenLoeschen();
			break;

		case 0: // Zurück ( raus aus dem Menü )
			loop = false;
			break;

		default:
			this->gebeMeldungAus( "FEHLER\nFalsche Eingabe!" );
			break;
		}

	} while( loop );
}

void SparManager::menuPunkt_kontoHinzufuegen()
{
	system( "CLS" );
	cout << "Noch nicht implementiert" << endl;
	system( "PAUSE" );
}

void SparManager::menuPunkt_kontoAendern()
{
	int menuPunkt = -1;
	bool loop = true;

	do
	{
		this->printMenu_kontoAendern();

		cout << "\nEingabe: ";
		cin >> menuPunkt;

		cin.clear();
		cin.sync();

		switch( menuPunkt )
		{
		case 1: // Kontoname ändern
			this->menuPunkt_kontoNameAendern();
			break;

		case 0: // Zurück( raus aus dem Menü )
			loop = false;
			break;

		default:
			this->gebeMeldungAus( "FEHLER\nFalsche Eingabe!" );
			break;
		}

	} while( loop );
}

void SparManager::menuPunkt_kontoLoeschen()
{
	system( "CLS" );
	cout << "Noch nicht implementiert" << endl;
	system( "PAUSE" );
}

void SparManager::menuPunkt_sparQuelleHinzufuegen()
{
	system( "CLS" );
	cout << "Noch nicht implementiert" << endl;
	system( "PAUSE" );
}

void SparManager::menuPunkt_sparQuelleAendern()
{
	int menuPunkt = -1;
	bool loop = true;

	do
	{
		this->printMenu_sparQuelleAendern();

		cout << "\nEingabe: ";
		cin >> menuPunkt;

		cin.clear();
		cin.sync();

		switch( menuPunkt )
		{
		case 1: // Sparquellen-Name ändern
			this->menuPunkt_SparquellenNameAendern();
			break;

		case 0: // Zurück ( raus aus dem Menü )
			loop = false;
			break;

		default:
			this->gebeMeldungAus( "FEHLER\nFalsche Eingabe!" );
			break;
		}

	} while( loop );
}

void SparManager::menuPunkt_sparQuelleLoeschen()
{
	system( "CLS" );
	cout << "Noch nicht implementiert" << endl;
	system( "PAUSE" );
}

void SparManager::menuPunkt_verteilKnotenHinzufuegen()
{
	system( "CLS" );
	cout << "Noch nicht implementiert" << endl;
	system( "PAUSE" );
}

void SparManager::menuPunkt_verteilKnotenAendern()
{
	int menuPunkt = -1;
	bool loop = true;

	do
	{
		this->printMenu_verteilKnotenAendern();

		cout << "\nEingabe: ";
		cin >> menuPunkt;

		cin.clear();
		cin.sync();

		switch( menuPunkt )
		{
		case 1: // Verteil-Anteil ändern
			this->menuPunkt_verteilAnteilAendern();
			break;

		case 0: // Zurück ( raus aus dem Menü )
			loop = false;
			break;

		default:
			this->gebeMeldungAus( "FEHLER\nFalsche Eingabe!" );
			break;
		}

	} while( loop );
}

void SparManager::menuPunkt_verteilKnotenLoeschen()
{
	system( "CLS" );
	cout << "Noch nicht implementiert" << endl;
	system( "PAUSE" );
}

void SparManager::menuPunkt_kontoNameAendern()
{
	system( "CLS" );
	cout << "Noch nicht implementiert" << endl;
	system( "PAUSE" );
}

void SparManager::menuPunkt_SparquellenNameAendern()
{
	system( "CLS" );
	cout << "Noch nicht implementiert" << endl;
	system( "PAUSE" );
}

void SparManager::menuPunkt_verteilAnteilAendern()
{
	system( "CLS" );
	cout << "---- Verteil-Anteil ändern ----" << endl;
	cout << "Für Welche Spar-Quelle?\n\nSparquellen:" << endl;

	for( auto &sq : this->sparQuellen )
	{
		cout << '(' << sq->getId() << ") " << sq->getName() << endl;
	}

	cout << "\n(0) zurück" << endl;

	cout << "\nEingabe: ";

	int eingabe = -1;
	cin >> eingabe;

	cin.clear();
	cin.sync();

	bool zurueck = false;

	if( eingabe == 0 )
	{
		zurueck = true;
	}

	if( !zurueck )
	{
		size_t quellenId = eingabe;

		// finde SparQuelle
		SparQuelle *quelle = nullptr;

		for( auto &sq : this->sparQuellen )
		{
			if( sq->getId() == quellenId )
			{
				quelle = sq;
				break;
			}
		}

		if( quelle != nullptr )
		{
			system( "CLS" );
			cout << "---- Konfiguration von '" << quelle->getName() << "' ----\n" << endl;

			for( auto &vk : quelle->getVerteilKonfiguration()->getVerteilKnoten() )
			{
				cout << '(' << vk->getKasse()->getId() << ") " << vk->getKasse()->getName()
					<< "( Verteil-Anteil: " << vk->getVerteilAnteil() << " )" << endl;
			}

			cout << "\nVerteil-Anteil ändern für Kassen-Id: ";

			size_t kassenId = 0;
			cin >> kassenId;

			cin.clear();
			cin.sync();

			if( this->findeKasse( kassenId ) != nullptr )
			{
				cout << "Verteil-Anteil ändern auf: ";
				float verteilanteil = 0.0f;
				cin >> verteilanteil;

				cin.clear();
				cin.sync();

				if( verteilanteil > 0.0f )
				{
					if( this->setVerteilAnteil( quellenId, kassenId, verteilanteil ) )
					{
						this->verteilungsDatenSpeichern();
						this->gebeMeldungAus( "Verteil-Anteil geändert!\nDaten wurden gespeichert.." );
					}
					else
					{
						this->gebeMeldungAus( "FEHLER\nVerteilung nicht erfolgt!\nQuelle oder Kasse fehlt!" );
					}
				}
				else
				{
					this->gebeMeldungAus( "Verteil-Anteil muss größer als 0.00 sein!" );
				}
			}
			else
			{
				this->gebeMeldungAus( "FEHLER\nKassen - ID nicht gefunden!" );
			}
		}
		else
		{
			this->gebeMeldungAus( "FEHLER\nQuelle nicht gefunden!" );
		}
	}
}

void SparManager::start()
{
	this->menuPunkt_hauptMenu();
}

Kasse* SparManager::findeKasse( size_t &kassenId ) 
{
	Kasse *kasse = nullptr;

	for( auto &k : this->kassen )
	{
		if( k->getId() == kassenId )
		{
			kasse = k;
			break;
		}
	}

	return kasse;
}

SparQuelle* SparManager::findeSparQuelle( size_t &sparQuelleId ) 
{
	SparQuelle *quelle = nullptr;

	for( auto &sq : this->sparQuellen )
	{
		if( sq->getId() == sparQuelleId )
		{
			quelle = sq;
			break;
		}
	}

	return quelle;
}

bool SparManager::setVerteilAnteil( size_t &sparQuellenId, size_t &kassenId, float &verteilAnteil )
{
	bool verteilAnteilGesetzt = false;

	for( auto &sq : this->sparQuellen )
	{
		if( sq->getId() == sparQuellenId )
		{
			verteilAnteilGesetzt = sq->setVerteilAnteil( kassenId, verteilAnteil );
			break;
		}
	}

	return verteilAnteilGesetzt;
}
// ---