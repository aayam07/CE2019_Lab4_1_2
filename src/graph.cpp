#include "graph.h"

graph::graph(bool directed)
{
    this->directed = directed;
    this->HEAD = nullptr;
}

graph::~graph()
{
    delete this->HEAD;
}

bool graph::isEmpty()
{
    if (this->HEAD == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool graph::isdirected()
{
    if (this->directed == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void graph::addVertex(int vertex)
{
    Vertex *newVertex = new Vertex(vertex);
    if (isEmpty())
    {
        this->HEAD = newVertex;
    }
    else
    {
        newVertex->nextVertex = this->HEAD;
        this->HEAD = newVertex;
    }
}

bool graph::vertex_exists(int vertex)
{
    Vertex *tempVertex = this->HEAD;
    while (tempVertex != nullptr && tempVertex->value != vertex)
    {
        tempVertex = tempVertex->nextVertex;
    }
    if (tempVertex != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void graph::addEdge(int vertex1, int vertex2)
{
    if (vertex_exists(vertex1) && vertex_exists(vertex2))
    {
        Vertex *tempVertex1 = this->HEAD;
        while (tempVertex1 != nullptr && tempVertex1->value != vertex1)
        {
            tempVertex1 = tempVertex1->nextVertex;
        }
        if (tempVertex1 != nullptr)
        {

            Vertex *tempVertex2 = new Vertex(vertex2, nullptr, tempVertex1->nextNeighbour);
            tempVertex1->nextNeighbour = tempVertex2;

            if (!this->isdirected() && !neighbour(vertex2, vertex1))
            {
                addEdge(vertex2, vertex1);
            }
        }
    }
    else
    {
        cout << "Either one or both of the vertices dont exist.So, edge can't be added." << endl;
    }
}

bool graph::neighbour(int vertex1, int vertex2)
{
    Vertex *newVertex = this->HEAD;

    while (newVertex != nullptr && newVertex->value != vertex1)
    {

        newVertex = newVertex->nextVertex;
    }
    while (newVertex != nullptr && newVertex->value != vertex2)
    {
        newVertex = newVertex->nextNeighbour;
    }
    if (newVertex != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int graph::numVertices()
{
    int count = 0;
    Vertex *tempVertex = HEAD;
    while (tempVertex != nullptr)
    {
        tempVertex = tempVertex->nextVertex;
        count += 1;
    }
    return count;
}

// void graph::removeVertex(int vertexToRemove)
// {
//     Vertex *prevVertex = nullptr;
//     Vertex *tempVertex = HEAD;
//     while(tempVertex != nullptr && tempVertex->value != vertexToRemove)
//     {
//         prevVertex = tempVertex;
//         tempVertex = tempVertex->nextVertex;
//     }
//     if(tempVertex == nullptr)
//     {
//         cout << "The vertex to be removed doesn't exist in the graph" << endl;

//     }
//     else
//     {
//         prevVertex = tempVertex->nextVertex;
//         delete tempVertex;
//         cout << "Deleted " << vertexToRemove << endl;

//     }
// }

void graph::displayVertex(char separator)
{
    Vertex *newVertex = this->HEAD;
    while (newVertex != nullptr)
    {

        cout << newVertex->value << separator;
        newVertex = newVertex->nextVertex;
    }
    cout << endl;
}

int graph::indegree(int vertex)
{
    int count = 0;
    if (vertex_exists(vertex))
    {
        Vertex *traVertex = this->HEAD;
        while (traVertex != nullptr)
        {
            if (traVertex->value == vertex)
            {
                traVertex = traVertex->nextVertex;
                continue;
            }
            Vertex *tempVertex = traVertex;
            while (tempVertex->nextNeighbour != nullptr)
            {
                tempVertex = tempVertex->nextNeighbour;
                if (tempVertex->value == vertex)
                {
                    count += 1;
                }
            }
            traVertex = traVertex->nextVertex;
        }
    }
    else
    {
        cout << vertex << " doesn't exist in the graph" << endl;
    }
    return count;
}
