#include "StackQueue.h"

void ParenthesisMatching(char arr[], int size){
    char currentChar;
    int match = 1;
    Stack *SParenthesis = CreateNewStack(size);
    Stack *SResult = CreateNewStack(size);
    for(int i = 0 ; i < size ; i++){
        currentChar = arr[i];
        if(currentChar == '('){
            Push(SParenthesis,currentChar);
            Push(SResult,currentChar);
            //printf("(");
            match = 0;
            ShowStackDetail(SParenthesis);
        }
        else if(currentChar == ')'){
            if(SParenthesis -> data[SParenthesis -> top] == '('){
                match = 1;
                Pop(SParenthesis);
            }
            //printf(")");
            Push(SResult,currentChar);
            ShowStackDetail(SParenthesis);
        }
        else{
            //printf("%c", currentChar);
            //Push(SResult,currentChar);
            ShowStackDetail(SParenthesis);
        }
    }
    if(!isSEmpty((SParenthesis))){
        match = 0;
    }
    while(!isSEmpty(SResult)){
        Push(SParenthesis,Pop(SResult));
    }
    while(!isSEmpty(SParenthesis)){
        printf("%c", Pop(SParenthesis));
    }
    puts("");
    if(match == 1){
        printf("MATCHING!\n");
    }
    else{
        printf("UNMATCHING!\n");
    }
    SFree(SParenthesis);
}
