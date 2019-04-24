#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "GameEngine.h"
//forward declaration used to access the engine data without causing infinite recursive calls
//class GameEngine;

class GameState
{
protected:
	sf::RenderWindow * windowPtr;
	sf::Event * eventPtr;
public:
	GameState();
	GameState(GameEngine * game);
	//start end Functions
	virtual void init() = 0;
	
	GameEngine * game;
	


	//this is the how events are handled
	virtual void HandleEvents(GameEngine *game2) = 0;

	//|Updates the Game Logic|
	virtual void Update(GameEngine *game2) = 0;

	//|Draws to the Window|
	virtual void Draw(GameEngine* game2) = 0;


	//obsolete function
	virtual void getRefs(GameEngine*);

private:
	
};




