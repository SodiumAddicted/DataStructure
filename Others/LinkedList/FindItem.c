#include "LinkedListHeader.h"

Node FindItem(Node *head, int item){
    Node *tempnode = NULL;
    int count = 0;
    tempnode = (Node*)malloc(sizeof(Node));
    tempnode = head;
    while(!isEmpty(tempnode)){//다음 노드가 존재하면
        if(tempnode -> value != item){
            tempnode = tempnode -> next;
            count++;
        }
        else{
            break;
        }
    }
    if(tempnode -> value == item){
        printf("%d in arrayindex [%d]\n", item, count-1);
        return *tempnode;
    }
    printf("Search Fail!!\n");
    exit(1);
}
