#include "Header.h"

//이진트리로 변환방법은?
Node *Infix2Binarytree(char *infix){
    Node *newone = NULL;
    int i = 0;
    NStack *opStack = CreateNewNStack(_SIZE); //a b c d e
    Stack *oprStack = CreateNewStack(_SIZE); //( ) + - * /
    while(infix[i] != '\0'){
        if(infix[i] == '('){
            Push(oprStack, infix[i]);
        }
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
            if(oprStack -> top == -1){//opr스택 비어있으면 그냥 push
                Push(oprStack, infix[i]);
            }
            else if(Priority(infix[i], oprStack -> data[oprStack -> top]) == 1){ //입력우선순위가 높으면
                newone = CreateNode(Pop(oprStack));
                Node *right = NPop(opStack);
                Node *left = NPop(opStack);
                newone -> left = left;
                newone -> right = right;
                NPush(opStack, newone);
            }
        }
        else if(infix[i] == ')'){
            while(oprStack -> data[oprStack -> top] != '('){
                newone = CreateNode(Pop(oprStack));
                Node *right = NPop(opStack);
                Node *left = NPop(opStack);
                newone -> left = left;
                newone -> right = right;
                NPush(opStack, newone);
            }
            Pop(oprStack);//'('괄호제거
        }
        else{ //피연산자
            NPush(opStack, CreateNode(infix[i]));
        }
        i++;
    }
    return newone; //마지막 사용한 newone포인터 반환
}

int Priority(char op1, char op2){ // op1 >= op2 1, else 0
    if(op1 == '('){
        return 1;
    }
    else if(op1 == '+' || op1 == '-'){
        if(op2 == '+' || op2 == '-'){
            return 1;
        }
        else if(op2 == '*' || op2 == '/'){
            return 0;
        }
    }
    else if(op1 == '*' || op1 == '/'){
        if(op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/'){
            return 1;
        }
    }
    printf("Priority() error!\n");
    return -1;
}
