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

bool graph::isdirected()
{
    if(this->directed == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}