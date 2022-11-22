#include "Header.h"

int main(int argc, const char * argv[]) {
    
    //infix 입력부
    char infixExpression[_SIZE]; //_SIZE = 64
    printf("INFIX : ");
    scanf("%s", infixExpression);
    
    Node *newone = Infix2Binarytree(infixExpression);
    InfixOrder(newone);
    return 0;
}

