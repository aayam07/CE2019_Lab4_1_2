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
        cout << "Either one or both of the vertices doesn't exist. So, edge can't be added." << endl;
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

void graph::displayVertex(char separator)
{
    Vertex *tempVertex = this->HEAD;
    while (tempVertex != nullptr)
    {

        cout << tempVertex->value << separator;
        tempVertex = tempVertex->nextVertex;
    }
    cout << endl;
}

// indegree means of a vertex means finding out tyo vertex aaru kun kun vertex ko neighbour ho
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

int graph::outdegree(int vertex)
{
    int count = 0;
    if(vertex_exists(vertex))
    {
        Vertex *traVertex = this->HEAD;
        while(traVertex->value != vertex)
        {
            traVertex = traVertex->nextVertex;
        }
        Vertex *tempVertex = traVertex;
        while(tempVertex->nextNeighbour != nullptr)
        {
            tempVertex = tempVertex->nextNeighbour;
            count++;
        }
    }
    else
    {
        cout << vertex << " doesn't exist in the graph." << endl;
    }
    return count;
}

int graph::degree(int vertex)
{
    int number_of_degrees;
    if(this->isdirected())
    {
        number_of_degrees = indegree(vertex) + outdegree(vertex);
    }
    else
    {
        number_of_degrees = outdegree(vertex);
    }
    return number_of_degrees;
}

Vertex* graph::neighbours(int vertex)
{
    Vertex *traVertex = this->HEAD;  // To traverse through the vertices
    if(vertex_exists(vertex))
    {
        while(traVertex->value != vertex)
        {
            traVertex = traVertex->nextVertex;
        }
        
        // Vertex *tempVertex = traVertex->nextNeighbour; // To traverse through the neighbours of the vertex
        
        // cout << "The neighbours of " << vertex << " are: ";
        // while(tempVertex->nextNeighbour != nullptr)
        // {
        //     tempVertex = tempVertex->nextNeighbour;
        //     // cout << tempVertex->value << " ";
        // }
        // cout << endl;
    }
    else
    {
        cout << vertex << " doesn't exist in the graph." << endl;
        return traVertex;
    }
    return traVertex;
}

int graph::numEdges()
{
    int count;
    if(!this->isEmpty())
    {
        Vertex *tempVertex = this->HEAD;
        while(tempVertex != nullptr)
        {
            count += outdegree(tempVertex->value);
            tempVertex = tempVertex->nextVertex;
        }
        if(!this->isdirected())
        {
            count /= 2;
        }
    }
    else
    {
        cout << "Empty graph doesn't have edges." << endl;
        return 0;
    }
    return count;
}

void graph::removeEdge(int vertex1, int vertex2)
{
    if(neighbour(vertex1,vertex2))
    {
        Vertex *traVertex = this->HEAD;
        while(traVertex->value != vertex1)
        {
            traVertex = traVertex->nextVertex;
        }
        Vertex *tempVertex = traVertex->nextNeighbour;
        while(tempVertex->value != vertex2)
        {
            tempVertex = tempVertex->nextNeighbour;
            traVertex = traVertex->nextNeighbour;
        }
        traVertex->nextNeighbour = tempVertex->nextNeighbour;
        tempVertex = nullptr;
        if(!this->isdirected() && neighbour(vertex2,vertex1))
        {
            removeEdge(vertex2,vertex1);
        }
    }
    else
    {
        cout << "There is no edge between " << vertex1 << " and " << vertex2 << endl;
    }
}

void graph::displayEdges()
{
    if(!this->isEmpty())
    {
        Vertex *traVertex = this->HEAD;
        cout << "Edges of the graph: " << endl;
        while(traVertex != nullptr)
        {
            Vertex *tempVertex = traVertex->nextNeighbour; // this is created inside while loop since for every vertex of the graph, we need to traverse its neighbours. So, during each iteration a new pointer tempVertex is created.
            cout << traVertex->value << " -> ";
            while(tempVertex != nullptr)
            {
                cout << tempVertex->value << " ";
                tempVertex = tempVertex->nextNeighbour;
            }
            cout << endl;
            traVertex = traVertex->nextVertex;
        }
    }
    else
    {
        cout << "Cannot display the edges of an empty graph." << endl;
    }
}

void graph::removeVertex(int vertexToRemove)
{
    Vertex *prev = this->HEAD;
    Vertex *temp = this->HEAD->nextVertex;

    if(vertexToRemove == prev->value)
    {
        removeAllEdges(prev);
        this->HEAD = prev->nextVertex;
        prev = nullptr;
        temp = nullptr;
    }
    else
    {
        if(neighbour(prev->value, vertexToRemove))
        {
            removeEdge(prev->value, vertexToRemove);
        }
    }

    while(temp != nullptr)
    {
        if(temp->value == vertexToRemove)
        {
            removeAllEdges(temp);
            prev->nextVertex = temp->nextVertex;
            temp = temp->nextVertex;
        }
        else if(neighbour(temp->value, vertexToRemove))
        {
            removeEdge(temp->value, vertexToRemove);
            if(prev != nullptr)
            {
                prev = prev->nextVertex;
            }
            temp = temp->nextVertex;
        }
        else
        {
            if(prev != nullptr)
            {
                prev = prev->nextVertex;
            }
            temp = temp->nextVertex;
        }
    }
}

void graph::removeAllEdges(Vertex *vertexEdgeDelete)
{
    Vertex *tempVertex = vertexEdgeDelete->nextNeighbour; // means that vertex to be removed ko first neighbour is assigned
    while(tempVertex != nullptr)
    {
        removeEdge(vertexEdgeDelete->value, tempVertex->value);
        tempVertex = tempVertex->nextNeighbour;
    }
}