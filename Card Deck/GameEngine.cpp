#include "GameEngine.h"

//called when the game engine is first initiated
//place information that is initialized once at the beginning of the game
void GameEngine::init()
{
	createWindow(800, 16 / 9, "Test");
	pushState(new Menu());
}
//used to go to new gamestate
void GameEngine::pushState(GameState *nState)
{
	states.push_back(nState);
}
//gets pointer to game state
GameState * GameEngine::peekState()
{
	return states[states.size() - 1];
}
//removes gamestate from stack
void GameEngine::popState()
{
	states.pop_back();
}
//initializes the game window
void GameEngine::createWindow(int height, double Ratio, std::string name)
{
	window.create(sf::VideoMode(height, height*Ratio), name);
}

