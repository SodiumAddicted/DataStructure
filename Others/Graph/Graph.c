#include "Header.h"

void graphInit(GraphType *G){
    G -> numofVertex = 0;
    for(int i = 0 ; i < MAX_VERTICES ; i++){
        G -> adjList[i] = NULL;
    }
}

void insertVertex(GraphType *G, int vertex){
    if(G -> numofVertex > MAX_VERTICES){
        fprintf(stderr,"Graph Overflow Error");
        return;
    }
    G -> numofVertex++;
}

void insertEdge(GraphType *G, int tail, int head){
    if(tail > G -> numofVertex || head > G -> numofVertex){
        fprintf(stderr,"Graph Node Input Error");
        return;
    }
    
    GraphNode *newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode -> vertex = head;
    newNode -> link = G -> adjList[tail];
    G -> adjList[tail] = newNode;
}

void printAdjList(GraphType *G){
    for(int i = 0 ; i < G -> numofVertex ; i++){
        GraphNode *P = G -> adjList[i];
        printf("Vertex %d의 인접 리스트 : ", i);
        while(P != NULL){
            if(P -> link != NULL){
                printf("%d, ", P -> vertex);
            }
            else{
                printf("%d", P -> vertex);
            }
            P = P -> link;
        }
        puts("");
    }
}
