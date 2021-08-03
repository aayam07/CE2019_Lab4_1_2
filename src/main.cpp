#include "graph.h"

int main()
{
    graph g(0); // 0 means false i.e directed is set to false (assuming this as undirected graph)
    cout << g.isEmpty(); // prints 1 if the graph is directed else prints 0

}