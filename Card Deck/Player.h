#pragma once
#include "Hand.h"
#include "Stack.h"
#include "Pairs.h"
class Player
{
protected:
	Hand playerHand;
	Stack<Pairs *> pairList;
public:
	Player();
	virtual ~Player();
	//functions reguarding Player hand

	//displays Hand to console
	void DisplayHand();
	int getHandSize() { return playerHand.getDeckLength(); };
	bool isHandEmpty() { return playerHand.isEmpty(); };//tested
	void drawCards(Deck &deck, int num);//tested
	int checkForPairs();//tested
	void clearPairs() { pairList.clearStack(); };
	void clearHand() { playerHand.clearDeck(); };
	//functions reguarding Pairs
	int countPairs() { return pairList.getSize(); };

	//for testing
	void insertCard(int suit, int faceVal) { playerHand.addCard(new Card(suit, faceVal)); };
private:
	//hand helper functions
	void addPair(int location);
};




