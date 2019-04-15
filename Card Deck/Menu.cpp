
#include "Menu.h"
#include "GameEngine.h"
#include <iostream>

Menu::Menu()
{
}
Menu::Menu(GameEngine * game)
{
	getRefs(game);
}

Menu::~Menu()
{
}

void Menu::init()
{

}
void Menu::cleanup()
{

}


void Menu::HandleEvents(GameEngine *game)
{
	sf::RenderWindow *windowPtr = &(game->window);
	while (game->window.pollEvent(game->event)) {
		if (game->event.KeyPressed)
		{
			
			if (game->event.key.code == sf::Keyboard::Space) std::cout << "SpacePressed";
		}
	}
}
void Menu::Update(GameEngine *game)
{

}
void Menu::Draw(GameEngine* game)
{

}

