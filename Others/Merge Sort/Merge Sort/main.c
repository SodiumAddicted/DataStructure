#include <stdio.h>
#define SIZE 8

int temp[SIZE];

void merge(int *data, int m, int middle, int n){
    int i = m;
    int j = middle + 1;
    int k = m;
    while(i <= middle && j <= n){
        if(data[i] <= data[j]){
            temp[k] = data[i];
            i++;
        }
        else{
            temp[k] = data[j];
            j++;
        }
        k++;
    }
    if(i <= middle){
        for( ; i <= middle ; i++){
            temp[k] = data[i];
            k++;
        }
    }
    else{
        for( ; j <= n ; j++){
            temp[k] = data[j];
            k++;
        }
    }
    for(int t = m ; t <= n ; t++){
        data[t] = temp[t];
    }
}

void mergeSort(int *data, int m, int n){
    if(m < n){
        int middle = (m+n)/2;
        mergeSort(data, m, middle);
        mergeSort(data, middle+1, n);
        merge(data, m, middle, n);
    }
}

int main(int argc, const char * argv[]) {
    
    int list[SIZE] = {1,6,5,2,7,8,10,0};
    printf("Before Sort : ");
    for(int i = 0 ; i < SIZE ; i++){
        printf("%d ", list[i]);
    }
    puts("");
    mergeSort(list, 0, SIZE-1);
    printf("After Sort :  ");
    for(int i = 0 ; i < SIZE ; i++){
        printf("%d ", list[i]);
    }
    puts("");
    return 0;
}
