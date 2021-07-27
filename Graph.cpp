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





// void Graph::addEdge(int ver1, int ver2){
//         Vertex *newVertex = GRAPH_HEAD;

//         while(newVertex!=nullptr && (newVertex->data!=ver1 && newVertex->data!=ver2)){

//                 newVertex=newVertex->nextVertex;
//         }
// if(newVertex!=nullptr){
//     if(newVertex->data==ver1){
//     if(isVertexPresent(ver2)){
//         Vertex *tempVertex =new  Vertex(ver2,nullptr,newVertex->nextNeighbour);
//         newVertex->nextNeighbour=tempVertex;
//         }
//         else{
//                 cout<<ver2<<" doesnt exist."<<endl;

//         }
//     }
//     else{
//             if(isVertexPresent(ver1)){
//         Vertex *tempVertex =new  Vertex(ver1,nullptr,newVertex->nextNeighbour);
//         newVertex->nextNeighbour=tempVertex;
//         }
//         else{
//                 cout<<ver1<<" doesnt exist."<<endl;

//         }
//     }

// }
// else{
//     cout<<ver1<<" doesnt exist."<<endl;
// }

// }


void Graph::addEdge(int ver1, int ver2){

    if(isVertexPresent(ver1) && isVertexPresent(ver2)){
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
else{
    cout<<"Either one or both the vertices dont exist, hence edge cant be formed."<<endl;
}

}



// void Graph::addEdge(int ver1, int ver2){
//         Vertex *newVertex = GRAPH_HEAD;

//         while(newVertex!=nullptr && newVertex->data!=ver1){

//                 newVertex=newVertex->nextVertex;
//         }
// if(newVertex!=nullptr){
//     if(isVertexPresent(ver2)){
//         Vertex *tempVertex =new  Vertex(ver2,nullptr,newVertex->nextNeighbour);
//         newVertex->nextNeighbour=tempVertex;}
//         else{
//                 cout<<ver2<<" doesnt exist."<<endl;

//         }
// }
// else{
//     cout<<ver1<<" doesnt exist."<<endl;
// }

// }



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

void Graph::outDegree(int ver){
    if(isVertexPresent(ver)){
        Vertex *newVertex = GRAPH_HEAD;
        int count=0;

        while(newVertex->data!=ver){

                newVertex=newVertex->nextVertex;
        }
        Vertex *tempVertex=newVertex;
while(tempVertex->nextNeighbour!=nullptr){
    tempVertex=tempVertex->nextNeighbour;
    count++;
    
}
cout<<"Outdegree of "<<ver<<"= "<<count<<endl;
    }
    else{
        cout<<ver<<" is not present."<<endl;
    }
}
