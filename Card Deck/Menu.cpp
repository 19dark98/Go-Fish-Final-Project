#include "Menu.h"
#include "GameEngine.h"


Menu::Menu()
{
	
}

Menu::Menu(GameEngine * game) : GameState(game)
{
	init();
}

Menu::~Menu()
{
}

void Menu::init()
{
	rect.setSize(sf::Vector2f(game->window.getSize()));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Blue);

}


//most likely wont be used


//this is the how events are handled
void Menu::HandleEvents(GameEngine *game)
{

}
void Menu::Update(GameEngine *game)
{

}
void Menu::Draw(GameEngine* game)
{
	game->window.draw(rect);
	std::cout << "boop";

	game->window.display();
}