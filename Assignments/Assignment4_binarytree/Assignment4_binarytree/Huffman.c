#include "Header.h"

Capsule *CreateCapsule(char alpha){
    Capsule *cap = (Capsule*)malloc(sizeof(Capsule));
    
    cap -> count = 0;
    cap -> alpha = alpha;
    
    return cap;
}

void SortByCount(Capsule **list){ //bubblesort
    int size = getCapsuleListSize(list);
    int endCursor = size-1;
    while(endCursor > 0){
        for(int i = 0 ; i < endCursor ; i++){
            //0부터 end 까지 작은건 뒤로
            if(list[i+1] -> alpha != '\n' && list[i] -> count < list[i+1] -> count){
                CapSwap(list[i], list[i+1]);
            }
        }
        
        endCursor--;
    }
}

HuffmanNode *CreateHuffNode(int sumCount){
    HuffmanNode *newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    
    newNode -> cap = (Capsule*)malloc(sizeof(Capsule));
    newNode -> cap = CreateCapsule('\0');
    newNode -> sumCount = sumCount;
    newNode -> left = NULL;
    newNode -> right = NULL;
    
    return newNode;
}

void InitHuffmanTree(HuffmanNode **Hufflist, Capsule** Caplist){
    int size = getCapsuleListSize(Caplist);
    for(int i = 0 ; i < size ; i++){
        Hufflist[i] = CreateHuffNode(Caplist[i] -> count);
        Hufflist[i] -> cap = Caplist[i];
    }
}

HuffmanNode *MakeHuffmanTree(HuffmanNode **Hufflist){
    HuffmanNode *root = NULL;
    while(getHuffListSize(Hufflist) != 1){
        LinkMin2Node(Hufflist); //제일 작은 sumCount두개 찾아서 부모노드만들고 리스트 추가, 두노드는 리스트에서 삭제.
    }
    root = Hufflist[0];
    return root;
}

void HuffSwap(HuffmanNode *c1, HuffmanNode *c2){
    HuffmanNode *temp = CreateHuffNode(0);
    temp -> sumCount = c1 -> sumCount;
    temp -> cap = c1 -> cap;
    temp -> left = c1 -> left;
    temp -> right = c1 -> right;
    c1 -> sumCount = c2 -> sumCount;
    c1 -> cap = c2 -> cap;
    c1 -> left = c2 -> left;
    c1 -> right = c2 -> right;
    c2 -> sumCount = temp -> sumCount;
    c2 -> cap = temp -> cap;
    c2 -> left = temp -> left;
    c2 -> right = temp -> right;
    KillHuffmanNode(temp);
}

void SortBySumCount(HuffmanNode **list){ //bubblesort
    int size = getHuffListSize(list);
    int endCursor = size-1;
    while(endCursor > 0){
        for(int i = 0 ; i < endCursor ; i++){
            //0부터 end 까지 작은건 뒤로
            if(list[i] -> sumCount != 0 && list[i] -> sumCount < list[i+1] -> sumCount){
                HuffSwap(list[i], list[i+1]);
            }
        }
        endCursor--;
    }
}

void LinkMin2Node(HuffmanNode **Hufflist){
    int size = getHuffListSize(Hufflist);
    SortBySumCount(Hufflist);
    //두 노드의 카운트 합을 갖는 노드
    //printf("Cap1 : %c, Cap2 : %c \n", Hufflist[size-1] -> cap -> alpha, Hufflist[size-2] -> cap -> alpha);
    //printf("NODE1 : %d, NODE2 : %d\n", Hufflist[size-1] -> sumCount, Hufflist[size-2] -> sumCount);
    
    HuffmanNode *newone = CreateHuffNode(Hufflist[size-1] -> sumCount + Hufflist[size-2] -> sumCount);
    //sort하여 맨뒤두개 이어 새로노드만듬
    newone -> right = Hufflist[size-1];
    newone -> left = Hufflist[size-2];
    Hufflist[size-1] = NULL;
    Hufflist[size-2] = NULL;
    Hufflist[size-2] = newone;
    
}

void CapSwap(Capsule *c1, Capsule *c2){
    Capsule *temp = CreateCapsule('\0');
    temp -> count = c1 -> count;
    temp -> alpha = c1 -> alpha;
    c1 -> count = c2 -> count;
    c1 -> alpha = c2 -> alpha;
    c2 -> count = temp -> count;
    c2 -> alpha = temp -> alpha;
    KillCapsule(temp);
}

void ShowListDetail(Capsule **list){
    for(int i = 0 ; i < _SIZE ; i++){
        if(list[i] -> count > 0 && list[i] -> alpha != '\n'){
            printf("alpha : %c, count : %d\n", list[i] -> alpha, list[i] -> count);
            
        }
    }
}

void Classification(Capsule **list, char *paragraph){
    int cursor = 0;
    int size = getSize(paragraph);
    for(int i = 0 ; i < size ; i++){
        if(isInList(list, paragraph[i])){
            list[searchInList(list, paragraph[i])] -> count++;
        }
        else{
            list[cursor] = CreateCapsule(paragraph[i]);
            list[cursor] -> count++;
            cursor++;
        }
    }
    
}

int isInList(Capsule **list, char ch){
    int i = 0;
    while(list[i] != NULL){
        if(list[i] -> alpha == ch && list[i] -> count > 0){
            return 1;
        }
        i++;
    }
    return 0;
}

int searchInList(Capsule **list, char ch){
    int i = 0;
    while(list[i] != NULL){
        if(list[i] -> alpha == ch && list[i] -> count > 0){
            return i;
        }
        i++;
    }
    return -1;
}

void KillCapsule(Capsule *cap){
    free(cap);
}

void KillCapsuleList(Capsule **list){
    int i = 0;
    while(list[i] != NULL){
        free(list[i]);
        i++;
    }
}

void KillHuffmanNode(HuffmanNode *node){
    free(node);
}


void SetHuffmanCode(HuffmanNode *root, int times){
    if(root != NULL){
        if(root -> left != NULL){
            strncpy(root -> left -> Huffmancode, root -> Huffmancode, times);
            strcat(root -> left -> Huffmancode, "0");
            SetHuffmanCode(root -> left, times+1);
        }
        if(root -> right != NULL){
            strncpy(root -> right -> Huffmancode, root -> Huffmancode, times);
            strcat(root -> right -> Huffmancode, "1");
            SetHuffmanCode(root -> right, times+1);
            
        }
    }
}


void HuffmanInfixOrder(HuffmanNode *root){ //inorder
    if(root != NULL && root -> sumCount > 0){
        HuffmanInfixOrder(root -> left);
        if(root -> cap -> alpha != '\0'){
            printf("code:%4s / alpha:%c\n", root -> Huffmancode, root -> cap -> alpha);
        }
        HuffmanInfixOrder(root -> right);
    }
}

void InputCode(HuffmanNode *root, LNode *head){
    if(root != NULL && root -> sumCount > 0){
        InputCode(root -> left, head);
        if(root -> cap -> alpha != '\0'){
            AddList(head, root -> cap -> alpha, root -> Huffmancode);
        }
        InputCode(root -> right, head);
    }
}

