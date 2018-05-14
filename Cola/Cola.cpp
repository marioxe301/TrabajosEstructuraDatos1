#include "Cola.h"
#define NULLPTR 0

Cola::Cola(): Top(NULLPTR),End(NULLPTR)
{}

int Cola::Push(int number) {
	if (isEmpty()) {
		Node *newN = new Node;
		newN->setNumber(number);
		Top = End = newN;
	}
	else {
		if (Lenght() == 1) {
			Node *newN = new Node;
			newN->setNumber(number);
			End->setNext(newN);
			Top = newN;
		}
		else
		{
			Node *newN = new Node;
			newN->setNumber(number);
			Top->setNext(newN);
			Top = newN;
		}
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
