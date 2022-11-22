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

typedef struct stack{//char스택 구현
    int size;
    int top;
    char *data;
}Stack;

typedef struct nstack{//Node스택 구현
    int size;
    int top;
    Node *data;
}NStack;

Node *CreateNode(char data);
void DestroyTree(Node *Remove);
Queue *QueueInit(void);
int isEmpty(Queue *Q);
void Enqueue(Queue *Q, Node *node);
Node *Dequeue(Queue *Q);

Stack *CreateNewStack(int size);
int isSFull(Stack *S);
int isSEmpty(Stack *S);
void Push(Stack *S, char c);
char Pop(Stack *S);
void ShowStackDetail(Stack *S);
void SFree(Stack *S);

NStack *CreateNewNStack(int size);
int isNSFull(NStack *S);
int isNSEmpty(NStack *S);
void NPush(NStack *S, Node *N);
Node *NPop(NStack *S);
void NSFree(NStack *S);

void InfixOrder(Node *root);
void PrefixOrder(Node *root);
void PostfixOrder(Node *root);
void LevelOrder(Node *root);

Node *Infix2Binarytree(char *infix);
int Priority(char op1, char op2);
#endif /* Header_h */
