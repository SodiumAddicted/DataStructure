#include "LinkedListHeader.h"

Node AddItem(Node *head, int value){
    Node *tempnode = NULL;
    tempnode = (Node*)malloc(sizeof(Node));
    tempnode -> next = head -> next;
    tempnode -> value = value;
    head -> next = tempnode;
    
    return *tempnode;
}
