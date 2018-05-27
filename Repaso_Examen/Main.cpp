#include <iostream>
#include <conio.h>
#include "Lista.h"
int main() {
	Lista *LN = new Lista;

	LN->agregar(2);
	LN->agregar(5);
	LN->borrar(5);


	LN->Imprimir();



	_getch();
	return 0;
}