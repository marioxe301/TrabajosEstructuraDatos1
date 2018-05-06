#pragma once
#ifndef ARBOL_H
#define ARBOL_H

struct Mango {
	int peso;
	Mango *sig;
	Mango *ant;
	
	Mango() { sig = 0; ant = 0; }
};


class Arbol {
public:
	Arbol();
	Mango *Primero;
	Mango *Ultimo;

	bool Vacio(); //H
	int Agregar(int); // H
	int Insertar(int, int);
	int Tamaño();//H
	void Imprimir();//H
	int Eliminar(int);//H
};
#endif // !ARBOL_H
