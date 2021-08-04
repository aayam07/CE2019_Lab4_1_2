#pragma once
#include <iostream>
using namespace std;

class Vertex{
    public:
    int value;
    Vertex *nextVertex;
    Vertex *nextNeighbour;

    public:
    Vertex(int value)
    {
        this->value = value;
        nextVertex = nullptr;
        nextNeighbour = nullptr;
    }
    ~Vertex()
    {
        delete nextVertex, nextNeighbour;
    }

};

class graph
{
private:
    Vertex *HEAD;
    bool directed;
public:
    graph(bool isdirected);
    ~graph();
    bool isEmpty();
    bool isdirected();
    void addVertex(int newVertex);
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int vertexToRemove);
    void removeEdge(int vertex1, int vertex2);
    int numVertices();
    int numEdges();
    int indegree();
    int outdegree();
    int degree();
    int neighbours(int vertex);
    bool neighbour(int vertex1, int vertex2);
    bool vertex_exists(int vertex);

};


