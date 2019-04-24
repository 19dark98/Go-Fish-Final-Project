#include "HumanTurn.h"
//#include "GameEngine.h"



HumanTurn::HumanTurn(GameEngine *game2) : GameState(game2)
{
	selectedIndex = 1;
}


HumanTurn::~HumanTurn()
{
}
void HumanTurn::init()
{
	
}


void HumanTurn::HandleEvents(GameEngine *game2)
{
	while (this->game2->window.pollEvent(this->game2->event))
	{
		switch (this->game2->event.type)
		{
		case sf::Event::KeyPressed:
			
			break;
		}
	}
}

void  HumanTurn::Update(GameEngine *game2)
{

}

//|Draws to the Window|
void  HumanTurn::Draw(GameEngine* game2)
{
	this->DrawGame();
}




void HumanTurn::keyboardPressEvent()
{
	switch (game2->event.key.code)
	{
	case sf::Keyboard::Left:

		break;
	}
}
void HumanTurn::moveRight()
{

}
void HumanTurn::moveLeft()
{

}



void HumanTurn::DrawGame()
{
	drawBackground();
	drawPlayerHand();
	drawCpuHand();
	drawDeck();
	drawPairNum();
}

void HumanTurn::MakeChoice(Player &curPlayersTurn, Player &otherPlayer, Card * selectedCard)
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
void HumanTurn::drawBackground()
{
	game2->window.draw(BackgroundSprite);
}
void HumanTurn::drawPlayerHand()
{

}
void HumanTurn::drawCpuHand()
{

}
void HumanTurn::drawDeck()
{

}
void HumanTurn::drawPairNum()
{

}


void HumanTurn::loadBackground()
{
	this->BackgroundTexture.loadFromFile("Assets/CardBackground.jpg");
	this->BackgroundSprite.setTexture(BackgroundTexture);
}
void HumanTurn::resizeBackground()
{
	BackgroundSprite.setScale(
		game2->window.getSize().x / BackgroundSprite.getLocalBounds().width,
		game2->window.getSize().y / BackgroundSprite.getLocalBounds().height
	);
}

bool HumanTurn::isGameOver()
{
	if (game2->CpuPlayer.countPairs() + game2->HumanPlayer.countPairs() == 26) return true;
	return false;
}
void HumanTurn::resetGame()
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

int HumanTurn::findVictor()
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