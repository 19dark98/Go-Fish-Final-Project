#include "Hand.h"

Hand::Hand()
{

}
Hand::Hand(Deck &d,int handSize)
{
	
	for (int i = 0; i < handSize; i++) {
		if(!d.isEmpty())addCard(d.DealCard());
	}
	mpHead = getHeadPtr();
	
}
Hand::~Hand()
{
	
}
Card *Hand::discardAtNodeN(int n)
{
	Card *temp = nullptr;
	if (n < 0 || n > HAND_SIZE) return temp;
	Card *c = discardAtNodeN(n, mpHead);
	return c;
}
void Hand::sortHand()
{
	sortHand(this->mpHead);
}

//properties

bool Hand::hasSuit(int suit)
{
	bool ret = false;
	CardNode *pCur = mpHead;
	while (pCur != nullptr && !ret)
	{
		if (pCur->getCardNode()->getSuit() == suit) ret = true;
		pCur = pCur->getNextNode();
	}
	return ret;
}
bool Hand::hasFace(int face)
{
	bool ret = false;
	CardNode *pCur = mpHead;
	while (pCur != nullptr && !ret)
	{
		if (pCur->getCardNode()->getFaceValue() == face) ret = true;
		pCur = pCur->getNextNode();
	}
	return ret;
}
bool Hand::hasCard(int suit, int face)
{
	Card c(suit, face);
	bool ret = false;
	CardNode *pCur = mpHead;
	while (pCur != nullptr && !ret)
	{
		if (*pCur->getCardNode() == c) ret = true;
		pCur = pCur->getNextNode();
	}
	return ret;
}
bool Hand::hasCard(int suit, int face, int &index)
{
	Card c(suit, face);
	bool ret = false;
	CardNode *pCur = mpHead;
	int i = 1;
	while (pCur != nullptr && !ret)
	{
		if (*pCur->getCardNode() == c)
		{
			index = i;
			ret = true;
		}

		pCur = pCur->getNextNode();
		i++;
	}
	return ret;
}
bool Hand::hasCard(Card c)
{
	bool ret = false;
	CardNode *pCur = mpHead;
	while (pCur != nullptr && !ret)
	{
		if (*pCur->getCardNode() == c) ret = true;
		pCur = pCur->getNextNode();
	}
	return ret;
}
bool Hand::hasCard(Card c, int &index)
{
	bool ret = false;
	CardNode *pCur = mpHead;
	int i = 1;
	while (pCur != nullptr && !ret)
	{
		if (*pCur->getCardNode() == c)
		{
			index = i;
			ret = true;
		}

		pCur = pCur->getNextNode();
		i++;
	}
	return ret;
}

//opperators
Card * Hand::operator[](int i)
{
	Card *c = nullptr;
	if (i <= this->getDeckLength() && i > 0) return getPointerAtN(i)->getCardNode();
	return nullptr;
}

//private functions

Card *Hand::discardAtNodeN(int n, CardNode *pHead)
{
	Card *card = nullptr;
	if (pHead == getPointerAtN(n))
	{
		CardNode *temp = nullptr;
		Card *c = (mpHead)->getCardNode();
		
		temp = mpHead;
		mpHead = mpHead->getNextNode();
		delete temp;

		return c;
	}
	else
	{
		if (getPointerAtN(n) != nullptr) 
		{
			
			CardNode *pCurr = getPointerAtN(n), *pPrev = getPointerAtN(n-1);
			card = (pCurr->getCardNode());
			pPrev->setNextNode(pCurr->getNextNode());
			delete pCurr;
			return card;
		}
	}
	return card;
}
void Hand::addCard(Card *c)
{
	if (mpHead == nullptr) mpHead = new CardNode(c);
	else
	{
		insertInOrder(c, mpHead);
	}
}
void Hand::sortHand(CardNode *pHead)
{
	int handSize = HAND_SIZE;
	for (int i = 1; i <= handSize; i++)
	{
		for (int j = 1; j <= handSize - i; j++)
		{
			if (*this->getPointerAtN(j)->getCardNode() > *this->getPointerAtN(j + 1)->getCardNode()) swapCard(j, j+1);
		}
	}
}

void Hand::swapCard(int index1, int index2)
{
	CardNode *node1 = nullptr;
	CardNode *node2 = nullptr;
	Card *temp = nullptr;

	node1 = getPointerAtN(index1);
	node2 = getPointerAtN(index2);
	temp = node2->getCardNode();
	node2->setCardNode(node1->getCardNode());
	node1->setCardNode(temp);
	

}

void Hand::insertInOrder(Card *c, CardNode *pCur)
{
	
	//find where to insert
	if (*c < *pCur->getCardNode() && (mpHead == pCur))
	{
		CardNode *temp = new CardNode(c);
		temp->setNextNode(mpHead);
		mpHead = temp;
	}
	else
	{
		if (pCur->getNextNode() != nullptr)
		{
			if (*c < *pCur->getNextNode()->getCardNode())
			{
				CardNode *temp = new CardNode(c);
				temp->setNextNode(pCur->getNextNode());
				pCur->setNextNode(temp);
			}
			else
			{
				insertInOrder(c, pCur->getNextNode());
			}
		}
		else
		{
			CardNode *temp = new CardNode(c);
			pCur->setNextNode(temp);
		}
		
	}

}

//operators
ostream & operator<< (ostream &lhs, Hand &rhs)
{
	if (rhs.isEmpty())
	{
		lhs << "Hand is empty";
	}
	else 
	{
		for (int i = 1; i <= rhs.getDeckLength(); i++)
		{
			printCard(*rhs.getPointerAtN(i)->getCardNode());
		}
	}
	

	return lhs;
}

