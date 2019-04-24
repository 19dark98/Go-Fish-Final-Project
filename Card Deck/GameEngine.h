#pragma once
//sfml includes
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
//
//#include "Hand.h"
#include "Player.h"
//state dependencies - add Gamestates here


//std Lib dependencies
#include <vector>
#include <thread>

class GameState;
class GameEngine
{
public:
	GameEngine();
	void init();
	void cleanup();//most likely not nessesary

	//state management functions

	/*
	these functions are used to transition game states from one to the next.
	since the GameState class contains a pointer to the GameEngine these functions can be called within
	from the derived classes that inherit GameState.
	*/
	
	//pushes a state to the top of the stack
	void pushState(GameState *nState);
	//removes a state from the top of the stack
	void popState(); 
	/*
	gets the pointer to the gamestate at the top of the stack. 
	this is used to call the functions: HandleEvents(), Update(), Draw() which are contained in GameState.
	*/
	GameState * peekState();
	

	//this is the main game loop which runs the game.
	void GameLoop();


	//call these variables with the GameEngine pointer to update the game
	sf::RenderWindow window;
	sf::Event event;
	
	//added player and deck information
	//these are used to store the game information
	//can be accessed through the GameEngine pointer
	Player HumanPlayer;
	Player CpuPlayer;
	Deck deck;
	sf::Texture faceDownCard;
	std::vector<GameState *> states;
private:
	//keeps track of all the game states and used to call current running gamestate
	

	//store any data that needed for the game here

	void pushPlayerState();

	//end of game data*****************************

	//private functions

	//window functions

	/*
	called when during GameEngine's init() called in the Constructor.
	creates the window which the game is displayed.
	*/
	void createWindow(int height, double Ratio, std::string name);
};


