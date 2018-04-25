#include "Nodo.h"
#include <iostream>
Stack::Stack() :Primero(0),Ultimo(0)
{}

bool Stack::Vacio() {
	if (Primero == 0) {
		return true;
	}
	else
	{
		return false;
	}
}
void Stack::push(int numero) {
	if (Vacio()) {
		Nodo *nuevo = new Nodo;
		nuevo->numero = numero;
		Primero = Ultimo = nuevo;
	}
	else {
		Nodo *nuevo = new Nodo;
		Nodo *tmp = Primero;
		nuevo->numero = numero;
		nuevo->ant = tmp;
		tmp->sig = nuevo;
		Primero = nuevo;
	}
}
void Stack::pop() {
	if (Vacio()) {
		std::cout << "El stack esta vacio"<<std::endl;
	}
	else {
		Nodo *tmp = Primero;
		Nodo *nuevo = Primero->ant;

		delete tmp;

		Primero = nuevo;
	}
}

void Stack::imprimir() {
	Nodo *tmp = Primero;
	while (tmp != 0) {

		std::cout << tmp->numero << "\t";
		tmp = tmp->ant;

	}
	std::cout << std::endl;
	
}

void Stack::imprimirR(Nodo *nodo) {
	if (nodo == 0) {
		return;
	}
	else {
		std::cout << nodo->numero << "\t";
		imprimirR(nodo = nodo->ant);
	}

	std::cout << std::endl;
}