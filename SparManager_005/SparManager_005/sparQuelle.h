#ifndef SPARQUELLE_H
#define SPARQUELLE_H

#include "verteilKonfiguration.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

// Vorwärtsdeklaration
class SparManager;

class SparQuelle
{
public:
	// Konstruktoren ---
	SparQuelle( SparManager *parent, size_t &id, string &name, VerteilKonfiguration *verteilKonfiguration );
	~SparQuelle();
	// ---

	// Methoden ---
	bool setVerteilAnteil( size_t &kassenId, float &verteilAnteil );
	bool verteilen( long double &betrag );
	// ---

	// Getter
	size_t& getId() ;
	string& getName() ;
	VerteilKonfiguration *getVerteilKonfiguration() ;
	//

	// Setter ---
	void setName( string &name );
	// ---

private:
	// Deletes ---
	SparQuelle() = delete;
	SparQuelle( SparQuelle &obj ) = delete;
	SparQuelle& operator=( SparQuelle &obj ) = delete;
	// ---

	// Eigenschaften ---
	SparManager *parent;
	size_t id;
	string name;
	VerteilKonfiguration *verteilKonfiguration;
	// ---
};

#endif