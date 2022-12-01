#include "Header.h"


int main(int argc, const char * argv[]) {
    /*
    //infix 입력부
    char infixExpression[_SIZE]; //_SIZE = 64
    printf("INFIX식 입력 : ");
    scanf("%s", infixExpression); //scanf fgets 충돌
    
    Node *root = infix2binarytree(infixExpression);
    
    
    puts("");
    printf("--binary tree 변환--\n");
    printf("infix order : ");
    InfixOrder(root);
    puts("");
    
    printf("prefix order : ");
    PrefixOrder(root);
    puts("");
    
    printf("postfix order : ");
    PostfixOrder(root);
    puts("");
    
    printf("level order : ");
    LevelOrder(root);
    puts("");
    
    
    
    fflush(stdin);
    */
    
    
    
    char paragraph[_SIZE];
    printf("좋아하는 문단 입력 : ");
    fgets(paragraph, _SIZE, stdin); //공백포함입력
    
    Capsule **alphaList; //알파벳과 개수를 가지는 구조체
    alphaList = (Capsule**)calloc(_SIZE,sizeof(Capsule*));
    for(int i = 0 ; i < _SIZE ; i++){
        alphaList[i] = (Capsule*)malloc(sizeof(Capsule));
    }
    
    Classification(alphaList, paragraph); //paragraph에 있는 알파벳들을 분류하여 Capsule배열에 넣음
    SortByCount(alphaList); //배열을 count에 대한 오름차순으로 정렬
    //ShowListDetail(alphaList);
    
    HuffmanNode **treeList;
    treeList = (HuffmanNode**)calloc(getCapsuleListSize(alphaList),sizeof(HuffmanNode*));
    for(int i = 0 ; i < getCapsuleListSize(alphaList) ; i++){
        treeList[i] = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    }
    
    InitHuffmanTree(treeList, alphaList);//alphaList를 Huffman식 노드로 변경
    HuffmanNode *root = MakeHuffmanTree(treeList);
    
    SetHuffmanCode(root, 0);
    
    LNode *head = CreateHead();
    InputCode(root, head);
    ShowList(head);
    
    
    char code[200];
    printf("코드입력:");
    fgets(code ,200, stdin);
    Code2Text(head, code);
    
    
    
    
    
    
    KillHuffmanNode(root);
    KillAllNode(head);
    KillCapsuleList(alphaList);
    
    return 0;
}

