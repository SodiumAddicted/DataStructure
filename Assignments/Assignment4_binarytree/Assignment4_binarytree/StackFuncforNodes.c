#include "Header.h"

NStack *CreateNewNStack(int size){
    NStack *S;
    S = (NStack*)malloc(sizeof(NStack)); //구조체 동적할당
    S -> size = size;
    S -> top = -1; //빈경우
    S -> data = (Node*)malloc(sizeof(Node)*size);
    return S;
}

int isNSFull(NStack *S){
    if(S -> top == S -> size - 1){
        return 1;
    }
    return 0;
}

int isNSEmpty(NStack *S){
    if(S -> top == -1){
        return 1;
    }
    return 0;
}

void NPush(NStack *S, Node *N){
    if(isNSFull(S)){
        printf("Rejected : Stack is already full\n");
    }
    else{
        S -> top++;
        S -> data[S -> top] = *N;
    }
}

Node *NPop(NStack *S){
    if(isNSEmpty(S)){
        printf("Error : Stack is empty\n");
        exit(1);
    }
    else{
        //printf("Pop : %c\n", S -> data[S -> top]);
    }
    return &S -> data[S -> top--]; //반환 후 top - 1
}

void NSFree(NStack *S){
    free(S -> data);
    free(S);
}
