#include "DeckTests.h"



DeckTests::DeckTests()
{
}


DeckTests::~DeckTests()
{
}

void DeckTests::testConstructors()
{
	Deck dEmpty(true);
	
	Deck dNotEmpty(false);


}
void DeckTests::testDeal()
{
	Deck d1(false), d2;
	cout << "before: \n d1:" << d1 << "\n d2: " << d2;
	d2 << d1;
	cout << "after: \n d1:" << d1 << "\n d2: " << d2;
}
