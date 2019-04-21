#pragma once
#include "GameState.h"
class Turn :
	public GameState
{
public:
	Turn();
	virtual ~Turn();

	//draws the game board with all the information
	void DrawGame();

private:
	//data files
	sf::Texture BackgroundTexture;
	sf::Sprite BackgroundSprite;

	void drawBackground();//done needs testing
	
	//Needs Coding
	void drawPlayerHand();
	void drawCpuHand();
	void drawDeck();
	void drawPairNum();

	//functions called on initialization
	void loadBackground();//needs testing
	void resizeBackground();//needs testing

protected:
	bool isGameOver();
	void resetGame();

	//virtual functions that will be overridden in derived class
	//virtual void chooseCard() = 0;
};

