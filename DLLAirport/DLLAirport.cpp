// $nombredeproyecto$.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"
#include "C:\Users\Mario Flores JR\Documents\TrabajosEstructuraDatos1\TrabajosEstructuraDatos1\MetodosAeropuertos\MetodosAeropuertos\Header.h"
#include "C:\Users\Mario Flores JR\Documents\TrabajosEstructuraDatos1\TrabajosEstructuraDatos1\MetodosAeropuertos\MetodosAeropuertos\Body.cpp"

extern "C" __declspec(dllexport) void __stdcall Create_Airport(char*nombre, double lat, double lon) {
	ProyectMethods pm;
	pm.Create_Airport(nombre, lat, lon);
}

extern "C" __declspec(dllexport) int __stdcall Lenght_Air() {
	ProyectMethods pm;
	return pm.Lenght_Arch();
}

extern "C" __declspec(dllexport) char* __stdcall Read_Airport(int pos) {
	ProyectMethods pm;
	return pm.Read_Airport(pos);
}