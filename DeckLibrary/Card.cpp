#include "Card.h"

using std::to_string;
//constructors
Card::Card()
{
	suit = 0;
	faceValue = 0;
}
Card::Card(int const iniSuit, int const iniFaceValue)
{
	setFaceValue(iniFaceValue);
	setSuit(iniSuit);
	string filePath = "Assets/" + to_string(suit)+ " "+ to_string(faceValue) + ".png";

	cardTexture.loadFromFile(filePath);
	cardSprite.setTexture(cardTexture);

}
Card::Card(Card const &copy)
{
	faceValue = copy.faceValue;
	suit = copy.suit;
}

//destructor
Card::~Card()
{
	
}

//Getters
int Card::getSuit()
{
	return suit;
}
int Card::getFaceValue()
{
	return faceValue;
}

//Setters

//precondition: values must be within valid range
void Card::setSuit(int const newSuit)
{
	if (newSuit >= 1 && newSuit <= 4) suit = newSuit;
	else suit = 0;

}
void Card::setFaceValue(int const newFaceValue)
{
	if (newFaceValue >= 1 && newFaceValue <= 13) faceValue = newFaceValue;
	else faceValue = 0;
}
//other functions
Card Card::operator=(Card &c)
{
	setSuit(c.suit);
	setFaceValue(c.faceValue);
	return c;
}


//nonMember functions
void printCard(Card &c)
{
	std::string suitValues[5] = { "","Spades","Clubs","Diamonds","Hearts" };
	std::string faceValues[14] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
	std::cout << faceValues[c.getFaceValue()] << " of " << suitValues[c.getSuit()] << std::endl;
}
void printCard(std::ostream &stream, Card &c)
{
	std::string suitValues[5] = { "","Spades","Clubs","Diamonds","Hearts" };
	std::string faceValues[14] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
	stream << faceValues[c.getFaceValue()] << " of " << suitValues[c.getSuit()] << std::endl;
}
bool operator==(Card &lhs, Card &rhs)
{
	bool isEqual = false;
	if (lhs.getFaceValue() == rhs.getFaceValue() && lhs.getSuit() == rhs.getSuit()) isEqual = true;
	return isEqual;
}

bool operator!=(Card &lhs, Card &rhs)
{
	bool isEqual = false;
	if (lhs.getFaceValue() == rhs.getFaceValue() && lhs.getSuit() == rhs.getSuit()) isEqual = true;
	return !isEqual;
}
bool operator>(Card &lhs, Card &rhs)
{
	bool isGreaterThan = false;
	if (cardcmp(lhs, rhs) == 1)
	{
		isGreaterThan = true;
	}
	return isGreaterThan;
}
bool operator<(Card &lhs, Card &rhs)
{
	bool isLessThan = false;
	if (cardcmp(lhs, rhs) == -1) isLessThan = true;
	return isLessThan;
}
bool operator<=(Card &lhs, Card &rhs)
{
	bool isGreaterThan = false;
	if (cardcmp(lhs, rhs) == 1)
	{
		isGreaterThan = true;
	}
	return !isGreaterThan;
}
bool operator>=(Card &lhs, Card &rhs)
{
	bool isLessThan = false;
	if (cardcmp(lhs, rhs) == -1) isLessThan = true;
	return !isLessThan;
}
bool isFaceValueEqual(Card &c1, Card &c2)
{
	bool isEqual = 0;
	if (c1.getFaceValue() == c2.getFaceValue()) isEqual = 1;
	return isEqual;
}
bool isSuitEqual(Card &c1, Card &c2)
{
	bool isEqual = 0;
	if (c1.getSuit() == c2.getSuit()) isEqual = 1;
	return isEqual;
}
int suitcmp(Card &c1, Card &c2)
{
	return c1.getSuit() - c2.getSuit();
}
int facecmp(Card &c1, Card &c2)
{
	return c1.getFaceValue() - c2.getFaceValue();
}
int cardcmp(Card &c1, Card &c2)
{
	int compareValue = 0;
	int differenceValue = facecmp(c1, c2);
	if (differenceValue < 0)
	{
		compareValue = -1;
	}
	else if (differenceValue > 0)
	{
		compareValue = 1;
	}
	else
	{
		differenceValue = suitcmp(c1, c2);
		if (differenceValue < 0)
		{
			compareValue = -1;
		}
		else if (differenceValue > 0)
		{
			compareValue = 1;
		}
		else compareValue = 0;
	}
	return compareValue;
}
std::ostream & operator<< (std::ostream &lhs, Card &rhs)
{
	printCard(lhs, rhs);
	return lhs;
}