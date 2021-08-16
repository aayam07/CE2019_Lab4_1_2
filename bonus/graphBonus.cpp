#include "graphBonus.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

GraphBonus::GraphBonus(){
    srand(time(0)) ;
    gl.directed= rand()%2;
}
bool GraphBonus::isDirected(){
    gl.isDirected();
}


void GraphBonus::addVertex(int verNo){
    srand(time(0));
    int count=0;
    int ver;
    while (count<verNo){
     ver=rand()%10 +1;

    if(!gl.isVertexPresent(ver)){
        gl.addVertex(ver);
        count++;
    }
    }
}
void GraphBonus::addEdge(int EdgeNo){
    srand(time(0)) ;
    int count=0;
    int ver1, ver2;
    while (count<EdgeNo){
        ver1=rand()%10 +1;
        ver2=rand()%10 +1;

        if((gl.isVertexPresent(ver1) && gl.isVertexPresent(ver2)) && !gl.neighbour(ver1,ver2)){
            gl.addEdge(ver1,ver2);
            count++;
        }
    }

}

void GraphBonus::displayVertex(){
    gl.displayVertex();
}

void GraphBonus::displayEdge(){
    gl.displayEdge();
}