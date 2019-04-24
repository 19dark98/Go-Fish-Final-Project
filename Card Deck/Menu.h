#pragma once
#include "GameState.h"


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

	int curstate;
	void KeyPressedEvents();
	void MoveUp();
	void MoveDown();
	void SelectionMade();


	
};

enum states { menustate, rules, playgame };