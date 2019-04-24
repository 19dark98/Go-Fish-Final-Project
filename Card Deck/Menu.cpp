#include "Menu.h"
//#include "HumanTurn.h"
//must be included inorder to access the gameEngine functions
//#include "GameEngine.h"
//#include "GameState.h"
#include <exception>

Menu::Menu()
{
	
}

Menu::Menu(GameEngine * game2) : GameState(game2)
{
	init();
	initRules();
	resizeDeck((game->deck));
	currentState = menustate;
	winnerText.setColor(sf::Color::Yellow);
	winnerText.setPosition(game->window.getSize().x/5, game->window.getSize().y/2);
	winnerText.setFont(*menu[0].getFont());
	winnerText.setCharacterSize(45);


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

	//cursor init
	cursorTexture.loadFromFile("Assets/cursor.png");
	cursor.setTexture(cursorTexture);
	cursorSelection = 1;
}


//most likely wont be used


//this is the how events are handled
void Menu::HandleEvents(GameEngine *game2)
{
	

	
	
	switch (currentState)
	{
	case menustate:
		while (game2->window.pollEvent(game2->event))
		{

			switch (game2->event.type)
			{
			case sf::Event::Closed:
				this->game->window.close();
				break;
			case sf::Event::KeyPressed:
				KeyPressedEvents();

				
				break;
			}

		}
		break;
	case rules:
	
		while (game2->window.pollEvent(game2->event))
		{

			switch (game2->event.type)
			{
			case sf::Event::Closed:
				this->game->window.close();
				break;
			case sf::Event::KeyPressed:
				if (game->event.key.code == sf::Keyboard::Enter) currentState = menustate;
				break;
			}

		}
		break;

	case playerTurn:
		while (game2->window.pollEvent(game2->event))
		{

			switch (game2->event.type)
			{
			case sf::Event::Closed:
				this->game->window.close();
				break;
			case sf::Event::KeyPressed:
				if (game2->event.key.code == sf::Keyboard::Left && cursorSelection - 1 > 0)
				{
					cursorSelection--;
				}
				if (game2->event.key.code == sf::Keyboard::Right && cursorSelection + 1 <= game->HumanPlayer.playerHand.getDeckLength())
				{
					cursorSelection++;
				}
				if (game2->event.key.code == sf::Keyboard::Enter)
				{
					MakeChoice(game->HumanPlayer, game->CpuPlayer, game->HumanPlayer.getNodeAtN(cursorSelection));
					cursorSelection = 1;
					currentState = CPUturn;
					if (isGameOver()) {
						findVictor();
						resetGame();
						currentState = showWinner;
					}
				}
				if (game->event.type == game->event.KeyPressed)
				{
					if (game->event.key.code == sf::Keyboard::P)
						cout << "paused";
				}
				break;
			}

		}

	case showWinner:
		while (game2->window.pollEvent(game2->event))
		{

			switch (game2->event.type)
			{
			case sf::Event::Closed:
				this->game->window.close();
				break;
			case sf::Event::KeyPressed:
				if (game->event.key.code == sf::Keyboard::Enter) {
					currentState = menustate;
					resetGame();
				}
				break;
			}

		}
		break;
	}
	
}
void Menu::Update(GameEngine *game2)
{
	switch (currentState)
	{
	case menustate:
		break;
	case rules:
		break;
	case CPUturn:
		MakeChoice(game->CpuPlayer, game2->HumanPlayer, game->CpuPlayer.getNodeAtN(rand() % game->CpuPlayer.getHandSize() + 1));
		currentState = playerTurn;
		
		if (isGameOver()) {
			findVictor();
			//resetGame();
			currentState = showWinner;
		}
		break;
	case playerTurn:
		if (isGameOver()) {
			findVictor();
			//resetGame();
			currentState = showWinner;
		}
		break;
	}
	
}
void Menu::Draw(GameEngine* game2)
{
	game2->window.draw(BGsprite);
	
	switch (currentState)
	{
	case menustate:
		for (int i = 0; i < NUMBER_OF_OPTIONS; i++)
		{
			game2->window.draw(this->menu[i]);
		}
		break;
	case rules:
		displayRules();
		break;
	case playerTurn:
	case CPUturn:
		displayBoard();
		break;
	case showWinner:
		game->window.draw(winnerText);
		break;

	}
	
	
	game2->window.display();
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
		currentState = playerTurn;
		break;
	case 1:
		currentState = rules;
		break;
	case 2:
		game->popState();
		break;
	}
}


//rules functions
void Menu::initRules()
{
	ruleLines[0].setFont(font);
	ruleLines[0].setCharacterSize(40);
	ruleLines[0].setColor(sf::Color::Red);
	ruleLines[0].setString("Rules!");
	ruleLines[0].setPosition(sf::Vector2f(20,0));

	ruleLines[1].setFont(font);
	//ruleLines[1].setCharacterSize(60);
	ruleLines[1].setColor(sf::Color::White);
	ruleLines[1].setString("Rule 1! -> Draw 6 cards.");
	ruleLines[1].setPosition(sf::Vector2f(20,100));

	ruleLines[2].setFont(font);
	//ruleLines[2].setCharacterSize(60);
	ruleLines[2].setColor(sf::Color::White);
	ruleLines[2].setString("Rule 2! -> Ask the opposing player if they have a pair of a card you are holding");
	ruleLines[2].setPosition(sf::Vector2f(20, 200));

	ruleLines[3].setFont(font);
	//ruleLines[3].setCharacterSize(60);
	ruleLines[3].setColor(sf::Color::White);
	ruleLines[3].setString("Rule 3! -> If you or your opponent don't have the card you \"go fish\"");
	ruleLines[3].setPosition(sf::Vector2f(20, 300));

	ruleLines[4].setFont(font);
	//ruleLines[4].setCharacterSize(60);
	ruleLines[4].setColor(sf::Color::White);
	ruleLines[4].setString("Rule 4! -> When the deck runs out, the player with the highest nnumber of pairs win!");
	ruleLines[4].setPosition(sf::Vector2f(20,400));

	ruleLines[5].setFont(font);
	//ruleLines[5].setCharacterSize(60);
	ruleLines[5].setColor(sf::Color::White);
	ruleLines[5].setString("Rule 5! -> hAvE fUn"); //for you Andy if you read this
	ruleLines[5].setPosition(sf::Vector2f(20,500));
}

void Menu::displayRules()
{
	for (int i = 0; i < RULE_LINES; i++)
	{
		game->window.draw(ruleLines[i]);
	}
}

void Menu::displayBoard()
{
	displayPlayerHand();
	displayCursor();
	displayCpuHand();
}

void Menu::displayPlayerHand()
{
	sf::Sprite * spritePtr = nullptr;
	if (!game->deck.isEmpty())
	{
		for (int i = 1; i <= game->HumanPlayer.playerHand.getDeckLength(); i++) {
			try
			{
				if (game->HumanPlayer.playerHand.getPointerAtN(i) != nullptr)
				{
					spritePtr = &game->HumanPlayer.playerHand.getPointerAtN(i)->getCardNode()->cardSprite;
					spritePtr->setPosition((i - 1) * 110, game->window.getSize().y - 150);
					//spritePtr->setScale(.5, .5);

					spritePtr->setScale((game->window.getSize().x / 13) / game->deck.getPointerAtN(i)->getCardNode()->cardSprite.getLocalBounds().width, (game->window.getSize().x / 13) / game->deck.getPointerAtN(i)->getCardNode()->cardSprite.getLocalBounds().width);
					game->window.draw(*spritePtr);
				}
			}
			catch (...)
			{

			}
			
		}
	
		
		
	}
	
}
void Menu::displayCpuHand()
{
	sf::Sprite * spritePtr;
	if (!game->deck.isEmpty())
	{
		for (int i = 1; i <= game->CpuPlayer.getHandSize(); i++)
		{
			try
			{
				if (game->CpuPlayer.playerHand.getPointerAtN(i) != nullptr)
				{
					spritePtr = &game->CpuPlayer.playerHand.getPointerAtN(i)->getCardNode()->cardSprite;
					spritePtr->setTexture(game->faceDownCard);
					spritePtr->setScale((game->window.getSize().x / 13) / game->deck.getPointerAtN(i)->getCardNode()->cardSprite.getLocalBounds().width, (game->window.getSize().x / 13) / game->deck.getPointerAtN(i)->getCardNode()->cardSprite.getLocalBounds().width);
					spritePtr->setPosition((i - 1) * 110, 10);

					game->window.draw(*spritePtr);
				}
			}
			catch (...)
			{
				continue;
			}
			
		}
	}
	
}
void Menu::displayCursor()
{
	sf::Sprite *spritePtr = &game->HumanPlayer.playerHand.getPointerAtN(cursorSelection-1)->getCardNode()->cardSprite;
	cursor.setScale(105 / cursor.getLocalBounds().width, 105 / cursor.getLocalBounds().width);
	cursor.setPosition((cursorSelection - 1)*103, game->window.getSize().y - 280);
	game->window.draw(cursor);
}
void Menu::MakeChoice(Player &curPlayersTurn, Player &otherPlayer, Card * selectedCard)
{
	int index = otherPlayer.hasMatch(selectedCard);
	if (index)
	{
		curPlayersTurn.addCard(otherPlayer.RemoveCard(index));
		while (otherPlayer.isHandEmpty() && !game->deck.isEmpty())
		{
			otherPlayer.drawCards(this->game->deck, 4);
		}
		curPlayersTurn.checkForPairs();
		while (curPlayersTurn.isHandEmpty() && !game->deck.isEmpty())
		{
			curPlayersTurn.drawCards(this->game->deck, 4);
		}

	}
	else
	{
		curPlayersTurn.drawCards(game->deck, 1);
		curPlayersTurn.checkForPairs();
		while (curPlayersTurn.isHandEmpty() && !game->deck.isEmpty()) curPlayersTurn.drawCards(game->deck, 4);
	}

}
void Menu::resizeDeck(Deck &deck)
{
	for (int i = 1; i <= deck.getDeckLength(); i++) {
		float width = (game->window.getSize().x / 13) / deck.getPointerAtN(i)->getCardNode()->cardSprite.getLocalBounds().width;
		game->deck.getPointerAtN(i)->getCardNode()->cardSprite.setScale(.25, .25);

		//deck.getPointerAtN(i)->getCardNode()->cardSprite.setScale(width, width *5 /7.0);
	}
	
}

bool Menu::isGameOver()
{
	if (game->CpuPlayer.countPairs() + game->HumanPlayer.countPairs() >= 25) return true;
	return false;
}
void Menu::resetGame()
{
	//clears pairs
	game->CpuPlayer.clearPairs();
	game->HumanPlayer.clearPairs();
	//clears hands
	game->CpuPlayer.clearHand();
	game->HumanPlayer.clearHand();
	//resets deck
	game->deck.resetDeck();

	clock.restart();
}
void Menu::findVictor()
{

	std::string message;
	int victorStatus = 0;
	if (game->HumanPlayer.countPairs() > game->CpuPlayer.countPairs())
	{
		victorStatus = 1;
		message = "(You won with " + std::to_string(game->HumanPlayer.countPairs()) + " pairs!)";
		this->winnerText.setString(message);
	}
	if (game->HumanPlayer.countPairs() < game->CpuPlayer.countPairs())
	{
		message = "(You lost to a crappily programmed npc bro!)";
		victorStatus = -1;
		this->winnerText.setString(message);
	}
}