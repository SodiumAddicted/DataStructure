#include "LinkedListHeader.h"

void DeleteItem(Node *head, int item){
    Node *tempnode = NULL;
    int found = 0;
    tempnode = head;
    while(!isEmpty(tempnode)){//다음 노드가 존재하면
        if(tempnode -> next -> value == item){//찾았을 때
            Node *tempnode2 = tempnode -> next;
            tempnode -> next = tempnode -> next -> next;
            free(tempnode2);
            found++;
        }
        else{
            tempnode = tempnode -> next;
        }
    }
    if(found == 0){
        printf("There are no value %d Cannot delete.\n", item);
    }
}
