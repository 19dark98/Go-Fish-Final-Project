#include "GameEngine.h"
#include "Menu.h"





GameEngine::GameEngine()
{
	init();
	

}

//called when the game engine is first initiated
//place information that is initialized once at the beginning of the game
void GameEngine::init()
{
	createWindow(800, 16.0 / 9, "Test");
	states.push_back(new Menu(this));

	//initialize Hands and Deck
	deck.resetDeck();
	HumanPlayer.drawCards(deck, 7);
	CpuPlayer.drawCards(deck, 7);
}
//used to go to new gamestate
void GameEngine::pushState(GameState *nState)
{
	states.push_back(nState);
}
//gets pointer to game state
GameState * GameEngine::peekState()
{
	return (states[states.size() - 1]);
}
//removes gamestate from stack
void GameEngine::popState()
{
	states.pop_back();
}

void GameEngine::GameLoop()
{
	while (window.isOpen())
	{


		
		//handle Events
		if (!states.empty()) peekState()->HandleEvents(&(*this));
		else window.close();

		window.clear();
		
		if (!states.empty()) peekState()->Update(&(*this));
		else window.close();


		if (!states.empty()) peekState()->Draw(&(*this));
		else window.close();


	}
}
//initializes the game window
void GameEngine::createWindow(int height, double Ratio, std::string name)
{
	double widthdouble = height * Ratio;
	int width = (int)round(widthdouble);
	window.create(sf::VideoMode(width, height), name);
}


void GameEngine::pushPlayerState()
{
	
	//HumanTurn * hTurn = new HumanTurn(this);
	//states.push_back(hTurn);
}