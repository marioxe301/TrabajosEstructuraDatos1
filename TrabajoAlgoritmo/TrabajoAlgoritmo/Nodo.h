#pragma once
#ifndef NODO_H
#define NODO_H

struct Nodo
{
	int numero;
	Nodo *sig;
	Nodo *ant;
	Nodo() { sig = 0; ant = 0; }
};

class Stack {
public:
	Stack();
	Nodo *Primero;
	Nodo *Ultimo;


	void push(int);
	void pop();
	void imprimir();
	void imprimirR(Nodo *);
	bool Vacio();
};
#endif // !NODO_H
