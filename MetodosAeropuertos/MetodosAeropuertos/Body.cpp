#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;

ProyectMethods::ProyectMethods(char *name, double lat, double lon){
	this->name = name;
	this->lat = lat;
	this->lon = lon;
}

int ProyectMethods::Create_Airport() {
	ofstream archivoAeropuerto("aeropuertos.txt", ios::app);
	
	if (!archivoAeropuerto) {
		return 1;
	}
	
	char nombre[20];
	double lat, lon;

	strcpy(nombre, this->name);
	lat = this->lat;
	lon = this->lon;

	archivoAeropuerto << nombre << ";" << lat << ";" << lon<<"\n";
	archivoAeropuerto.close();
	return 0;
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