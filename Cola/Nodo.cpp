#include "Nodo.h"

Node::Node() : number(-1), sig(0)
{}

Node* Node::getNext() {
	return this->sig;
}

void Node::setNext(Node *next) {
	this->sig = next;
}
void Node::setNumber(int num) {
	this->number = num;
}

int Node::getNumber() {
	return this->number;
}

