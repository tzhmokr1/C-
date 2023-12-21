#include "verteilKnoten.h"

// Konstruktoren ---
VerteilKnoten::VerteilKnoten( Kasse *kasse, float &verteilAnteil )
: kasse( dynamic_cast<Kasse*>( kasse ) )
, verteilAnteil( verteilAnteil )
{
}
// ---

// Getter ---
Kasse* VerteilKnoten::getKasse() 
{
	return this->kasse;
}

float& VerteilKnoten::getVerteilAnteil() 
{
	return this->verteilAnteil;
}
// ---

// Setter ---
void VerteilKnoten::setVerteilAnteil( float &verteilAnteil )
{
	this->verteilAnteil = verteilAnteil;
}
// ---