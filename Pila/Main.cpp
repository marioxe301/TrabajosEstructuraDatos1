#include <iostream>
#include <conio.h>
#include "Stack.h"
int main() {
	Stack *mainS = new Stack;
	mainS->Push(2);
	mainS->Push(3);
	mainS->Push(1);

	mainS->Print();

 	Stack *result = ++mainS;

	result->Print();
	_getch();

	return 0;
}