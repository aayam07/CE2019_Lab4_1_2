#include "graph.h"

graph::graph(bool directed)
{
    this->directed = directed;
}

graph::~graph()
{
    delete HEAD;
}

bool graph::isEmpty()
{
    if(HEAD == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}