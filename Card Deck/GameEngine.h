#pragma once
//sfml includes
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
//
#include "Hand.h"
//state dependencies - add Gamestates here


//std Lib dependencies
#include <vector>

class GameState;
class GameEngine
{
public:
	GameEngine();
	void init();
	void cleanup();//most likely not nessesary

	//state management
	void pushState(GameState *nState);
	void popState(); 
	GameState * peekState();
	

	
	void GameLoop();



	sf::RenderWindow window;
	sf::Event event;
	//test info
	int i = 1;
private:
	//keeps track of all the game states and used to call current
	std::vector<GameState *> states;

	//store any data that needed for the game here



	//end of game data*****************************

	//private functions

	//window functions
	void createWindow(int height, double Ratio, std::string name);
};

