#include <iostream>
#include "Arbol.h"

using namespace std;

int main() {
	Arbol *raiz = new Arbol;
	raiz->Agregar(90);
	raiz->Agregar(50);
	raiz->Agregar(34);

	raiz->Imprimir();

	raiz->Eliminar(1);

	raiz->Imprimir();

	system("pause");
	return 0;
}