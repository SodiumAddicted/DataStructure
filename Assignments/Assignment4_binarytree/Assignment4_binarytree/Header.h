#ifndef Header_h
#define Header_h
#include <stdio.h>
#include <stdlib.h>
#define _SIZE 64
typedef struct node *next;
typedef struct node{
    char data;
    next left;
    next right;
}Node;

typedef struct queue{//Node큐 구현
    int rear;
    int front;
    Node *data;
}Queue;
Node *CreateNode(char data);
void DestroyTree(Node *Remove);
Queue *QueueInit(void);
int isEmpty(Queue *Q);
void Enqueue(Queue *Q, Node *node);
Node *Dequeue(Queue *Q);

void InfixOrder(Node *root);
void PrefixOrder(Node *root);
void PostfixOrder(Node *root);
void LevelOrder(Node *root);
#endif /* Header_h */
