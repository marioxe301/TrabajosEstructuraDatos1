#ifndef  VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED
#include <vector>
#include <iostream>
#include "Edge.h"

#pragma once

using namespace std;

class Vertex
{
	
public:

	vector<Edge*> edges;
	const char * id;
	Vertex(const char *);
	vector<Vertex*> getAdj();//obtiene las aristas conectadas a este vertice
	~Vertex();
};

#endif // ! VERTEX_H_INCLUDED