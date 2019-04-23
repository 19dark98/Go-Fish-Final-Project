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

	//used to get the handsize of playerHand because playerHand is private
	int getHandSize() { return playerHand.getDeckLength(); };

	//used to get check if playerHand is empty
	bool isHandEmpty() { return playerHand.isEmpty(); };//tested

	//draws cards to playerHand from Deck
	void drawCards(Deck &deck, int num);//tested

	//checks Hand for pairs
	int checkForPairs();//tested
	void clearPairs() { pairList.clearStack(); };
	void clearHand() { playerHand.clearDeck(); };
	//functions reguarding Pairs
	int countPairs() { return pairList.getSize(); };

	//for testing
	void insertCard(int suit, int faceVal) { playerHand.addCard(new Card(suit, faceVal)); };
private:
	//hand helper functions

	//adds a pair at a given location to the pairList
	void addPair(int location);
};




