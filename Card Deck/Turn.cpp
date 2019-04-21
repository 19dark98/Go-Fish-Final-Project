#include "Turn.h"
#include "GameEngine.h"


Turn::Turn()
{
	
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

//private functions
void Turn::drawBackground()
{
	game->window.draw(BackgroundSprite);
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
		game->window.getSize().x / BackgroundSprite.getLocalBounds().width,
		game->window.getSize().y / BackgroundSprite.getLocalBounds().height
	);
}

bool Turn::isGameOver()
{
	if (game->CpuPlayer.countPairs() + game->HumanPlayer.countPairs() == 26) return true;
	return false;
}
void Turn::resetGame()
{
	//clears pairs
	game->CpuPlayer.clearPairs();
	game->HumanPlayer.clearPairs();
	//clears hands
	game->CpuPlayer.clearHand();
	game->HumanPlayer.clearHand();
	//resets deck
	game->deck.resetDeck();
}