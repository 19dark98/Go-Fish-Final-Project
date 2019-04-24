#include "WrappedText.h"



WrappedText::WrappedText(sf::IntRect TextArea, std::string const &string)
{
	sf::Font font;
	font.loadFromFile("Assets/RioGrande.ttf");
	this->boundingArea = TextArea;
	this->setPosition(0, 0);

	this->setFont(font);
	this->setString(string);
}


WrappedText::~WrappedText()
{
}


int WrappedText::getWordPxWidth(std::string &word)
{
	Text sample;
	sample.setString(word);
	sample.setCharacterSize(this->getCharacterSize());
	sample.setFont(*this->getFont());
	return sample.getLocalBounds().width;
	
}