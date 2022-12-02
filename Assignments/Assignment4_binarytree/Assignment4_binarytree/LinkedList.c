#include "Header.h"

LNode *CreateHead(void){
    LNode *head = (LNode*)malloc(sizeof(LNode));
    head -> alpha = '0';
    head -> next = NULL;
    return head;
}

LNode *AddList(LNode *head, char alpha, char *HuffmanCode){
    LNode *newone = (LNode*)malloc(sizeof(LNode));
    newone -> alpha = alpha;
    strcpy(newone -> HuffmanCode, HuffmanCode);
    newone -> next = head -> next;
    head -> next = newone;
    return newone;
}

void ShowList(LNode *head){
    LNode *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
        printf("alpha : %c, code : %s\n", temp -> alpha, temp -> HuffmanCode);
    }
}


void KillAllNode(LNode *head) {
    LNode *cur = head->next;
    while (cur != NULL){
        LNode *next = cur->next;
        free(cur);
        cur = next;
    }
}

char *Alpha2Code(LNode *head, char alpha){
    LNode *cur = NULL;
    cur = head;
    while(cur -> next != NULL){
        cur = cur -> next;
        if(alpha == cur -> alpha){ //같으면
            break;
        }
    }
    return cur -> HuffmanCode;
}

char Code2Alpha(LNode *head, char *code){
    LNode *cur = NULL;
    cur = head;
    while(cur -> next != NULL){
        cur = cur -> next;
        if(strcmp(code, cur -> HuffmanCode) == 0){ //같으면
            return cur -> alpha;
            //break;
        }
    }
    return '\0';
    
}

void Text2Code(LNode *head, char *text){
    int i = 0;
    int size = getSize(text);
    char *result = (char*)malloc(sizeof(char)*10); //10글자
    for(i = 0 ; i < size-1 ; i++){
        strcpy(result,Alpha2Code(head, text[i]));
        printf("%s", result);
    }
    free(result);
    puts("");
}


void Code2Text(LNode *head, char *codes){
    int startindex = 0;
    int range = 1;
    int size = getSize(codes);
    char *code = (char*)calloc(10,sizeof(char));
    strncpy(code,codes+startindex, range);
    while(startindex + range < size+1){
        if(Code2Alpha(head,code) != '\0'){
            printf("%c", Code2Alpha(head, code));
            startindex = startindex + range;
            range = 0;
        }
        range++;
        memset(code, 0, sizeof(char)*10);
        strncpy(code,codes+startindex, range);
    }
    free(code);
    puts("");
}

