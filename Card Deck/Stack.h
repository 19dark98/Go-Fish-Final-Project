#pragma once
#include "Node.h"
#include <iostream>

using std::cout;
using std::endl;
template <class T>
class Stack
{
public:
	Stack();
	~Stack();

	void push(Node<T> * nData);
	T pop(); //needs testing
	Node<T> * peek() { return mpHead; }; //tested
	bool isEmpty() { return (mpHead == nullptr); }; //tested 
	int getSize() { return size; }; //tested

private:
	Node<T> * mpHead;
	int size;
	void clearStack(Node<T> *curNode);
	
};



template <class T>
Stack<T>::Stack()
{
	mpHead = nullptr;
	size = 0;
}

template <class T>
Stack<T>::~Stack()
{
	cout << "\nStackDestructor called\n";
	if (!this->isEmpty()) clearStack(mpHead);
}

template <class T>
void Stack<T>::push(Node<T> * nData)
{
	if (isEmpty()) mpHead = nData;
	else
	{
		nData->setNextPtr(mpHead);
		mpHead = nData;
	}
	size++;
}

//precondition: must not be empty. use isEmpty() before calling
template <class T>
T Stack<T>::pop()
{
	T temp = mpHead->getData();
	Node<T> *tempNode = mpHead;
	mpHead = mpHead->getNextPtr();
	delete tempNode;
	size--;
	return temp;
}

template <class T>
void Stack<T>::clearStack(Node<T> *curNode)
{
	if (mpHead != nullptr)
	{
		if (curNode->getNextPtr() != nullptr) clearStack(curNode->getNextPtr());
		else {
			mpHead = nullptr;
			size = 0;
		}
		delete curNode;
	}
	
}