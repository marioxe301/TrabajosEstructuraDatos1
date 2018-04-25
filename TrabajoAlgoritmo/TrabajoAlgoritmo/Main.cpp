#include <iostream>
#include "Nodo.h"
using namespace std;

int main() {
	Stack pila;

	pila.push(1);
	pila.push(5);
	pila.push(7);
	pila.push(8);

	pila.imprimir();


	pila.pop();
	pila.imprimir();


	pila.pop();
	pila.imprimirR(pila.Primero);

	system("pause");
}