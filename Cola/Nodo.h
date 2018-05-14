#pragma once
#ifndef NODO_H

#define NODO_H

class Node {
public:
	Node();

	Node *getNext();
	int getNumber();
	void setNumber(int);
	void setNext(Node*);

private:
	int number;
	Node *sig;

};

#endif // !NODO_H
