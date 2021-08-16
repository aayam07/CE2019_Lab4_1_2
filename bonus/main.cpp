#include "graphBonus.h"
#include <iostream>

using namespace std;

int main(){
cout<<boolalpha;
GraphBonus g;
cout<<"Is the graph directed? "<<g.isDirected()<<endl; // directed/undirected property is also random
g.addVertex(8); // adds 8 vertices of random unique values
g.displayVertex(); //displays randomly created vertices
g.addEdge(10); // adds 10 edges randomly
g.displayEdge(); //displays randomly added edges(if the graph is undirected, shows twice the number of edges, as a->b also means b->a)
}