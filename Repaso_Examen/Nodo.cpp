#include "Nodo.h"

Nodo::Nodo() :sig(0),ant(0)
{}

Nodo::Nodo(int numero): sig(0), ant(0)
{
	setNum(num);
}

int Nodo::getNumero() {
	return this->num;
}

Nodo * Nodo::getSig() {
	return this->sig;
}

Nodo * Nodo::getAnt() {
	return this->ant;
}

void Nodo::setSig(Nodo *sig) {
	this->sig = sig;
}

void Nodo::setAnt(Nodo * ant) {
	this->ant = ant;
}

void Nodo::setNum(int num) {
	this->num = num;
}