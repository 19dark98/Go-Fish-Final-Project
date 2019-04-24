#pragma once
#include "SFML/Graphics.hpp"
#include <string>


class WrappedText :
	public sf::Text
{
public:
	WrappedText(sf::IntRect TextArea,std::string const &string);
	~WrappedText();

private:
	sf::IntRect boundingArea;
	int linesInBox;

	int getWordPxWidth(std::string &word);
};

