#ifndef VERTEILKONFIGURATION_H
#define VERTEILKONFIGURATION_H

#include "verteilKnoten.h"

#include <vector>
using std::vector;

class VerteilKonfiguration
{
public:
	// Konstruktoren ---
	VerteilKonfiguration( vector<VerteilKnoten*> &verteilKnoten );
	~VerteilKonfiguration();
	// ---

	// Methoden ---
	bool setVerteilAnteil( Kasse *kasse, float &verteilAnteil );
	bool einsparen( long double &betrag );
	// ---

	// Getter ---
	vector<VerteilKnoten*>& getVerteilKnoten() ;
	// ---

private:
	// Deletes ---
	VerteilKonfiguration() = delete;
	VerteilKonfiguration( VerteilKonfiguration &obj ) = delete;
	// ---

	// Eigenschaften
	vector<VerteilKnoten*> verteilKnoten;
	// ---
};

#endif