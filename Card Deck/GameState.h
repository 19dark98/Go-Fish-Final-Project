#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

//forward declaration used to access the engine data without casueing infinite recursive calls
class GameEngine;

class GameState
{
protected:
	sf::RenderWindow * windowPtr;
	sf::Event * eventPtr;
public:
	GameState();
	//start end Functions
	virtual void init() = 0;
	virtual void cleanup() = 0;

	//most likely wont be used


	//this is the how events are handled
	virtual void HandleEvents(GameEngine *game) = 0;
	virtual void Update(GameEngine *game) = 0;
	virtual void Draw(GameEngine* game) = 0;

	virtual void getRefs(GameEngine*);

private:
	
};



