#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include "Vertex.h"

#pragma once
class Edge
{
private:
	int dist;
public:
	Vertex * origin;
	Vertex * destiny;
	Edge(int);
	~Edge();
};

#endif // !EDGE_H_INCLUDED