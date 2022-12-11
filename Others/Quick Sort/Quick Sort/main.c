#include <stdio.h>

void swap(int *array, int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void QuickSort(int *data, int start, int end){
    if (start >= end){
        return;
    }
    int key = start;
    int i = start + 1;
    int j = end;
    while(i <= j){
        while(data[i] <= data[key]){
            i++;
        }
        while(data[j] >= data[key] && j > start){
            j--;
        }
        if(i > j){// 엇갈린경우
            swap(data, key, j);
        }
        else{// 안엇갈린경우
            swap(data, i, j);
        }
    }
    QuickSort(data, start, j-1);
    QuickSort(data, j+1, end);
}



int main(int argc, const char * argv[]) {
    int list[11] = {1,10,4,5,7,2,3,6,9,8,0};
    printf("Before sort : ");
    for(int i = 0 ; i < 11 ; i++){
        printf("%d ", list[i]);
    }
    puts("");
    QuickSort(list, 0, 10);
    printf("After sort :  ");
    for(int i = 0 ; i < 11 ; i++){
        printf("%d ", list[i]);
    }
    puts("");
    
    
    return 0;
}
