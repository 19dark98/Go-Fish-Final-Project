#pragma once
#include "GameState.h"

#define NUMBER_OF_OPTIONS 3
class Menu : public GameState
{
public:
	Menu();
	Menu(GameEngine * game);
	~Menu();

	//start end Functions
	void init();

	


	//this is the how events are handled
	void HandleEvents(GameEngine *game);
	void Update(GameEngine *game);
	void Draw(GameEngine* game);


private:
	sf::RectangleShape Background;

	sf::Texture BGtext;
	sf::Sprite BGsprite;

	int optionSelected;
	sf::Font font;
	sf::Text menu[NUMBER_OF_OPTIONS];


	//private functions


	void KeyPressedEvents();
	void MoveUp();
	void MoveDown();
	void SelectionMade();

};

