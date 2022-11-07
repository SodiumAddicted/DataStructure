#include "LinkedListHeader.h"

void showListItem(Node *head){
    Node *tempnode = NULL;
    tempnode = head -> next;
    if(tempnode != NULL){
        printf("[");
        while(tempnode != NULL){
            if(tempnode -> next != NULL){
                printf("%d, ", tempnode -> value);
                tempnode = tempnode -> next;
            }
            else{
                printf("%d]\n", tempnode -> value);
                break;
            }
        }
    }
    else{
        printf("The List is Empty!\n");
    }
}
