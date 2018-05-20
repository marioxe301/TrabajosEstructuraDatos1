#include "Arbol.h"
#include <iostream>
Arbol::Arbol(): Primero(0), Ultimo(0)
{}

bool Arbol::Vacio() {
	if (Primero == 0) {
		return true;
	}
	else {
		return false;
	}
}

int Arbol::Agregar(int Peso) {
	if (Vacio()) {
		Mango *nuevo = new Mango;
		nuevo->peso = Peso;
		Primero = Ultimo = nuevo;
		return 0;
	}
	else {
		Mango *nuevo = new Mango;
		nuevo->peso = Peso;
		nuevo->ant = Ultimo;
		Ultimo->sig = nuevo;
		Ultimo = nuevo;
		return 0;
	}
	
}

int Arbol::Tamaño() {
	Mango *tmp = Primero;
	int i = 0;
	while (tmp!=0)
	{
		i++;
		tmp = tmp->sig;
	}
	return i;
}

void Arbol::Imprimir() {
	Mango *tmp = Primero;
	while (tmp!=0)
	{
		std::cout <<"Peso: "<< tmp->peso<<"\t";
		tmp = tmp->sig;
	}
	std::cout << "\n";
}

int Arbol::Eliminar(int poscicion) {
	if (poscicion > Tamaño()) {
		return 1;
	}
	else {
		Mango *tmp = Primero;
		int a = 1;
		
		if (poscicion == 1) {
			Mango *sig = tmp->sig;
			delete tmp;
			Primero = sig;

			return 0;

		}else if(poscicion == Tamaño()){
			Mango *ant = Ultimo->ant;
			delete Ultimo;
			Ultimo = ant;

			return 0;
		}
		else {
			while (poscicion != a) { a++; tmp = tmp->sig; }
			Mango *ant = tmp->ant;
			Mango *sig = tmp->sig;
			delete tmp;
			ant->sig = sig;
			sig->ant = ant;

			return 0;
		}
	}
}

int Arbol::Insertar(int poscicion, int peso) {
	if (poscicion > Tamaño()) {
		return 1;
	}
	else {
		Mango *tmp = Primero;
		Mango *tmp2 = Ultimo;
	
		int a = 1;

		if (poscicion == 1) {
			Mango *sig = tmp->sig;
			tmp->sig = sig;
			sig->ant = tmp;

			Primero = tmp;
			

			return 0;

		}
		else if (poscicion == Tamaño()) {
			Mango *ant = Ultimo->ant;
			tmp2->ant = ant;
			ant->sig = tmp2;

			Ultimo = tmp2;

			return 0;
		}
		else {
			while (poscicion != a) { a++; tmp = tmp->sig; }
			Mango *ant = tmp->ant;
			Mango *sig = tmp->sig;
			delete tmp;
			ant->sig = sig;
			sig->ant = ant;

			return 0;
		}
	}
}