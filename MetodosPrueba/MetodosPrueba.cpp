// $nombredeproyecto$.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"
#include "C:\Users\Mario Flores JR\source\repos\Project1\Project1\Suma.h"
#include "C:\Users\Mario Flores JR\source\repos\Project1\Project1\CuerpoClase.cpp"

extern "C" __declspec(dllexport) double __stdcall  SumaNormal(double a,double b) {
	SumaNum SM(a, b);

	return SM.SumaTotal();
}



