#pragma once
#include "Nodo.h"

class Cola {
public:
	Cola();

	int Push(int);//H
	int Pull();
	bool isEmpty();//H
	int Lenght();//H

	void Print();


private:
	Node *Top;
	Node *End;

};
