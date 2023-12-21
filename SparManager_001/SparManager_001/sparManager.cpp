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
	// Speichere Daten zurück in die Textdateien
	fstream kassenDatei( SparManager::kassenDateiName, ios::out|ios::ate );
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

	fstream sparquellenDatei( SparManager::sparquellenDateiName, ios::out | ios::ate );
	if( sparquellenDatei.fail() )
	{
		exit( -1 );
	}

	ersterDatensatz = true;
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

	fstream verteilungDatei( SparManager::verteilungDateiName, ios::out | ios::ate );
	if( verteilungDatei.fail() )
	{
		exit( -1 );
	}

	ersterDatensatz = true;
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

void SparManager::printMenu() 
{
	system( "CLS" );

	cout << "---- MENÜ ----" << endl;
	cout << "(1) Einsparen" << endl;
	cout << "(2) Verteil-Anteil ändern" << endl;
	cout << "(x) Programm beenden" << endl;
}

void SparManager::start()
{
	char menuPunkt = ' ';

	do
	{
		this->printMenu();

		cout << "\nEingabe: ";
		cin >> menuPunkt;

		switch( menuPunkt )
		{
		case '1':
		{
			system( "CLS" );
			cout << "---- QUELLEN-VERTEILUNG ----" << endl;
			cout << "Für Welche Spar-Quelle?\nSparquellen:\n" << endl;

			for( auto &sq : this->sparQuellen )
			{
				cout << '(' << sq->getId() << ')' << sq->getName() << endl;
			}

			cout << "Quellen-Id: ";
			size_t quellenId = 0;
			cin >> quellenId;

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
				cout << "Betrag: ";

				float betrag = 0.0f;
				cin >> betrag;

				quelle->einsparen( betrag );
			}
			else
			{
				cout << "Fehler. Quelle nicht gefunden!" << endl;
			}
		}
		break;

		case '2':
		{
			system( "CLS" );
			cout << "---- VERTEIL-ANTEIL ÄNDERN ----" << endl;
			cout << "Für Welche Spar-Quelle?\nSparquellen:\n" << endl;

			for( auto &sq : this->sparQuellen )
			{
				cout << '(' << sq->getId() << ')' << sq->getName() << endl;
			}

			cout << "Quellen-Id: ";
			size_t quellenId = 0;
			cin >> quellenId;

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
				cout << "---- Konfiguration von '" << "' ----\n" << endl;

				for( auto &vk : quelle->getVerteilKonfiguration()->getVerteilKnoten() )
				{
					cout << '(' << vk->getKasse()->getId() << ')' << vk->getKasse()->getName()
						<< "( Verteil-Anteil: " << vk->getVerteilAnteil() << ')' << endl;
				}

				cout << "Verteil-Anteil ändern für Kassen-Id: ";
				size_t kassenId = 0;
				cin >> kassenId;

				cout << "Verteil-Anteil ändern auf: ";
				float verteilanteil = 0.0f;
				cin >> verteilanteil;

				if( this->setVerteilAnteil( quellenId, kassenId, verteilanteil ) )
				{
					system( "CLS" );
					cout << "Verteil-Anteil geändert!" << endl;
					system( "PAUSE" );
				}
				else
				{
					system( "CLS" );
					cout << "Kassen-ID nicht gefunden!" << endl;
					system( "PAUSE" );
				}

				cout << "\n" << endl;
				break;
			}
			else
			{
				cout << "Fehler. Quelle nicht gefunden!" << endl;
			}
		}

		case 'x':
			cout << "\nProgramm wird beendet..." << endl;
			break;

		default: 
			cout << "\nFalsche Eingabe!" << endl;
			break;
		}

		system( "PAUSE" );

	} while( menuPunkt != 'x' );
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