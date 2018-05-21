#pragma once
struct Node
{
	int numero;
	Node *sig;
	Node *ant;
	Node() { sig = 0; ant = 0; }
};

class Stack {
	
public:

	friend Stack& operator++(const Stack&);
	friend Stack& operator--(const Stack&);

	Stack();
	Node *First;
	Node *Last;


	int Push(int);
	int Pop();
	void Print();
	bool isEmpty();
	int Lenght();

};
