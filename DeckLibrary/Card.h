#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;


class Card
{
public:

	Card();//tested

	Card(int const iniSuit, int const iniFaceValue);//tested

	Card(Card const &copy);

	~Card();
	//getters
	int getSuit();

	int getFaceValue();

	//setters
	void setSuit(int const newSuit);

	void setFaceValue(int const newFaceValue);

	//other functions
	Card operator=(Card &c);
private:
	int suit;//cards suit

	int faceValue; // cards numerical value
};

//nonMember functions
void printCard(Card &c);//tested
void printCard(std::ostream &stream, Card &c);//tested
bool operator==(Card &lhs, Card &rhs);//tested
bool operator!=(Card &lhs, Card &rhs);//tested
bool operator>(Card &lhs, Card &rhs);//wip
bool operator<(Card &lhs, Card &rhs);
bool operator<=(Card &lhs, Card &rhs);
bool operator>=(Card &lhs, Card &rhs);


bool isFaceValueEqual(Card &c1, Card &c2);
bool isSuitEqual(Card &c1, Card &c2);
int suitcmp(Card &c1, Card &c2);
int facecmp(Card &c1, Card &c2);
int cardcmp(Card &c1, Card &c2);
std::ostream & operator<< (std::ostream &lhs, Card &rhs);

