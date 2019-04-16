#pragma once
template <class T>
class Node
{
public:
	Node();
	Node(T nData);
	~Node();

	T getData() { return Data; };
	Node<T> * getNextPtr() { return mpNext; };
	
	void setNextPtr(Node<T> * nNext) { mpNext = nNext; };

private:
	T Data;
	Node<T> * mpNext;
	
};


template <class T>
Node<T>::Node()
{
	mpNext = nullptr;
}
template<class T>
Node<T>::Node(T nData)
{
	mpNext = nullptr;
	Data = nData;//needs copy constructor
}

template <class T>
Node<T>::~Node()
{
}
