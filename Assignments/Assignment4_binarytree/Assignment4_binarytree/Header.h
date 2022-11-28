#ifndef Header_h
#define Header_h
#include <stdio.h>
#include <stdlib.h>
#define _SIZE 64
typedef struct node{
    char data;
    struct node *left;
    struct node *right;
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

typedef struct nodestack{//char스택 구현
    int size;
    int top;
    Node **data; //노드를 담을 수 있는 data배열
}NodeStack;

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

NodeStack *CreateNewNodeStack(int size);
int isNSFull(NodeStack *S);
int isNSEmpty(NodeStack *S);
void NPush(NodeStack *S, Node *node);
Node *NPop(NodeStack *S);
void ShowNodeStackDetail(NodeStack *S);
void NSFree(NodeStack *S);

void InfixOrder(Node *root);
void PrefixOrder(Node *root);
void PostfixOrder(Node *root);
void LevelOrder(Node *root);

Node *infix2binarytree(char *infixExpression);
int isOp(char ch);
int priority(char ch);
void calc(NodeStack *operand, Stack *operator);
#endif /* Header_h */
