// $nombredeproyecto$.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"
#include "C:\Users\Mario Flores JR\Documents\TrabajosEstructuraDatos1\TrabajosEstructuraDatos1\MetodosAeropuertos\MetodosAeropuertos\Header.h"
#include "C:\Users\Mario Flores JR\Documents\TrabajosEstructuraDatos1\TrabajosEstructuraDatos1\MetodosAeropuertos\MetodosAeropuertos\Body.cpp"

extern "C" __declspec(dllexport) int __stdcall  Create_Airport(char *name, double lat, double lon) {
	ProyectMethods pm(name, lat, lon);
	return pm.Create_Airport();
}

