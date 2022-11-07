#include "LinkedListHeader.h"

Node *head = NULL;

int main(int argc, const char * argv[]) {
    head = (Node*)malloc(sizeof(Node));
    AddItem(head, 0);
    AddItem(head, 1);
    AddItematLast(head, 3);
    AddItematLast(head, 2);
    DeleteItem(head, 1);
    
    //MakeListEmpty(head);
    showListItem(head);
    printf("%d\n", FindItem(head,0).value);
    
    return 0;
}

