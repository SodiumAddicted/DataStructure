#include "LinkedListHeader.h"

int isEmpty(Node *N){
    if(N -> next == NULL){
        return 1;
    }
    return 0;
}
