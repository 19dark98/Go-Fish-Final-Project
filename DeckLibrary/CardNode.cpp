#include "CardNode.h"

//member functions

//private functions


//public functions

//constructors
CardNode::CardNode()
{
	this->pCard = nullptr;
	this->pNext = nullptr;
}
CardNode::CardNode(Card *c)
{
	this->pCard = c;
	this->pNext = nullptr;
}
CardNode::CardNode(Card &c)
{
	this->pCard = new Card(c);
	this->pNext = nullptr;
}
CardNode::CardNode(int faceValue, int suitValue)
{
	this->pCard = new Card(suitValue, faceValue);
	this->pNext = nullptr;
}


CardNode::~CardNode()
{

}

CardNode CardNode::operator=(CardNode &rhs) 
{
	//deep copy
	Card *pC = new Card(*rhs.pCard);
	this->pCard = pC;
	this->pNext = rhs.pNext;
	return *this;
}

//getters
CardNode *CardNode::getNextNode()
{
	return this->pNext;
}
Card * CardNode::getCardNode()
{
	if(this != nullptr)
	return this->pCard;
}
//setters
void CardNode::setNextNode(CardNode *newNode)
{
	this->pNext = newNode;
}
void CardNode::setCardNode(Card *newNode)
{
	this->pCard = newNode;
}