#include <iostream>
#include "Cola.h"

int main() {
	Cola *CL = new Cola();
	CL->Push(2);
	CL->Push(5);
	CL->Push(7);
	CL->Push(8);

	CL->Print();

	CL->Pull();

	CL->Print();

	system("pause");
	return 0;
}