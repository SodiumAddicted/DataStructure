#include "LinkedListHeader.h"

void AddItematLast(Node *head, int value){
    Node *tempnode = NULL;
    tempnode = head -> next;
    while(!isEmpty(tempnode)){
        tempnode = tempnode -> next;
    }
    AddItem(tempnode, value);
}
