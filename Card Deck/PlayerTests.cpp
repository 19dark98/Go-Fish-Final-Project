#include "PlayerTests.h"
#include "Card.h"
#include <iostream>


PlayerTests::PlayerTests()
{
}


PlayerTests::~PlayerTests()
{
}

void PlayerTests::testDraw()
{
	Deck d(false);
	Player p;

	p.DisplayHand();
	p.drawCards(d, 4);
	p.DisplayHand();

	
}
void PlayerTests::testCheckPairs()
{
	Player p;
	p.insertCard(1, 1);
	p.insertCard(2, 1);
	p.checkForPairs();
	//test with multiple cards
	Player p2;
	p2.insertCard(1, 1);
	p2.insertCard(2, 1);
	p2.insertCard(1, 2);
	p2.insertCard(2, 2);
	p2.checkForPairs();

	//test dealing whole deck
	Deck d(false);
	Player p3;
	p3.drawCards(d, 55);//calls checkforpairs()
	p3.getHandSize();
	std::cout << "expected Hand size: 0 -> actual Hand Size " << p3.getHandSize() << std::endl;
	std::cout << "expected Pair size: 26 -> acutal pair count: " << p3.countPairs() << std::endl;
	
}
