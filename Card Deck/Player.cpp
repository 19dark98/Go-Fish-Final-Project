#include "Player.h"
#include "Card.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::DisplayHand()
{
	std::cout << playerHand;
}


void Player::drawCards(Deck &deck, int num)
{
	for (int i = 0; i < num && !deck.isEmpty(); i++)
	{
		playerHand.addCard(deck.DealCard());
	}
	if (playerHand.getDeckLength() > 1) checkForPairs();
}

int Player::checkForPairs()
{
	playerHand.getDeckLength();
	int numPairs = 0;
	for (int i = 1; i < playerHand.getDeckLength(); i++)
	{
		if (isFaceValueEqual(*playerHand.getPointerAtN(i)->getCardNode(), *playerHand.getPointerAtN(i + 1)->getCardNode()))
		{
			pairList.push(new Node<Pairs*>(new Pairs(playerHand.discardAtNodeN(i), playerHand.discardAtNodeN(i))));
			numPairs++;
			i--;

		}
	}
	return numPairs;
}

//Private functions

void Player::addPair(int location)
{

}