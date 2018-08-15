#pragma once
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"



class ProyectMethods {
private:
	int cantV;
public:
	std::vector<Vertex*> vertexes;

	ProyectMethods();
	void Create_Airport(const char *,double,double);
	void Read_Airport(char*,int);
	int Lenght_Arch();
	void Delete_Airport(const char *);
	void Update_Airport(const char*, const char*, double, double);
	bool Exist_Airport(const char *);

	double getLat(const char*);
	double getLng(const char*);
	int getDist(const char*, const char*);

	void getID(char*, const char*);

	int Create_Route(const char *, const char *);
	void Read_Route(char *, int);
	int Lenght_R();
	void Delete_Route(const char *,const char*);
	void Update_Route(const char*, const char *, const char *);
	void Update_IDroute(const char *, const char *);

	void Delete_allIDroutes(const char *);
	void createRutasID(const char * origen, const char * destino,int dis);
	void readRutasID(char *, int);
	int Lenght_IDrutas();
	void borrarRutasID(const char *);

	void dijkstra(const char*);
	void dijk(Vertex * origen);

	double weight(Vertex *, Vertex *);
	queue<Edge *> sortedEdges(Vertex*);
	void crearVertices();
	void crearAristas();
	void borrarVertice(const char*);
	void borrarArista(const char* , const char*);
	void updateArista(const char* , const char* , const char*);
};