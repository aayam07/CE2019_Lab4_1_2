#include "graph.h"

int main()
{
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
    cout << g.numVertices() << endl;
    // g.removeVertex(60);
    g.displayVertex();
    cout << g.vertex_exists(60) << endl;
    g.addEdge(10,30);
    g.addEdge(10,20);
    g.addEdge(20,40);
    g.addEdge(20,10);
    g.addEdge(30,50);
    g.addEdge(30,10);
    g.addEdge(40,60);
    g.addEdge(40,20);
    g.addEdge(50,30);
    g.addEdge(50,60);
    g.addEdge(60,50);
    g.addEdge(60,40);
    cout << g.indegree(20) << endl;



}