#pragma once
#include "Nodo.h"
class Lista {
public:
	Lista();

	void agregar(int);
	void borrar(int);
	int Moda();
	int Diferencia();
	bool Vacio();
	void Imprimir();

	Nodo * Inicio;
	Nodo * Final;
	
};