#include "Hand.h"
#include "Player.h"
#include "WrappedText.h"
//test includes
#include "DeckTests.h"
#include "TestHand.h"
#include "TestStack.h"
#include "PlayerTests.h"

//include engine
#include "GameEngine.h"



int main()
{
	sf::Clock clock;
	clock.restart();
	//test cases
	TestHand testHand;
	TestStack testStack;
	DeckTests dt;
	PlayerTests pt;
	testHand.TestPropertiesEmpty();
	dt.testDeal();
	dt.testConstructors();
	dt.testDestroyDeck();
	testStack.testPush();
	testStack.testDestructor();
	pt.testDraw();
	pt.testCheckPairs();

	//end of test cases
	cout << clock.getElapsedTime().asSeconds();
	


	GameEngine game2;
	//init gameEngine
	

	

	game2.GameLoop();

	//runGameLoop
	

	return 0;
}