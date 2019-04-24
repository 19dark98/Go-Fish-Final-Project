#pragma once
#include "GameState.h"
class HumanTurn : public GameState
{
public:
	HumanTurn(GameEngine *game2);
	~HumanTurn();

	virtual void init();

	//this is the how events are handled
	void HandleEvents(GameEngine *game2);

	//|Updates the Game Logic|
	void Update(GameEngine *game2);

	//|Draws to the Window|
	void Draw(GameEngine* game2);
private:
	int selectedIndex;

	void keyboardPressEvent();
	void moveRight();
	void moveLeft();
public:
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

