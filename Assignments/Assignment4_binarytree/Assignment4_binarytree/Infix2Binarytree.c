#include "Header.h"

Node *infix2binarytree(char *infixExpression){
    int size = 0; //infixExpression 크기
    Node *result = NULL;
    size = getSize(infixExpression);
    Stack *operator = CreateNewStack(size);
    NodeStack *operand = CreateNewNodeStack(size);
    for(int i = 0 ; i < size ; i++){
        
        char curChar = infixExpression[i];
        //연산자면
        if(isOp(curChar)){
            
            if(curChar == '('){
                Push(operator, curChar);
            }
            else if(curChar == ')'){
                while(operator -> data[operator -> top] != '('){
                    calc(operand, operator);
                }
                Pop(operator);
            }
            else{// + - * / 일경우
                if(priority(curChar) > priority(operator -> data[operator -> top])){
                    Push(operator, curChar);
                }
                else{
                    calc(operand, operator);
                    Push(operator, curChar);
                }
            }
            
        }
        //피연산자면
        else{
            NPush(operand, CreateNode(curChar));
        }
        
    }
    // 연산종료시남은거 계산
    while(operator -> top != -1){
        calc(operand, operator);
    }
    
    
    
    result = NPop(operand);
    return result;
}

void calc(NodeStack *operand, Stack *operator){
        Node *newone = CreateNode(Pop(operator));
        newone -> right = NPop(operand);
        newone -> left = NPop(operand);
        NPush(operand, newone);
}



int isOp(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')'){
        return 1;
    }
    return 0;
}

int priority(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}
