#include "Lista.h"
#include <iostream>

Lista::Lista(): Inicio(0),Final(0)
{
	Nodo *centinela = new Nodo;
	centinela->setNum(-1);
	Inicio = Final = centinela;
	centinela->setSig(centinela);
	centinela->setAnt(centinela);

}

void Lista::agregar(int numero) {
	Nodo *nuevo = new Nodo;
	nuevo->setNum(numero);

	if (Vacio()) {
		Inicio->setSig(nuevo);
		Inicio->setAnt(nuevo);
		nuevo->setSig(Inicio);
		Final = nuevo;
	}
	else {
		Nodo *tmp = Inicio->getSig();
		while (tmp!=Inicio)
		{
			if (tmp->getNumero() <= numero) {
				if (tmp == Final) {
					tmp->setSig(nuevo);
					nuevo->setAnt(tmp);
					nuevo->setSig(Inicio);
					Final = nuevo;
				}
				else {
					tmp->setSig(nuevo);
					nuevo->setAnt(tmp);
				}
			}
			else if (tmp->getNumero() >= numero) {
				if (tmp == tmp) {
					tmp->setAnt(nuevo);
					nuevo->setSig(tmp);
					nuevo->setAnt(Inicio);
					
				}
				else {
					tmp->setAnt(nuevo);
					nuevo->setSig(tmp);
				}
			}

			tmp = tmp->getSig();
		}
	}
}

bool Lista::Vacio() {
	if (Final->getNumero() == -1) {
		return true;
	}
	else {
		return false;
	}

}

void Lista::borrar(int numero) {
	Nodo *tmp = Inicio->getSig();
	
	while (tmp != Inicio) {
		if (tmp == tmp && tmp->getNumero() == numero) {
			Inicio->setSig(tmp->getSig());
			tmp->getSig()->setAnt(Inicio);
			delete tmp;
			return;
		}
		else if (tmp == Final && tmp->getNumero() == numero) {
			tmp->getAnt()->setSig(Inicio);
			Inicio->setAnt(tmp->getAnt());
			Final = tmp->getAnt();
			delete tmp;
			return;
		}
		else {
			tmp->getAnt()->setSig(tmp->getSig());
			tmp->getSig()->setAnt(tmp->getAnt());
			delete tmp;
			return;
		}
	}
}

void Lista::Imprimir() {
	Nodo *tmp = Inicio->getSig();
	if (Vacio()) {
		std::cout << "La lista esta vacia"<<std::endl;
	}
	else
	{
		while (tmp!=Inicio)
		{
			std::cout << tmp->getNumero() << "\t";
			tmp = tmp->getSig();
		}
	}
}
