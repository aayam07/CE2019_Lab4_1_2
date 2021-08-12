#include "Graph.h"
#include <iostream>
using namespace std;

int main(){
Graph g(false);
cout<<boolalpha;
cout<<g.isEmpty()<<endl;

g.addVertex(5);
g.addVertex(11);
g.addVertex(7);
g.addVertex(9);
g.addVertex(10);

g.displayVertex();
// cout<<g.isEmpty()<<endl;
// cout<<g.isDirected()<<endl;
g.addEdge(7,10);
g.addEdge(7,5);
g.addEdge(5,10);
g.addEdge(7,9);
g.addEdge(7,8);
cout<<endl;
cout<<g.neighbour(7,10)<<endl;
g.removeEdge(7,10);
cout<<g.neighbour(7,10)<<endl;

cout<<g.neighbour(10,7)<<endl;
cout<<g.neighbour(7,8)<<endl;



g.outDegree(7);
g.outDegree(10);
g.outDegree(11);
g.inDegree(7);
g.inDegree(10);
g.inDegree(11);
g.neighbours(11);
g.numVertices();
}