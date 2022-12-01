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

void Code2Text(LNode *head, char *codes){
    
}

void KillAllNode(LNode *head) {
    LNode *cur = head->next;
    while (cur != NULL){
        LNode *next = cur->next;
        free(cur);
        cur = next;
    }
}

