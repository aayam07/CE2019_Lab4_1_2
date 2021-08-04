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

// void graph::addEdge(int vertex1, int vertex2)
// {
//     if (vertex_exists(vertex1) && vertex_exists(vertex2))
//     {
//         Vertex *tempVertex1 = this->HEAD;
//         while (tempVertex1 != nullptr && tempVertex1->value != vertex1)
//         {
//             tempVertex1 = tempVertex1->nextVertex;
//         }
//         if (tempVertex1 != nullptr)
//         {

//             Vertex *tempVertex2 = new Vertex(vertex2);
//             tempVertex1->nextNeighbour = tempVertex2;

//             if (!this->isdirected() && !neighbour(vertex2, vertex1))
//             {
//                 addEdge(vertex2, vertex1);
//             }
//         }
//     }
//     else
//     {
//         cout << "Either one or both the vertices dont exist, hence edge cant be formed." << endl;
//     }
// }

// bool graph::neighbour(int ver1, int ver2)
// {
//     Vertex *newVertex = HEAD;

//     while (newVertex != nullptr && newVertex->value != ver1)
//     {

//         newVertex = newVertex->nextVertex;
//     }
//     while (newVertex != nullptr && newVertex->value != ver2)
//     {
//         newVertex = newVertex->nextNeighbour;
//     }
//     if (newVertex != nullptr)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

int graph::numVertices()
{
    int count = 0;
    Vertex *tempVertex = HEAD;
    while(tempVertex != nullptr)
    {
        tempVertex = tempVertex->nextVertex;
        count += 1;
    }
    return count;

}

void graph::removeVertex(int vertexToRemove)
{
    Vertex *tempVertex = HEAD;
    while(tempVertex != nullptr && tempVertex->value != vertexToRemove)
    {
        tempVertex = tempVertex->nextVertex;
    }
    if(tempVertex == nullptr)
    {
        cout << "The vertex to be removed doesn't exist in the graph" << endl;
        
    }
    else
    {
        vertexToRemove = tempVertex->value;
        delete tempVertex;
        cout << "Removed " << vertexToRemove << " from the graph." << endl;
    }

}
