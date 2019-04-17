#include "Hand.h"
#include "Player.h"

//test includes
#include "DeckTests.h"
#include "TestHand.h"
#include "TestStack.h"
#include "PlayerTests.h"

//include engine
#include "GameEngine.h"



int main()
{
	//test cases
	TestHand testHand;
	TestStack testStack;
	DeckTests dt;
	PlayerTests pt;
	testHand.TestPropertiesEmpty();
	dt.testDeal();
	dt.testConstructors();
	
	testStack.testPush();
	testStack.testDestructor();
	pt.testDraw();
	pt.testCheckPairs();

	//end of test cases

	GameEngine game;
	//init gameEngine
	
	game.GameLoop();

	//runGameLoop
	

	return 0;
}