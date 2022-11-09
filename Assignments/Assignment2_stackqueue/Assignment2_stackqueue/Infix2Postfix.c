#include "StackQueue.h"

char result[MAX_SIZE];
char *Infix2Postfix(char arr[], int size){
    char currentChar;
    //result[size];
    int count = 0;
    int Spriority = 0;
    int newPriority = 0;
    Stack *Operator = CreateNewStack(size);
    
    for(int i = 0 ; i < size ; i++){
        currentChar = arr[i];
        switch(currentChar){
            case '(':
                Push(Operator,currentChar);
                Spriority = 0;
                break;
                
            case ')':
                //Pop Operator until '('
                while(Operator -> data[Operator -> top] != '('){
                    result[count] = Pop(Operator);
                    count++;
                    //printf("%c",Pop(Operator));
                }
                //Pop'('
                Spriority = 0;
                Pop(Operator);
                break;
                
            case '+':
            case '-':
            case '*':
            case '/':
                if(Operator -> data[Operator -> top] == '+' || Operator -> data[Operator -> top] == '-'){
                    Spriority = 1;
                }
                else if(Operator -> data[Operator -> top] == '*' || Operator -> data[Operator -> top] == '/'){
                    Spriority = 2;
                }
                if(currentChar == '+' || currentChar == '-'){
                    newPriority = 1;
                }
                else if(currentChar == '*' || currentChar == '/'){
                    newPriority = 2;
                }
                if(newPriority <= Spriority){
                    if(Operator -> data[Operator -> top] != '('){
                        result[count] = Pop(Operator);
                        count++;
                        //printf("%c",Pop(Operator));
                        Push(Operator, currentChar);
                    }
                }
                else{
                    Push(Operator, currentChar);
                }
                break;
                
            default://기타 피연산자
                result[count] = currentChar;
                count++;
                //printf("%c", currentChar);
                break;
            
        }
        
    }
    //연산종료시 모든 남은 operator pop
    while(Operator -> top != -1){
        result[count] = Pop(Operator);
        count++;
        //printf("%c",Pop(Operator));
    }
    SFree(Operator);
    return result;
}

