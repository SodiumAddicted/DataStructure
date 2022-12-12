#ifndef Header_h
#define Header_h
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
typedef struct GraphNode{
    int vertex;
    struct GraphNode *link;
}GraphNode;

typedef struct GraphType{
    int numofVertex;
    GraphNode *adjList[MAX_VERTICES]; //연결노드가 들어갈 배열
}GraphType;


void graphInit(GraphType *G);
void insertVertex(GraphType *G, int vertex);
void insertEdge(GraphType *G, int tail, int head);
void printAdjList(GraphType *G);

#endif /* Header_h */
