#include "StackQueue.h"

void ParenthesisMatching(char arr[], int size){
    char currentChar;
    int match = 1;
    Stack *SParenthesis = CreateNewStack(size);
    for(int i = 0 ; i < size ; i++){
        currentChar = arr[i];
        if(currentChar == '('){
            Push(SParenthesis,currentChar);
            printf("(");
            match = 0;
        }
        else if(currentChar == ')'){
            if(SParenthesis -> data[SParenthesis -> top] == '('){
                match = 1;
                Pop(SParenthesis);
            }
            printf(")");
        }
        else{
            printf("%c", currentChar);
        }
    }
    if(!isSEmpty((SParenthesis))){
        match = 0;
    }
    puts("");
    if(match == 1){
        printf("MATCHING!\n");
    }
    else{
        printf("UNMATCHING!\n");
    }
}
