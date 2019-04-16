#include "Pairs.h"



Pairs::Pairs(Card * pCard1, Card * pCard2)
{
	this->pCard1 = pCard1;
	this->pCard2 = pCard2;
}


Pairs::~Pairs()
{
	if (pCard1 != nullptr) delete pCard1;
	if (pCard2 != nullptr) delete pCard2;
}

Card * Pairs::getCard1Ptr()
{
	return pCard1;
}
Card * Pairs::getCard2Ptr()
{
	return pCard2;
}
