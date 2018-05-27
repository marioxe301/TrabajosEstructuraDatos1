#pragma once
class Nodo {
public:
	Nodo();
	Nodo(int);
	
	int getNumero();
	Nodo * getSig();
	Nodo * getAnt();

	void setNum(int);
	void setSig(Nodo *);
	void setAnt(Nodo *);

private:
	int num;
	Nodo * sig;
	Nodo * ant;
};