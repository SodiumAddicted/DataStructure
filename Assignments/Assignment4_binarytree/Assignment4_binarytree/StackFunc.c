#include "Header.h"

Stack *CreateNewStack(int size){
    Stack *S;
    S = (Stack*)malloc(sizeof(Stack)); //구조체 동적할당
    S -> size = size;
    S -> top = -1; //빈경우
    S -> data = (char*)malloc(sizeof(char)*size);
    return S;
}

int isSFull(Stack *S){
    if(S -> top == S -> size - 1){
        return 1;
    }
    return 0;
}

int isSEmpty(Stack *S){
    if(S -> top == -1){
        return 1;
    }
    return 0;
}

void Push(Stack *S, char c){
    if(isSFull(S)){
        printf("Rejected : Stack is already full\n");
    }
    else{
        S -> top++;
        S -> data[S -> top] = c;
    }
}

char Pop(Stack *S){
    if(isSEmpty(S)){
        printf("Error : Stack is empty\n");
        exit(1);
    }
    else{
        //printf("Pop : %c\n", S -> data[S -> top]);
    }
    return S -> data[S -> top--]; //반환 후 top - 1
}

void ShowStackDetail(Stack *S){
    printf("Bottom -> Top\n");
    for(int i = 0 ; i < S -> top + 1 ; i++){
        printf("%c ", S -> data[i]);
    }
    puts("");
}

void SFree(Stack *S){
    free(S -> data);
    free(S);
}
