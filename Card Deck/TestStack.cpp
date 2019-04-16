#include "TestStack.h"
#include <iostream>


TestStack::TestStack()
{
}


TestStack::~TestStack()
{
}

void TestStack::testPush()
{
	//test push function with empty list
	Stack<int> s1;

	s1.push(new Node<int>(5));
	std::cout << "peek returns: " << s1.peek()->getData()<< std::endl;
	if (!s1.isEmpty()) std::cout << "successful push\n";
	else std::cout << "failed to push\n";

	s1.push(new Node<int>(3));
	std::cout << "peek returns: " << s1.peek()->getData() << std::endl;
	if (s1.getSize() == 2) std::cout << "successful push\n";
	else std::cout << "failed to push\n";
}

void TestStack::testDestructor()
{
	Stack<int> s1;
	s1.push(new Node<int>(1));
	s1.push(new Node<int>(1));
	cout << "\nNumber of nodes before destructor : " << s1.getSize()<<endl;
	s1.~Stack();
	cout << "\nNumber of nodes after destructor : " << s1.getSize() << endl;

}