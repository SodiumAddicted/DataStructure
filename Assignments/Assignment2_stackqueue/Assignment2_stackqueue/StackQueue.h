#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif


#ifndef StackQueue_h
#define StackQueue_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct polynomial{//연결리스트 구현
    struct polynomial *next;
    double coef; //계수
    int exp; //지수
}Poly;

typedef struct queue{//char큐 구현
    int size;
    int rear;
    int front;
    int lastop; //enqueue 1 dequeue 0
    char *data;
}Queue;

int isEmpty(Poly *head);
Poly *CreateAbsolPoly(double arr[][2], int count);
Poly *CreateNewHead(void);
Poly *AddFirst(Poly *head, double coef, int exp);
Poly *AddLast(Poly *head, double coef, int exp);
Poly *KillFirst(Poly *head);
Poly *KillLast(Poly *head);
void ShowPoly(Poly *head);
void SwapNode(Poly *a, Poly *b);
double GetResult(Poly *head, double n);
Poly *PolySort(Poly* head);
void PolyFree(Poly *head);

int isQEmpty(Queue *Q);
int isQFull(Queue *Q);
Queue *CreateNewQueue(int size);
void ShowQueueDetail(Queue *Q);
void Enqueue(Queue *Q, char alpha);
char Dequeue(Queue *Q);
void QFree(Queue *Q);

#endif /* StackQueue_h */
