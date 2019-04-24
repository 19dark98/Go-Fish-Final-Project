#include "GameState.h"
//#include "GameEngine.h"

GameState::GameState()
{

}
GameState::GameState(GameEngine * game2)
{
	this->game = game2;
}

//gets pointers for window and event handling for ease of use
void GameState::getRefs(GameEngine* game2)
{
	this->eventPtr = &game2->event;
	this->windowPtr = &game2->window;
}