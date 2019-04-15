#pragma once
#include "Card.h"

class CardNode
{
private:
	//data fields
	Card *pCard;
	CardNode *pNext;

public:
	//constructors
	CardNode(); //tested
	CardNode(Card *c);//needs Testing
	CardNode(Card &c); //tested
	CardNode(int faceValue, int suitValue); //tested

	//rule of threes
	~CardNode(); // tested
	CardNode operator=(CardNode &rhs);
	//getters
	CardNode *getNextNode();
	Card *getCardNode();
	//setters
	void setNextNode(CardNode *newNode);
	void setCardNode(Card *newNode);
};