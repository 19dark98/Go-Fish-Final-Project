#include "Menu.h"

//must be included inorder to access the gameEngine functions
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
	//set Background
	Background.setSize(sf::Vector2f(game->window.getSize()));
	Background.setPosition(0, 0);
	Background.setFillColor(sf::Color::Black);

	BGtext.loadFromFile("Assets/CardTable.jpg");
	BGsprite.setTexture(BGtext);
	BGsprite.setScale(game->window.getSize().x / BGsprite.getLocalBounds().width, game->window.getSize().y / BGsprite.getLocalBounds().height);


	this->font.loadFromFile("Assets/RioGrande.ttf");

	menu[0].setFont(font);
	menu[0].setCharacterSize(60);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(game->window.getSize().x / 2, game->window.getSize().y / (NUMBER_OF_OPTIONS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setCharacterSize(60);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Rules");
	menu[1].setPosition(sf::Vector2f(game->window.getSize().x / 2, game->window.getSize().y / (NUMBER_OF_OPTIONS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setCharacterSize(60);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(game->window.getSize().x / 2, game->window.getSize().y / (NUMBER_OF_OPTIONS + 1) * 3));

	this->optionSelected = 0;


}


//most likely wont be used


//this is the how events are handled
void Menu::HandleEvents(GameEngine *game)
{
	while (game->window.pollEvent(game->event))
	{
		switch (game->event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;
		case sf::Event::KeyPressed:
			KeyPressedEvents();
			break;
		}
		
	}
}
void Menu::Update(GameEngine *game)
{

}
void Menu::Draw(GameEngine* game)
{
	game->window.draw(BGsprite);
	
	for (int i = 0; i < NUMBER_OF_OPTIONS; i++)
	{
		game->window.draw(this->menu[i]);
	}
	game->window.display();
}


void Menu::KeyPressedEvents()
{
	if (game->event.key.code == sf::Keyboard::Up)
	{
		MoveUp();
	}
	if (game->event.key.code == sf::Keyboard::Down)
	{
		MoveDown();
	}
	if (game->event.key.code == sf::Keyboard::Enter)
	{
		SelectionMade();
	}
}

void Menu::MoveUp()
{
	if (optionSelected - 1 >= 0)
	{
		menu[optionSelected].setColor(sf::Color::White);
		optionSelected--;
		menu[optionSelected].setColor(sf::Color::Red);
	}
}
void Menu::MoveDown()
{
	if (optionSelected + 1 < NUMBER_OF_OPTIONS)
	{
		menu[optionSelected].setColor(sf::Color::White);
		optionSelected++;
		menu[optionSelected].setColor(sf::Color::Red);
	}
}

void Menu::SelectionMade()
{
	switch (optionSelected)
	{
	case 0://push HumanPlayerTurn
		
		break;
	case 1:
		//push Rules
		break;
	case 2:
		game->popState();
		break;
	}
}