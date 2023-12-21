#include "verteilKonfiguration.h"

// Konstruktoren ---
VerteilKonfiguration::VerteilKonfiguration( vector<VerteilKnoten*> &verteilKnoten )
: verteilKnoten( verteilKnoten )
{
}

VerteilKonfiguration::~VerteilKonfiguration()
{
	for( auto &vk : this->verteilKnoten )
	{
		delete vk;
	}

	this->verteilKnoten.resize( 0 );
}
// ---

// Methoden ---
bool VerteilKonfiguration::setVerteilAnteil( Kasse *kasse, float &verteilAnteil )
{
	bool verteilAnteilGesetzt = false;

	for( auto &vk : this->verteilKnoten )
	{
		if( kasse == vk->getKasse() )
		{
			verteilAnteilGesetzt = true;
			vk->setVerteilAnteil( verteilAnteil );
			break;
		}
	}

	return verteilAnteilGesetzt;
}

bool VerteilKonfiguration::einsparen( long double &betrag )
{
	bool eingespart = false;

	float anteile = 0.0;
	for( auto &vk : this->verteilKnoten )
	{
		anteile += vk->getVerteilAnteil();
	}

	long double anteilBetrag = betrag / anteile;

	for( auto &vk : this->verteilKnoten )
	{
		dynamic_cast<Kasse*>(vk->getKasse())->einzahlen( anteilBetrag = vk->getVerteilAnteil() );
	}

	return eingespart;
}
// ---

// Getter ---
vector<VerteilKnoten*>& VerteilKonfiguration::getVerteilKnoten() 
{
	return this->verteilKnoten;
}
// ---