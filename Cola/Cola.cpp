#include "Cola.h"
#include <iostream>
#define NULLPTR 0

Cola::Cola(): Top(NULLPTR),End(NULLPTR)
{}

int Cola::Push(int number) {
	if (isEmpty()) {
		Node *newN = new Node;
		newN->setNumber(number);
		Top = End = newN;
		return 0;
	}
	else
		{
			Node *newN = new Node;
			newN->setNumber(number);
			Top->setNext(newN);
			Top = newN;
			return 0;
		}
	}


bool Cola::isEmpty() {
	if (Top == NULLPTR) {
		return true;
	}
	else {
		return false;
	}
}

int Cola::Lenght() {
	Node *tmp = Top;
	int i = 0;
	while (tmp!=0)
	{
		tmp = tmp->getNext();
		i++;
	}
	return i;
}

int Cola::Pull() {
	Node *tmp = End->getNext();
	delete End;
	End = tmp;
	return 0;
}

void Cola::Print() {
	Node *tmp = End;
	while (tmp!=NULLPTR)
	{
		std::cout << tmp->getNumber() << "\t";
		tmp = tmp->getNext();
	}
	std::cout << std::endl;
}