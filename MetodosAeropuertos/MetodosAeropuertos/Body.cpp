#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ProyectMethods::ProyectMethods() {}

void ProyectMethods::Create_Airport(const char*name, double lat, double lon) {
	ofstream ArchivoAeropuertos("C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt",ios::app);

	if (!ArchivoAeropuertos) { return; }
	
	ArchivoAeropuertos << name << ";" << lat << ";" << lon << "\n";
	ArchivoAeropuertos.close();
}

 void ProyectMethods::Read_Airport(char *buff,int posc) {
	ifstream ArchivoAeropuertos("C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt", ios::in);
	if (!ArchivoAeropuertos) { return ; }

	string buffer;
	int i = 0;
	

	while (getline(ArchivoAeropuertos,buffer))
	{
		i++;
		if (i == posc) { break; }
	}
	

	strcpy_s(buff, sizeof buffer, buffer.c_str());
	
	
	
}

int ProyectMethods::Lenght_Arch() {
	ifstream ArchivoAeropuertos("C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt", ios::in);
	if (!ArchivoAeropuertos) { return NULL; }
	int i = 0;
	string line;
	while (getline(ArchivoAeropuertos,line)) {
		i++;
	}
	return i;
}

//int  ProyectMethods::Display_Airports() {
//
//}
//
//int  ProyectMethods::Update_Airport() {
//
//}
//
//int  ProyectMethods::Delete_Airport() {
//
//}