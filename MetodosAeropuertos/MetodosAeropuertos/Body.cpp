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
	Delete_allIDroutes(nom);

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

	Update_IDroute(name, Newname);

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

int ProyectMethods::Create_Route(const char *id, const char *dest, double dist) {
	ofstream ArchivoRutas("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt", ios::app);

	if (!ArchivoRutas) { return 0; }

	if (Exist_Airport(id)) {
		ArchivoRutas << id << ";" << dest << ";" << dist << "\n";
		ArchivoRutas.close();

		return 1;
	}
	else
	{
		return 0;
	}
}

void ProyectMethods::Read_Route( char *id, int pos) {
	ifstream ArchivoRutas("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt", ios::in);
	if (!ArchivoRutas) { return; }

	string buffer;
	int i = 0;


	while (getline(ArchivoRutas, buffer))
	{
		i++;
		if (i == pos) { break; }
	}


	strcpy_s(id, sizeof buffer, buffer.c_str());

	ArchivoRutas.close();

}

void ProyectMethods::Update_Route(const char *id,const char *Rou, const char *newR, double dis) {
	ifstream fileA("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt", ios::in);
	ofstream fileB("C:\\Users\\Mario Flores JR\\Desktop\\RutasTMP.txt");


	string buffer;
	string nameA;
	string nameB;
	size_t n=0;

	size_t f;

	char delimit = ';';

	if (!fileA) { return; }

	while (fileA>>buffer)
	{
		f = buffer.find(delimit);
		nameA = buffer.substr(0, f);

		int i = 0;
		stringstream ss(buffer);
		
		while (getline(ss,nameB,delimit)) {
			if (i <2) { break; }
			i++;
		}
		

		if (nameA != id && nameB !=Rou)
		{
			fileB << buffer << "\n";
		}
		else {
			fileB << id << ";" << newR << ";" << dis << "\n";
		}

	}
	fileA.close(); fileB.close();

	remove("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt");
	rename("C:\\Users\\Mario Flores JR\\Desktop\\RutasTMP.txt", "C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt");
}

void ProyectMethods::Delete_Route(const char *id, const char *route) {
	ifstream fileA("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt", ios::in);
	ofstream fileB("C:\\Users\\Mario Flores JR\\Desktop\\RutasTMP.txt");

	string buffer;
	string nameA;
	string nameB;

	size_t n=0;
	size_t f;

	string delimit = ";";
	if (!fileA) { return; }

	while (getline(fileA, buffer))
	{
		f = buffer.find(delimit);
		nameA = buffer.substr(n, f);

		n = f + delimit.length();
		f = buffer.find(delimit, n);

		nameB = buffer.substr(n, f);


		if (nameA != id && nameB!=route)
		{
			fileB << buffer << "\n";
		}
		
		

	}
	fileA.close(); fileB.close();

	remove("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt");
	rename("C:\\Users\\Mario Flores JR\\Desktop\\RutasTMP.txt", "C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt");
}

int ProyectMethods::Lenght_R() {
	ifstream ArchivoR("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt", ios::in);
	if (!ArchivoR) { return NULL; }
	int i = 0;
	string line;
	while (getline(ArchivoR, line)) {
		i++;
	}
	ArchivoR.close();
	return i;
}

void ProyectMethods::Update_IDroute(const char *id,const char*nid) {
	ifstream ArchivoR("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt", ios::in);
	ofstream fileB("C:\\Users\\Mario Flores JR\\Desktop\\RutasTMP.txt");

	if (!ArchivoR) { return; }

	string ID;
	string line;
	size_t a;
	string subline;
	if (Exist_Airport(id)) {
		while (getline(ArchivoR, line)) {

			a = line.find(";");
			ID = line.substr(0, a);

			subline = line.substr(a, line.length());

			if (id != ID) {
				fileB << line << "\n";
			}
			else {
				fileB << nid + subline << "\n";
			}


		}

	}
	else
	{
		fileB.close(); ArchivoR.close();
		remove("C:\\Users\\Mario Flores JR\\Desktop\\RutasTMP.txt");
		return;
	}

	fileB.close(); ArchivoR.close();

	remove("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt");
	rename("C:\\Users\\Mario Flores JR\\Desktop\\RutasTMP.txt", "C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt");


}

void ProyectMethods::Delete_allIDroutes(const char *id) {
	ifstream ArchivoR("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt", ios::in);
	ofstream fileB("C:\\Users\\Mario Flores JR\\Desktop\\RutasTMP.txt");

	if (!ArchivoR) { return; }

	string ID;
	string line;
	size_t a;
	while (getline(ArchivoR, line)) {

		a = line.find(";");
		ID = line.substr(0, a);

		

		if (id != ID) {
			fileB << line << "\n";
		}
		
		

	}
	fileB.close(); ArchivoR.close();

	remove("C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt");
	rename("C:\\Users\\Mario Flores JR\\Desktop\\RutasTMP.txt", "C:\\Users\\Mario Flores JR\\Desktop\\Rutas.txt");

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