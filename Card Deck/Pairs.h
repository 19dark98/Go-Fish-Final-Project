#pragma once
#include "Card.h"
class Pairs
{
public:
	Pairs(Card * pCard1, Card * pCard2);
	~Pairs();
	Card * getCard1Ptr();
	Card * getCard2Ptr();

private:
	Card * pCard1;
	Card * pCard2;
};

