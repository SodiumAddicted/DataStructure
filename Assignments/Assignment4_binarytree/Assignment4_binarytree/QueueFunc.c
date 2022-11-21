#include "Header.h"

Queue *QueueInit(void){
    Queue *result;
    result = (Queue*)malloc(sizeof(Queue)*_SIZE);
    result -> front = -1;
    result -> rear = -1;
    result -> data = (Node*)malloc(sizeof(Node)*_SIZE);
    return result;
}

int isEmpty(Queue *Q){ //여기서 isFull은 만들 필요 없음, 같은 이유로 원형큐가 아님.
    if(Q -> rear == Q -> front){
        return 1;
    }
    return 0;
}

void Enqueue(Queue *Q, Node *node){
    Q -> rear++;
    Q -> data[Q -> rear] = *node;
}

Node *Dequeue(Queue *Q){
    Q -> front++;
    return &(Q -> data[Q -> front]);
}
