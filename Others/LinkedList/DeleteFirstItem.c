#include "LinkedListHeader.h"

void DeleteFirstItem(Node *head){
    Node *tempnode = head;
    if(head -> next == NULL){
        printf("List is Null\n");
    }
    else{
        tempnode = tempnode -> next;
        head -> next = head -> next -> next;
        free(tempnode);
    }
}
