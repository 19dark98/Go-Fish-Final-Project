#include "Hand.h"
#include "DeckTests.h"
#include "TestHand.h"
#include "TestStack.h"

#include "GameEngine.h"


#include "Menu.h"

#include "SFML/Graphics.hpp"

int main()
{
	//test cases
	TestHand testHand;
	testHand.TestPropertiesEmpty();
	DeckTests dt;
	dt.testDeal();
	dt.testConstructors();
	TestStack testStack;
	testStack.testPush();
	testStack.testDestructor();
	

	GameEngine game;
	//init gameEngine
	
	game.GameLoop();

	//runGameLoop
	

	return 0;
}