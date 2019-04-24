#pragma once
#include "GameState.h"

#define RULE_LINES 6
#define NUMBER_OF_OPTIONS 3
class Menu : public GameState
{
public:
	Menu();
	Menu(GameEngine * game2);
	~Menu();

	//start end Functions
	void init();

	


	//this is the how events are handled
	void HandleEvents(GameEngine *game2);
	void Update(GameEngine *game2);
	void Draw(GameEngine* game2);


private:
	sf::RectangleShape Background;

	sf::Texture BGtext;
	sf::Sprite BGsprite;

	int optionSelected;
	sf::Font font;
	sf::Text menu[NUMBER_OF_OPTIONS];


	//private functions

	int currentState;
	void KeyPressedEvents();
	void MoveUp();
	void MoveDown();
	void SelectionMade();

	//rules page
	sf::Text ruleLines[RULE_LINES];
	void initRules();
	void displayRules();
	
	//player turn page
	void displayBoard();
	void displayPlayerHand();
	void displayCpuHand();

	//cursor stuff
	void displayCursor();
	sf::Sprite cursor;
	sf::Texture cursorTexture;
	int cursorSelection;


	//decision making for player
	void MakeChoice(Player &curPlayersTurn, Player &otherPlayer, Card * selectedCard);

	bool isGameOver();
	void resetGame();
	void findVictor();
	int victorStatus;
	void resizeDeck(Deck &deck);

	sf::Clock clock;
	sf::Text winnerText;
};

enum states { menustate, rules, playerTurn, CPUturn, showWinner };

