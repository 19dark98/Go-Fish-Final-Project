#include "Hand.h"
#include "DeckTests.h"
#include "TestHand.h"

#include "GameEngine.h"

#include "SFML/Graphics.hpp"

int main()
{
	


	GameEngine game;
	//init gameEngine
	game.init();


	//runGameLoop
	while (game.window.isOpen())
	{
		//handle Events
		game.peekState();
		
	}

	return 0;
}