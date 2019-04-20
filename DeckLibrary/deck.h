/*
changelog:
3/22/2019: altered deck to contain more one deck type

*/

#pragma once
#include "Card.h"
#include "CardNode.h"
#include <ctime>
#include <cstdlib>
//standard cardDeck
#define DECK_SIZE 52


class Deck
{
public:
	//constructors
	//Deck();
	Deck(bool emptyDeck = true);//tested
	~Deck();
	//getters
	CardNode *getHeadPtr();
	//setters
	void setHeadPointer(CardNode * nHead);
	//void setHeadPtr(CardNode newHeadPtr);
	
	//other functions
	void resetDeck();
	void clearDeck() { destroyDeck(mpHead); };
	virtual void addCard(Card *c);
	void addCard(int faceValue, int suitValue);
	void Shuffle();
	CardNode *getPointerAtN(int n);
	
	Card *DealCard();//needs testing
	
	Card *deleteAtFront();//needs testing
	//property functions
	bool isEmpty();
	int getDeckLength();//tested

protected:
	//data fields
	CardNode *mpHead;
	
private:
	//private functions
	void addCard(Card *c, CardNode *pHead);//tested
	void addCard(int faceValue, int suitValue, CardNode *pNode);//tested
	void Shuffle(CardNode *mpHead);//tested
	CardNode *getPointerAtN(CardNode *mpHead, int n);//tested
	int getDeckLength(CardNode *pNode);//tested
	void initDeck(CardNode *mpHead);//used in constructor //works!!
	Card *DealCard(CardNode **mpHead);//needs testing
	Card *deleteAtFront(CardNode **mpHead);//needs testing
	void destroyDeck(CardNode *mpHead);
	
};

std::ostream & operator<< (std::ostream &lhs, Deck &rhs);
Deck & operator<< (Deck &lhs, Deck &rhs);
Deck & operator<< (Deck &lhs, Card *rhs);
