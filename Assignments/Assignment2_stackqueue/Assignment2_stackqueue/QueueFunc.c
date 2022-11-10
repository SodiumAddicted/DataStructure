#include "StackQueue.h"

Queue *CreateNewQueue(int size){
    Queue *new;
    new = (Queue*)malloc(sizeof(Queue));
    new -> size = size;
    new -> rear = 0;
    new -> front = 0;
    new -> lastop = 0;
    new -> data = (char*)calloc(size,sizeof(char));
    return new;
}

int isQEmpty(Queue *Q){
    if(Q -> lastop == 0 && Q -> rear == Q -> front){
        return 1;
    }
    return 0;
}

int isQFull(Queue *Q){
    if(Q -> lastop == 1 && Q -> rear == Q -> front){
        return 1;
    }
    return 0;
}

void Enqueue(Queue *Q, char alpha){
    if(isQFull(Q)){
        printf("Queue is already full\n");
    }
    else{
        Q -> rear = (Q -> rear + 1) % Q -> size;
        Q -> data[Q -> rear-1] = alpha;
        Q -> lastop = 1;
    }
}
char Dequeue(Queue *Q){
    char element;
    if(isQEmpty(Q)){
        printf("Queue is already empty\n");
        return 0;
    }
    else{
        Q -> front = (Q -> front + 1) % Q -> size;
        element = Q -> data[Q -> front-1];
        Q -> data[Q -> front-1] = 0;
        Q -> lastop = 0;
    }
    return element;
}


void ShowQueueDetail(Queue *Q){
    printf("rear:%d front:%d size:%d lastop:%d\n", Q -> rear, Q -> front, Q -> size, Q -> lastop);
    for(int i = 0 ; i < Q -> size ; i++){
        printf("%c ", Q -> data[i]);
    }
    puts("");
    puts("");
}

void QFree(Queue *Q){
    free(Q -> data);
    free(Q);
}
