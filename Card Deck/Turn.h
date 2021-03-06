#pragma once
#include "GameState.h"
#include "Player.h"


class Turn /*:
	public GameState*/
{
public:
	Turn(GameEngine *game2);
	virtual ~Turn();

	//draws the game board with all the information
	void DrawGame();
	void MakeChoice(Player &curPlayersTurn, Player &otherPlayer, Card * selectedCard);


	//new stuff
	GameEngine *game2;
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

	/*
	1 = Human victory
	0 = Draw
	-1 = CPU victory
	*/
	int findVictor();//needs testing
	//virtual functions that will be overridden in derived class
	//virtual void chooseCard() = 0;
};

