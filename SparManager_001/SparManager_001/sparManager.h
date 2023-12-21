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
	Kasse* findeKasse( size_t &kassenId );
	bool setVerteilAnteil( size_t &sparQuellenId, size_t &kassenId, float &verteilAnteil );
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
	void printMenu() ;
	// ---

	// Eigenschaften ---
	vector<Kasse*> kassen;
	vector<SparQuelle*> sparQuellen;
	// ---
};

#endif