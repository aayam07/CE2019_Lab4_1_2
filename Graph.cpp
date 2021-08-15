#include "Graph.h"
#include <iostream>
using namespace std;




Graph::Graph(bool isdirected)
{
    GRAPH_HEAD = nullptr;
    directed=isdirected;
}
Graph::~Graph(){
delete GRAPH_HEAD;

}
bool Graph::isEmpty(){
    return GRAPH_HEAD==nullptr;
}

void Graph::addVertex(int ver){
    Vertex *newVertex = new Vertex(ver, GRAPH_HEAD);

    GRAPH_HEAD = newVertex;

    std::cout<<"New Vertex added: "<<ver<<std::endl;
}

bool Graph::isVertexPresent(int ver){
        Vertex *newVertex = GRAPH_HEAD;

        while(newVertex!=nullptr && newVertex->data!=ver){

                newVertex=newVertex->nextVertex;
        }
        if(newVertex!=nullptr){
            return true;
        }
        else{
            return false;
        }

}


void Graph::addEdge(int ver1, int ver2){

    if(isVertexPresent(ver1) && isVertexPresent(ver2)){
        if(!neighbour(ver1,ver2)){
        Vertex *newVertex = GRAPH_HEAD;

        while(newVertex!=nullptr && newVertex->data!=ver1){

                newVertex=newVertex->nextVertex;
        }
if(newVertex!=nullptr){

        Vertex *tempVertex =new  Vertex(ver2,nullptr,newVertex->nextNeighbour);
        newVertex->nextNeighbour=tempVertex;

        if(!isDirected() && !neighbour(ver2,ver1)){
            addEdge(ver2,ver1);
        }
}
    }
    }
else{
    cout<<"Either one or both the vertices dont exist, hence edge cant be formed."<<endl;
}

}

void Graph::removeEdge(int ver1, int ver2){
    if (neighbour(ver1,ver2)){
        Vertex *newVertex = GRAPH_HEAD;

        while(newVertex->data!=ver1){

                newVertex=newVertex->nextVertex;
        }

Vertex *temp=newVertex->nextNeighbour;
while(temp->data!=ver2){
    temp=temp->nextNeighbour;
    newVertex=newVertex->nextNeighbour;
}
newVertex->nextNeighbour=temp->nextNeighbour;
temp=nullptr;
if(!isDirected() && neighbour(ver2,ver1)){
    removeEdge(ver2,ver1);
}
    }
    else{
        cout<<"Sorry, operation: removeEdge is unsuccessful!"<<endl;
    }
}



bool Graph::neighbour(int ver1, int ver2){
        Vertex *newVertex = GRAPH_HEAD;

        while(newVertex!=nullptr && newVertex->data!=ver1){

                newVertex=newVertex->nextVertex;
        }
while(newVertex!=nullptr && newVertex->data!=ver2){
    newVertex=newVertex->nextNeighbour;
}
if(newVertex!=nullptr){
    return true;
}
else{
    return false;
}


}




void Graph::displayVertex(){
    Vertex *newVertex = GRAPH_HEAD;
    while(newVertex!=nullptr){

        cout<<newVertex->data<<" ";
        newVertex=newVertex->nextVertex;
    }
    cout<<endl;


}
bool Graph::isDirected(){
    return directed; 
}



int Graph::outDegree(int ver){
        Vertex *newVertex = GRAPH_HEAD;
        int count=0;
if(isVertexPresent(ver)){
        while(newVertex->data!=ver){

                newVertex=newVertex->nextVertex;
        }
        Vertex *tempVertex=newVertex;
while(tempVertex->nextNeighbour!=nullptr){
    tempVertex=tempVertex->nextNeighbour;
    count++;
    
}
}
return count;
    
}
int Graph::inDegree(int ver){
        Vertex *newVertex = GRAPH_HEAD;
        int count=0;
        if(isVertexPresent(ver)){
        while(newVertex!=nullptr){
            if(newVertex->data==ver){
                            newVertex=newVertex->nextVertex;

                continue;
            }
            Vertex *tempVertex=newVertex;
            while(tempVertex->nextNeighbour!=nullptr){
                tempVertex=tempVertex->nextNeighbour;
                if(tempVertex->data==ver){
                    count++;
                }
            }
            newVertex=newVertex->nextVertex;
        }
        }
      return count;
}
int Graph::degree(int ver){
    if(isDirected()){
        return inDegree(ver)+ outDegree(ver);
    }
    else{
        return outDegree(ver);
    }
    
    return 0;
}



void Graph::neighbours(int ver){ 
    if(isVertexPresent(ver)){
        Vertex *newVertex = GRAPH_HEAD;

        while(newVertex->data!=ver){

                newVertex=newVertex->nextVertex;
        }
        Vertex *tempVertex=newVertex->nextNeighbour;
        cout<<"Neighbours of "<<ver<<":- ";
while(tempVertex!=nullptr){
    cout<<tempVertex->data<<" ";
    tempVertex=tempVertex->nextNeighbour;
    
}
cout<<endl;
    }
    else{
        cout<<ver<<" is not present."<<endl;
    }
}

void Graph::numVertices(){
   if(!isEmpty()){
       int c=0;
 Vertex *newVertex = GRAPH_HEAD;
    while(newVertex!=nullptr){
c=c+1;
        newVertex=newVertex->nextVertex;
    }
cout<<"Number of vertices:- "<<c<<endl;
   }
else{
    cout<<"Graph is empty"<<endl;
}
}

void Graph::numEdges(){
     if(!isEmpty()){
int count=0;

        Vertex *newVertex = GRAPH_HEAD;

        while(newVertex!=nullptr){
count=count + outDegree(newVertex->data);
                newVertex=newVertex->nextVertex;
        }
        if(!isDirected()){
            
count=count/2;
        }
                    cout<<"Number of edges of the graph:- "<<count<<endl;


     }
     else{
         cout<<"Graph is empty"<<endl;
     }

}

void Graph::removeVertex(int ver){
Vertex *prev=GRAPH_HEAD;
Vertex *temp=GRAPH_HEAD->nextVertex;
if(ver==GRAPH_HEAD->data){
removeAllEdges(GRAPH_HEAD);
            GRAPH_HEAD=prev->nextVertex;
            prev=nullptr;
            
            
}
else {
if(neighbour(prev->data,ver)){

    removeEdge(prev->data,ver);

    
    
}
}
while(temp!=nullptr){


if(temp->data==ver){

    removeAllEdges(temp); 
    prev->nextVertex=temp->nextVertex;
    temp=temp->nextVertex;
}
else if(neighbour(temp->data,ver)){

    removeEdge(temp->data,ver);

    if(prev!=nullptr){
    prev=prev->nextVertex;

    }
    temp=temp->nextVertex;

}
else {

if(prev!=nullptr){
    prev=prev->nextVertex;

    }
    temp=temp->nextVertex;
}
}
}


void Graph::removeAllEdges(Vertex *VerEdgeDelete){
        Vertex *tempVertex=VerEdgeDelete->nextNeighbour;
while(tempVertex!=nullptr){
    removeEdge(VerEdgeDelete->data,tempVertex->data);
    
    tempVertex=tempVertex->nextNeighbour;
    
}
}