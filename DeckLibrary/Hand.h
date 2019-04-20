#pragma once
#define HAND_SIZE this->getDeckLength()
#include "deck.h"

class Hand : public Deck
{
public:
	//constructors
	Hand();
	Hand(Deck &d,int handSize);
	~Hand();
	void sortHand();
	Card *discardAtNodeN(int n);
	void addCard(Card *c);
	
	//properties
	bool hasSuit(int suit);
	bool hasFace(int face);
	bool hasCard(int suit, int face);
	bool hasCard(int suit, int face, int &index);
	bool hasCard(Card c);
	bool hasCard(Card c, int &index);

	//operators
	Card *operator[](int i);
private:
	//private DataFields
	

	//functions
	void sortHand(CardNode *pHead);
	void swapCard(int index1, int index2);
	void insertInOrder(Card *c, CardNode *node);
	Card *discardAtNodeN(int n, CardNode *pHead);
};


//operators
ostream & operator<< (ostream &lhs, Hand &rhs);

//other functions


