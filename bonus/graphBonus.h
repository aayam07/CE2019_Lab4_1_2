#ifndef GRAPHBONUS_H
#define GRAPHBONUS_H


#include "Graph.h"



class GraphBonus
{
public:
GraphBonus();
void addEdge(int edgeNo);
void addVertex(int verNo);
bool isDirected();
void displayVertex();
void displayEdge();



private:
Graph gl;
};


#endif