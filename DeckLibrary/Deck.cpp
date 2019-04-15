#include "deck.h"
//constructors

//Deck::Deck()
//{
//	mpHead = nullptr;
//	initDeck(mpHead);
//	
//}
Deck::Deck(bool emptyDeck)
{
	mpHead = nullptr;
	if(!emptyDeck) initDeck(mpHead);
}
Deck::~Deck()
{
	CardNode *current = nullptr;
	current = mpHead;
	while (current != 0)
	{
		CardNode *next = current->getNextNode();
		delete current->getCardNode();
		delete current;
		current = next;
		cout << "Node Cleared" << endl;
	}
	mpHead = 0;
	cout << "destructor called";
}
//getters
CardNode *Deck::getHeadPtr()
{
	return this->mpHead;
}

//setters

void Deck::setHeadPointer(CardNode * nHead)
{
	mpHead = nHead;
}
//other functions

void Deck::addCard(Card *c)
{
	addCard(c, mpHead);
}
void Deck::addCard(int faceValue, int suitValue)
{
	addCard(faceValue, suitValue, mpHead);
}
void Deck::Shuffle()
{
	Shuffle(mpHead);
}
CardNode *Deck::getPointerAtN(int n)
{
	CardNode *node = getPointerAtN(mpHead, n);
	return node;
}
int Deck::getDeckLength()
{
	int count = getDeckLength(mpHead);
	return count;
}
Card *Deck::DealCard()
{
	Card *c = DealCard(&mpHead);
	return c;
}
Card *Deck::deleteAtFront() 
{
	Card *c = deleteAtFront(&mpHead);
	return c;
}

//bool Deck::isEmpty()
//{
//	return mpHead == nullptr;
//}

//private functions

int Deck::getDeckLength(CardNode *pNode)
{
	int count = 0;
	while (pNode != nullptr) 
	{
		count++;
		pNode = pNode->getNextNode();
	}
	return count;
}
void Deck::addCard(Card *c, CardNode *pNode)
{
	if (pNode == nullptr)
	{
		this->mpHead = new CardNode(c);
		
	}
	else
	{
		if (pNode->getNextNode() == nullptr)
		{
			pNode->setNextNode(new CardNode(c));
		}
		else
		{
			addCard(c, pNode->getNextNode());
		}
	}
}
void Deck::addCard(int faceValue, int suitValue, CardNode *pNode)
{
	if (pNode == nullptr)
	{
		this->mpHead = new CardNode(faceValue,suitValue);

	}
	else
	{
		if (pNode->getNextNode() == nullptr)
		{
			pNode->setNextNode(new CardNode(faceValue,suitValue));
		}
		else
		{
			addCard(faceValue,suitValue, pNode->getNextNode());
		}
	}
}
void Deck::initDeck(CardNode *mpHead)
{
	for (int i = 0; i < DECK_SIZE; i++)
	{
		addCard(i % 13 + 1, i % 4 + 1, this->mpHead);
	}
	Shuffle();
}
void Deck::Shuffle(CardNode *mpHead)
{
	CardNode *node1 = nullptr;
	CardNode *node2 = nullptr;
	Card *temp = nullptr;

	for (int i = 0; i < 1000; i++)
	{
		//get random nodes
		node1 = getPointerAtN(rand() % getDeckLength() + 1);
		node2 = getPointerAtN(rand() % getDeckLength() + 1);
		//set temp
		temp = node2->getCardNode();
		node2->setCardNode(node1->getCardNode());
		node1->setCardNode(temp);

	}
}
CardNode *Deck::getPointerAtN(CardNode *mpHead, int n)
{
	
	if (mpHead != nullptr)
	{
		for (int i = 1; i < n; i++)
		{
			mpHead = mpHead->getNextNode();
			if (mpHead == nullptr) return nullptr;
		}
	}
	return mpHead;
}
Card *Deck::DealCard(CardNode **mpHead)
{
	Card *c;
	if (mpHead != nullptr)
	{
		/*c = *((*mpHead)->getCardNode());
		delete (*mpHead)->getCardNode();
		temp = *mpHead;
		(*mpHead) = (*mpHead)->getNextNode();
		delete temp;*/
		c = deleteAtFront(mpHead);
		return c;
	}

	return c;
}
//precondition: must not be empty
Card *Deck::deleteAtFront(CardNode **mpHead)
{

	CardNode *temp = nullptr;
	Card *c = (*mpHead)->getCardNode();
	//delete (*mpHead)->getCardNode();
	temp = *mpHead;
	(*mpHead) = (*mpHead)->getNextNode();
	delete temp;
	return c;
}
void destroyDeck(CardNode *mpHead)
{
	while (mpHead != nullptr)
	{

	}
}

bool Deck::isEmpty()
{
	return mpHead == nullptr;
}
//nonMember functions


//operators
std::ostream & operator<< (std::ostream &lhs, Deck &rhs)
{
	CardNode *pCur = nullptr;
	pCur = rhs.getHeadPtr();
	for (int i = 0; i < rhs.getDeckLength(); i++)
	{
		printCard(lhs, *pCur->getCardNode());
		pCur = pCur->getNextNode();
	}
	return lhs;
}
Deck & operator<< (Deck &lhs, Deck &rhs)
{
	if (!lhs.isEmpty()) lhs.addCard(rhs.DealCard());
	return lhs;
}
Deck & operator<< (Deck &lhs, Card *rhs)
{
	if (rhs != nullptr)
	{
		if (!lhs.isEmpty()) lhs.addCard(rhs);
		else
		{
			lhs.setHeadPointer(new CardNode(rhs));
		}
	}
	return lhs;
}