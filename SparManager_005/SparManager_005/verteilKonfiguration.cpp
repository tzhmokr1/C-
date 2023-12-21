#include "verteilKonfiguration.h"

#include <algorithm>
using std::sort;

bool sortKriterium( VerteilKnoten *a, VerteilKnoten *b )
{
	if( ( a->getKasse()->getId() ) < ( b->getKasse()->getId() ) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Konstruktoren ---
VerteilKonfiguration::VerteilKonfiguration( vector<VerteilKnoten*> &verteilKnoten )
: verteilKnoten( verteilKnoten )
{
	sort( this->verteilKnoten.begin(), this->verteilKnoten.end(), sortKriterium );
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
	bool eingespart = true;

	float anteile = 0.0;
	for( auto &vk : this->verteilKnoten )
	{
		anteile += vk->getVerteilAnteil();
	}

	if( anteile > static_cast<long double>( 0.0 ) )
	{
		long double anteilBetrag = betrag / anteile;

		// VORSICHT!!!
		// das Einsparen in nur einer der Kassen könnte schief gehen,..
		// ein nachträgliches Handling erfordert hier eine besser durchdachte Fehler-Behandlung!
		// Z.B. müsste gelogt werden, wo bereits was eingezahlt wurde und in welcher Kasse nicht, um es evtl
		// nachträglich nachzuholen oder ggf. aus den erfolgreichen Einzahlungen den Bettrag zurückzuziehen/zurückzuzahlen.....
		for( auto &vk : this->verteilKnoten )
		{
			if( !( dynamic_cast<Kasse*>( vk->getKasse() )->einzahlen( anteilBetrag = vk->getVerteilAnteil() ) ) )
			{
				eingespart = false;
			}
		}
	}
	else
	{
		eingespart = false;
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