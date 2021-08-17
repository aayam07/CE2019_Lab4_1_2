#include "graph.h"

int main()
{   
    // creating graph object as g
    graph g(0); // 0 means false i.e directed is set to false (assuming this as undirected graph)

    cout << g.isEmpty() << endl; // prints 1 if the graph is empty else prints 0
    cout << g.isdirected() << endl; // prints 1 if the graph is directed else prints 0
    g.addVertex(10);
    g.addVertex(20);
    g.addVertex(30);
    g.addVertex(40);
    g.addVertex(50);
    g.addVertex(60);
    cout << g.vertex_exists(50) << endl; // prints 1 if vertex 50 exists in the graph, 0 otherwise. Prints True(1)
    cout << g.vertex_exists(70) << endl; // prints 1 if vertex 70 exists in the graph, 0 otherwise. Prints False(0)
    cout << g.neighbour(30,40) << endl; // checks if vertex 30 is the neighbour of vertex 40 & vice-versa, False(0)
    g.addEdge(30,40); // adds edge between vertex 30 and 40, success
    cout << g.neighbour(30,40) << endl; // checks if vertex 30 is the neighbour of vertex 40 & vice-versa. Prints True(1)
    cout << g.neighbour(50,10) << endl; // checks if vertex 50 is the neighbour of vertex 10 & vice-versa. Prints False(0)
    g.addEdge(90,10); // adds edge between vertex 30 and 40, unsuccessful since 90 doesn't exist in the graph
    cout << g.numVertices() << endl; // prints the total number of vertices in the graph
    g.displayVertex();
    cout << g.vertex_exists(60) << endl; // prints 1 if vertex 60 exists in the graph, 0 otherwise. Prints True(1)

    g.addEdge(10,30);
    g.addEdge(10,20);
    g.addEdge(20,40);
    g.addEdge(30,50);
    g.addEdge(40,60);
    g.addEdge(50,60);
    cout << g.degree(10) << endl; // prints the degree of a vertex
    cout << g.indegree(10) << endl; // since it is an undirected graph, indegree = outdegree
    cout << g.outdegree(10) << endl; // since it is an undirected graph, indegree = outdegree

    // Implementation to check the neighbours of a particular vertex
    Vertex *vertex_neighbours = g.neighbours(30);
    cout << "The neighbours of " << vertex_neighbours->value << " are: ";
    while(vertex_neighbours->nextNeighbour != nullptr)
    {
        vertex_neighbours = vertex_neighbours->nextNeighbour;
        cout << vertex_neighbours->value << " ";
    }
    cout << endl;

    cout << "The number of edges in the graph are: " << g.numEdges() << endl; // prints 7, since there are 7 edges

    g.displayEdges(); // Prints all the edges of the graph in a linked list representation
    g.removeEdge(20,40); // removes edge between 20 and 40
    g.removeEdge(60,40); // removes edge between 40 and 60
    cout << "The number of edges in the graph are: " << g.numEdges() << endl; // prints 5, since two edges are removed in the above two lines

    g.displayEdges(); // Prints all the edges of the graph in a linked list representation
    
    g.displayVertex(); // Prints all the vertices of the graph before removing a vertex
    g.removeVertex(60); // removes 60 from the graph
    g.removeVertex(40); // removes 40 from the graph
    g.displayVertex(); // displays all the vertices of the graph after removing 60 and 40
    
    g.addVertex(100); // adds vertex 100 to the graph
    g.displayVertex(); // displays all the vertices of the graph after adding 100
}