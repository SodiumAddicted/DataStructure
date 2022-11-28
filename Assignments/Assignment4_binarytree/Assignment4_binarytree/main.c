#include "Header.h"


int main(int argc, const char * argv[]) {
    
    //infix 입력부
    char infixExpression[_SIZE]; //_SIZE = 64
    printf("INFIX식 입력 : ");
    scanf("%s", infixExpression);
    
    Node *root = infix2binarytree(infixExpression);
    
    
    puts("");
    printf("--binary tree 변환--\n");
    printf("infix order:");
    InfixOrder(root);
    puts("");
    
    printf("prefix order:");
    PrefixOrder(root);
    puts("");
    
    printf("postfix order:");
    PostfixOrder(root);
    puts("");
    
    printf("level order:");
    LevelOrder(root);
    puts("");
    return 0;
}

