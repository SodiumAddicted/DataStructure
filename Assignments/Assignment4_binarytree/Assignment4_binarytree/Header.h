#ifndef Header_h
#define Header_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _SIZE 128
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

typedef struct huffmanCap{
    char alpha;
    int count;
}Capsule;

typedef struct huffmanTree{
    Capsule *cap;
    int sumCount;
    char Huffmancode[50];
    struct huffmanTree *left;
    struct huffmanTree *right;
}HuffmanNode;

typedef struct linkedList{
    char alpha;
    char HuffmanCode[50];
    struct linkedList *next;
}LNode;

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

int getSize(char *str);
int getCapsuleListSize(Capsule **list);
int getHuffListSize(HuffmanNode **list);

void Classification(Capsule **list, char *paragraph);
void SortByCount(Capsule **list);
void ShowListDetail(Capsule **list);
void CapSwap(Capsule *c1, Capsule *c2);
int isInList(Capsule **list, char ch);
int searchInList(Capsule **list, char ch);
void KillCapsule(Capsule *cap);
void KillCapsuleList(Capsule **list);
void SetHuffmanCode(HuffmanNode *root, int times);

HuffmanNode *CreateHuffNode(int sumCount);
void InitHuffmanTree(HuffmanNode **Hufflist, Capsule** Caplist);
HuffmanNode *MakeHuffmanTree(HuffmanNode **Hufflist);
void LinkMin2Node(HuffmanNode **Hufflist);
void KillHuffmanNode(HuffmanNode *node);
void HuffSwap(HuffmanNode *c1, HuffmanNode *c2);
void SortBySumCount(HuffmanNode **list);
void HuffmanInfixOrder(HuffmanNode *root);

LNode *CreateHead(void);
LNode *AddList(LNode *head, char alpha, char *HuffmanCode);
void ShowList(LNode *head);
void InputCode(HuffmanNode *root, LNode *head);

void KillAllNode(LNode *head);
void Code2Text(LNode *head, char *codes);
void Text2Code(LNode *head, char *text);

char *Alpha2Code(LNode *head, char alpha);
char Code2Alpha(LNode *head, char *code);
#endif /* Header_h */
