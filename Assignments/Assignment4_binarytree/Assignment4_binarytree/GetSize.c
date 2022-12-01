#include "Header.h"

int getSize(char *str){
    int size = 0;
    while(str[size] != '\0'){
        size++;
    }
    return size;
}

int getCapsuleListSize(Capsule **list){
    int size = 0;
    while(list[size] -> count != 0 && list[size] -> alpha != '\n'){
        size++;
    }
    return size;
}

int getHuffListSize(HuffmanNode **list){
    int size = 0;
    while(list[size] != NULL){
        size++;
    }
    return size;
}
