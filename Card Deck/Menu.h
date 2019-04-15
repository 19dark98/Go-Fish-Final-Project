#pragma once
#include "GameState.h"
class Menu : public GameState
{
public:
	Menu();
	Menu(GameEngine * game);
	~Menu();
	//start end Functions
	void init();
	void cleanup();

	//most likely wont be used
	

	//this is the how events are handled
	void HandleEvents(GameEngine *game);
	void Update(GameEngine *game);
	void Draw(GameEngine* game);
};

