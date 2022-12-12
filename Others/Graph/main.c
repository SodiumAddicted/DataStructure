#include "Header.h"


int main(int argc, const char * argv[]) {
    GraphType *MyGraph = (GraphType*)malloc(sizeof(GraphType));
    graphInit(MyGraph);
    insertVertex(MyGraph, 0);
    insertVertex(MyGraph, 1);
    insertVertex(MyGraph, 2);
    insertVertex(MyGraph, 3);
    insertEdge(MyGraph, 0, 1);
    insertEdge(MyGraph, 0, 3);
    insertEdge(MyGraph, 1, 0);
    insertEdge(MyGraph, 1, 2);
    insertEdge(MyGraph, 1, 3);
    insertEdge(MyGraph, 2, 1);
    insertEdge(MyGraph, 2, 3);
    insertEdge(MyGraph, 3, 0);
    insertEdge(MyGraph, 3, 1);
    insertEdge(MyGraph, 3, 2);
    printAdjList(MyGraph);
    return 0;
}
