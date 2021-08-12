#include "Graph.h"
#include <iostream>
using namespace std;

int main(){
Graph g(true);
cout<<boolalpha;
cout<<g.isEmpty()<<endl;

g.addVertex(5);
g.addVertex(11);
g.addVertex(7);
g.addVertex(9);
g.addVertex(10);
g.addVertex(99);
g.displayVertex();
// cout<<g.isEmpty()<<endl;
// cout<<g.isDirected()<<endl;
g.addEdge(7,10);
g.addEdge(7,5);
g.addEdge(5,10);
g.addEdge(7,9);
g.addEdge(7,8);
g.addEdge(99,7);
g.addEdge(9,7);
cout<<endl;
cout<<g.neighbour(7,10)<<endl;
// g.removeEdge(7,10);
// cout<<g.neighbour(7,10)<<endl;

cout<<g.neighbour(10,7)<<endl;
cout<<g.neighbour(7,8)<<endl;



cout<<"Outdegree of 7:- "<<g.outDegree(7)<<endl;
cout<<"Outdegree of 10:- "<<g.outDegree(10)<<endl;
cout<<"Outdegree of 11:- "<<g.outDegree(11)<<endl;
cout<<"Indegree of 7:- "<<g.inDegree(7)<<endl;
cout<<"Indegree of 10:- "<<g.inDegree(10)<<endl;
cout<<"Indegree of 11:- "<<g.inDegree(11)<<endl;
cout<<"Degree of 7:- "<<g.degree(7)<<endl;
cout<<"Degree of 10:- "<<g.degree(10)<<endl;
cout<<"Degree of 11:- "<<g.degree(11)<<endl;

g.neighbours(11);
g.numVertices();
g.numEdges();

}