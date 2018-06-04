#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
	
	ArchivoAeropuertos.close();
	
}

int ProyectMethods::Lenght_Arch() {
	ifstream ArchivoAeropuertos("C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt", ios::in);
	if (!ArchivoAeropuertos) { return NULL; }
	int i = 0;
	string line;
	while (getline(ArchivoAeropuertos,line)) {
		i++;
	}
	ArchivoAeropuertos.close();
	return i;
}

void ProyectMethods::Delete_Airport(const char *nom) {
	ifstream fileA("C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt", ios::in);
	ofstream fileB("C:\\Users\\Mario Flores JR\\Desktop\\AeropuertosTMP.txt");

	string buffer;
	string name;
	size_t n;

	if (!fileA) { return; }

	while (getline(fileA,buffer))
	{
		n = buffer.find(";");
		name = buffer.substr(0, n);

		if (name!=nom)
		{
			fileB << buffer << "\n";
		}

	}
	fileA.close(); fileB.close();

	remove("C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt");
	rename("C:\\Users\\Mario Flores JR\\Desktop\\AeropuertosTMP.txt", "C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt");


}

void ProyectMethods::Update_Airport(const char *name, const char *Newname, double lat, double lon) {
	ifstream fileA("C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt", ios::in);
	ofstream fileB("C:\\Users\\Mario Flores JR\\Desktop\\AeropuertosTMP.txt");

	string buffer;
	string nameA;
	size_t n;

	if (!fileA) { return; }

	while (getline(fileA, buffer))
	{
		n = buffer.find(";");
		nameA = buffer.substr(0, n);

		if (nameA != name)
		{
			fileB << buffer << "\n";
		}
		else {
			fileB << Newname << ";" << lat << ";" << lon << "\n";
		}

	}
	fileA.close(); fileB.close();

	remove("C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt");
	rename("C:\\Users\\Mario Flores JR\\Desktop\\AeropuertosTMP.txt", "C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt");
}

bool ProyectMethods::Exist_Airport(const char * name) {
	ifstream fileA("C:\\Users\\Mario Flores JR\\Desktop\\Aeropuertos.txt", ios::in);
	if (!fileA) { return false ; }

	string line, tmp;

	while (fileA >> line) {
		stringstream st(line);
		
		getline(st, tmp, ';');

		if (tmp == name) { return true; }
	}
	return false;
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