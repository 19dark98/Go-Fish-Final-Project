#include "GameState.h"
#include "GameEngine.h"


GameState::GameState()
{
	
}

//gets pointers for window and event handling for ease of use
void GameState::getRefs(GameEngine* game)
{
	this->eventPtr = &game->event;
	this->windowPtr = &game->window;
}