#include "Turn.h"

#include "GameEngine.h"
#include "Player.h"


Turn::Turn(GameEngine *game)//
{
	this->game2 = game;
}


Turn::~Turn()
{
}

void Turn::DrawGame()
{
	drawBackground();
	drawPlayerHand();
	drawCpuHand();
	drawDeck();
	drawPairNum();
}

void Turn::MakeChoice(Player &curPlayersTurn, Player &otherPlayer, Card * selectedCard)
{
	int index = otherPlayer.hasMatch(selectedCard);
	if (index)
	{
		curPlayersTurn.addCard(otherPlayer.RemoveCard(index));
		while (otherPlayer.isHandEmpty()) 
		{
			otherPlayer.drawCards(this->game2->deck, 4);
		}
		curPlayersTurn.checkForPairs();
		while (curPlayersTurn.isHandEmpty())
		{
			curPlayersTurn.drawCards(this->game2->deck, 4);
		}

	}
	else
	{
		curPlayersTurn.drawCards(game2->deck, 1);
		curPlayersTurn.checkForPairs();
		while (curPlayersTurn.isHandEmpty()) curPlayersTurn.drawCards(game2->deck, 4);
	}

}

//private functions
void Turn::drawBackground()
{
	game2->window.draw(BackgroundSprite);
}
void Turn::drawPlayerHand()
{

}
void Turn::drawCpuHand()
{

}
void Turn::drawDeck()
{

}
void Turn::drawPairNum()
{

}


void Turn::loadBackground()
{
	this->BackgroundTexture.loadFromFile("Assets/CardBackground.jpg");
	this->BackgroundSprite.setTexture(BackgroundTexture);
}
void Turn::resizeBackground()
{
	BackgroundSprite.setScale(
		game2->window.getSize().x / BackgroundSprite.getLocalBounds().width,
		game2->window.getSize().y / BackgroundSprite.getLocalBounds().height
	);
}

bool Turn::isGameOver()
{
	if (game2->CpuPlayer.countPairs() + game2->HumanPlayer.countPairs() == 26) return true;
	return false;
}
void Turn::resetGame()
{
	//clears pairs
	game2->CpuPlayer.clearPairs();
	game2->HumanPlayer.clearPairs();
	//clears hands
	game2->CpuPlayer.clearHand();
	game2->HumanPlayer.clearHand();
	//resets deck
	game2->deck.resetDeck();
}

int Turn::findVictor()
{
	int victorStatus = 0;
	if (game2->HumanPlayer.countPairs() > game2->CpuPlayer.countPairs())
	{
		victorStatus = 1;
	}
	if (game2->HumanPlayer.countPairs() < game2->CpuPlayer.countPairs())
	{
		victorStatus = -1;
	}

	return victorStatus;
}