

#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo {
	int nro;
	struct nodo *izq, *der;
};

typedef struct nodo *ABB;



void insertar(ABB &arbol, int x)
{
	if (arbol == NULL)
	{
		ABB nuevoNodo = new(struct nodo);
		nuevoNodo->nro = x;
		nuevoNodo->izq = NULL;
		nuevoNodo->der = NULL;
		arbol = nuevoNodo;
	}
	else if (x < arbol->nro)
		insertar(arbol->izq, x);
	else if (x > arbol->nro)
		insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		cout << arbol->nro << " ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		inOrden(arbol->izq);
		cout << arbol->nro << " ";
		inOrden(arbol->der);
	}
}

void postOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout << arbol->nro << " ";
	}
}
int Tamaño(ABB arbol) {
	int i = 0;
	if (arbol == NULL) {
		return 0;
	}
	else {
		return (Tamaño(arbol->izq) + 1 + Tamaño(arbol->der));
	}
		
}

int contarHojas(ABB arbol)
{
	if (arbol == NULL)
	{
		return 0;
	}
	if ((arbol->der == NULL) && (arbol->izq == NULL))
	{
		return 1;
	}
	else
	{
		return contarHojas(arbol->izq) + contarHojas(arbol->der);
	}
}

int Nivel(ABB arbol) {
	int iz, dr;
	if (arbol->izq == NULL&&arbol->der ==NULL) {
		return 1;
	}
	else {
		iz = Nivel(arbol->izq);
		dr = Nivel(arbol->der);

		if (iz < dr) {
			return dr;
		}
		else {
			return iz;
		}
	}
}
int altura(ABB arbol) {
	return Nivel(arbol) + 1;
}

int main()
{
	ABB arbol = NULL;   

	int n;  
	int x; 

	
	cout << " Numero de nodos del arbol a agregar:  ";
	cin >> n;
	cout << endl;

	for (int i = 0; i<n; i++)
	{
		cout << " Numero del nodo " << i + 1 << ": ";
		cin >> x;
		insertar(arbol, x);
	}

	

	cout << "\n Recorridos del ABB";

	cout << "\n\n En orden   :  ";   inOrden(arbol);
	cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
	cout << "\n\n Post Orden :  ";   postOrden(arbol);

	cout << "\n\n Tamaño   :  "<< Tamaño(arbol);
	cout << "\n\n Nivel :  " << Nivel(arbol);
	cout << "\n\n Hojas :  " << contarHojas(arbol);
	cout << "\n\n Altura:  " << altura(arbol);
	cout << endl << endl;

	system("pause");
	return 0;
}