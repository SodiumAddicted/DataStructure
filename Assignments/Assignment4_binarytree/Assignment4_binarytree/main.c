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
    
    
    
    char paragraph[200]; //200자까지 가능
    printf("좋아하는 문단 입력 : ");
    fgets(paragraph, 200, stdin); //공백포함입력
    
    Capsule **alphaList; //알파벳과 개수를 가지는 구조체
    alphaList = (Capsule**)calloc(200,sizeof(Capsule*));
    for(int i = 0 ; i < 200 ; i++){
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
    InputCode(root, head); //리스트에 허프만코드 삽입
    printf("-------code list-------\n");
    ShowList(head);
    printf("-----------------------\n");
    
    printf("^^Huffman Code Expression : ");
    Text2Code(head, paragraph);
    
    char code[1000];
    printf("코드입력 : ");
    fgets(code ,1000, stdin);
    
    printf("^^Alphabet Expression : ");
    Code2Text(head, code);
    
    
    
    
    
    KillHuffmanNode(root);
    KillAllNode(head);
    free(treeList);
    KillCapsuleList(alphaList);
    
    return 0;
}

