#pragma once

#define MAX_NODES 10

class Vertex{
    public:
    int data;
    Vertex *nextNeighbour;
    Vertex *nextVertex;

    Vertex() {
        nextNeighbour=nullptr;
        nextVertex=nullptr;

    }
    ~Vertex(){
        delete nextNeighbour;
        delete nextVertex;
    }
    Vertex(int info, Vertex *nextVer=nullptr, Vertex *nextNbr=nullptr){
    data=info;
        nextNeighbour=nextNbr;
        nextVertex=nextVer;
            }
};

class Graph{

public:
Graph(bool isdirected=false);
~Graph();
bool isEmpty();
bool isDirected();
void addVertex(int ver);
bool isVertexPresent(int ver);
void addEdge(int ver1, int ver2);
void removeVertex(int ver);
void removeEdge(int ver1, int ver2);
void numEdges();
void inDegree(int ver);
void outDegree(int ver);
void degree(int ver);
void neighbours(int ver);
bool neighbour(int ver1, int ver2);
void displayVertex();
private:
Vertex *GRAPH_HEAD;
bool directed;

};