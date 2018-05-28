// $nombredeproyecto$.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"
#include "C:\Users\Mario Flores JR\Documents\TrabajosEstructuraDatos1\TrabajosEstructuraDatos1\MetodosAeropuertos\MetodosAeropuertos\Header.h"
#include "C:\Users\Mario Flores JR\Documents\TrabajosEstructuraDatos1\TrabajosEstructuraDatos1\MetodosAeropuertos\MetodosAeropuertos\Body.cpp"

extern "C" __declspec(dllexport) void __stdcall Creat_Airport(char *name, double lat, double lon) {
	ProyectMethods pm;
	pm.Create_Airport(name, lat, lon);
}

extern "C" __declspec(dllexport) void __stdcall Read_Airport(char *buff, int pos) {
	ProyectMethods pm;
	pm.Read_Airport(buff, pos);
}


extern "C" __declspec(dllexport) int __stdcall Lenght_File() {
	ProyectMethods pm;
	return pm.Lenght_Arch();
}

extern "C" __declspec(dllexport) void __stdcall Delete_Airport(char * name) {
	ProyectMethods pm;
	pm.Delete_Airport(name);
}