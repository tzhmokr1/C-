#ifndef VERTEILKNOTEN_H
#define VERTEILKNOTEN_H

#include "kasse.h"

class VerteilKnoten
{
public:
	// Konstruktoren ---
	VerteilKnoten( Kasse *kasse, float &verteilAnteil );
	// ---

	// Getter ---
	Kasse* getKasse() ;
	float& getVerteilAnteil() ;
	// ---

	// Setter ---
	void setVerteilAnteil( float &verteilAnteil );
	// ---
	
private:
	// Deletes ---
	VerteilKnoten() = delete;
	VerteilKnoten( VerteilKnoten &obj ) = delete;
	VerteilKnoten& operator=( VerteilKnoten &obj ) = delete;
	// ---

	// Eigenschaften ---
	Kasse *kasse;
	float verteilAnteil;
	// ---
};

#endif