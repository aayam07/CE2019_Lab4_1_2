#pragma once
#include <iostream>
using namespace std;

class Vertex{
    public:
    int value;
    Vertex *nextVertex;
    Vertex *nextNeighbour;

    public:
    Vertex(int value, Vertex *nextVertex = nullptr, Vertex *nextNeighbour = nullptr)
    {
        this->value = value;
        this->nextVertex = nextVertex;
        this->nextNeighbour = nextNeighbour;
    }
    ~Vertex()
    {
        delete nextVertex; 
        delete nextNeighbour;
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
    int indegree(int vertex);
    int outdegree(int vertex);
    int degree(int vertex);
    int neighbours(int vertex);
    bool neighbour(int vertex1, int vertex2);
    bool vertex_exists(int vertex);
    void displayVertex(char separator=' ');

};


