#include "LinkedListHeader.h"

void MakeListEmpty(Node *head){
    Node *target = head -> next;
    Node *tempnode = NULL;
    while(target != NULL){
        tempnode = target -> next;
        free(target);
        target = tempnode;
        
    }
    head -> next = NULL;
}
