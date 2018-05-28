#pragma once
#include <string>

class ProyectMethods {
public:
	ProyectMethods();
	void Create_Airport(const char *,double,double);
	void Read_Airport(char*,int);
	int Lenght_Arch();
	void Delete_Airport(const char *);
	void Update_Airport(const char*, const char*, double, double);

};