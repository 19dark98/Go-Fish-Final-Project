//#include "Hand.h"
//#include "Player.h"
//#include "WrappedText.h"
//test includes
#include "DeckTests.h"
#include "TestHand.h"
#include "TestStack.h"
#include "PlayerTests.h"
#include "Menu.h"
//include engine
//#include "GameEngine.h"
//#include "Menu.h"
//#include "HumanTurn.h"


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
	


	GameEngine game;
	//init gameEngine
	
	game.states.push_back(new Menu(&game));
	//while (game.window.isOpen())
	//{



	//	//handle Events
	//	if (!game.states.empty()) game.peekState()->HandleEvents(&game);
	//	else game.window.close();

	//	game.window.clear();

	//	if (!game.states.empty()) game.peekState()->Update(&game);
	//	else game.window.close();


	//	if (!game.states.empty()) game.peekState()->Draw(&game);
	//	else game.window.close();


	//}

	game.GameLoop();

	//runGameLoop
	

	return 0;
}