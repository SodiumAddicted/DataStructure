#include "StackQueue.h"

void ParenthesisMatching(char arr[], int size){
    char currentChar;
    int match = 1;
    int *index = (int*)calloc(size,sizeof(int));
    int count = 0;
    int indexcount = 0;
    Stack *SParenthesis = CreateNewStack(size);
    Stack *SResult = CreateNewStack(size);
    for(int i = 0 ; i < size ; i++){
        currentChar = arr[i];
        if(currentChar == '('){
            Push(SParenthesis,currentChar);
            Push(SResult,currentChar);
            match = 0;
            ShowStackDetail(SParenthesis);
            index[indexcount++] = count++;
        }
        else if(currentChar == ')'){
            if(SParenthesis -> data[SParenthesis -> top] == '('){
                match = 1;
                Pop(SParenthesis);
            }
            Push(SResult,currentChar);
            ShowStackDetail(SParenthesis);
            index[indexcount++] = count++;
        }
        else{
            //ShowStackDetail(SParenthesis);
            count++;
        }
    }
    if(!isSEmpty((SParenthesis))){
        match = 0;
    }
    while(!isSEmpty(SResult)){
        Push(SParenthesis,Pop(SResult));
    }
    
    if(match == 1){
        printf("MATCHING!\n");
    }
    else{
        printf("UNMATCHING!\n");
    }
    printf("Each Parenthesis at index...\n");
    for(int i = 0 ; i < indexcount ; i++){
        printf("%2d ", index[i]+1);
    }
    puts("");
    while(!isSEmpty(SParenthesis)){
        printf("%2c ", Pop(SParenthesis));
    }
    puts("");
    SFree(SParenthesis);
    free(index);
}
