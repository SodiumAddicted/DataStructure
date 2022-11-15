#include "Header.h"

//사용자로부터 입력받은 숫자로 배열 생성
double **InputNewArr(int size){
    double **newArr;
    int i;
    newArr = (double**)calloc(size,sizeof(double*));
    for(i = 0 ; i < size ; i++){
        newArr[i] = (double*)calloc(2,sizeof(double));
    }
    for(i = 0 ; i < size ; i++){
        printf("%d번째 계수와 차수 입력:", i+1);
        scanf("%lf %lf", &newArr[i][0], &newArr[i][1]);
    }
    
    return newArr;
}

double **SumArr(int size1, int size2, double **arr1, double **arr2){
    int currentExp;
    int isItGotExp = 0;
    int i,j;
    int count = 0;
    int resultSize;
    resultSize = size1+size2;
    double **resultArr;
    resultArr = (double**)calloc(resultSize,sizeof(double*));
    for(int a = 0 ; a < resultSize ; a++){
        resultArr[a] = (double*)calloc(2,sizeof(double));
    }
    
    for(i = 0 ; i < size1 ; i++){
        currentExp = arr1[i][1];
        for(j = 0 ; j < size2 ; j++){
            if(arr2[j][1] == currentExp){
                resultArr[count][0] = arr1[i][0] + arr2[j][0];
                resultArr[count][1] = currentExp;
                isItGotExp = 1;
                count++;
            }
        }
        if(isItGotExp == 0){
            resultArr[count][0] = arr1[i][0];
            resultArr[count][1] = arr1[i][1];
            count++;
        }
    }
    isItGotExp = 0;
    //이제 list2에 있는 exp가 resultarr에 없으면 추가
    for(i = 0 ; i < size2 ; i++){
        currentExp = arr2[i][1];
        for(j = 0 ; j < resultSize ; j++){
            if(resultArr[j][1] == currentExp){
                isItGotExp = 1;
            }
        }
        if(isItGotExp == 0){
            resultArr[count][0] = arr2[i][0];
            resultArr[count][1] = arr2[i][1];
            count++;
        }
        isItGotExp = 0;
    }
    return resultArr;
}

double **SubArr(int size1, int size2, double **arr1, double **arr2){
    int currentExp;
    int isItGotExp = 0;
    int i,j;
    int count = 0;
    int resultSize;
    resultSize = size1+size2;
    double **resultArr;
    resultArr = (double**)calloc(resultSize,sizeof(double*));
    for(int a = 0 ; a < resultSize ; a++){
        resultArr[a] = (double*)calloc(2,sizeof(double));
    }
    
    for(i = 0 ; i < size1 ; i++){
        currentExp = arr1[i][1];
        for(j = 0 ; j < size2 ; j++){
            if(arr2[j][1] == currentExp){
                resultArr[count][0] = arr1[i][0] - arr2[j][0];
                resultArr[count][1] = currentExp;
                isItGotExp = 1;
                count++;
            }
        }
        if(isItGotExp == 0){
            resultArr[count][0] = arr1[i][0];
            resultArr[count][1] = arr1[i][1];
            count++;
        }
    }
    isItGotExp = 0;
    //이제 list2에 있는 exp가 resultarr에 없으면 추가
    for(i = 0 ; i < size2 ; i++){
        currentExp = arr2[i][1];
        for(j = 0 ; j < resultSize ; j++){
            if(resultArr[j][1] == currentExp){
                isItGotExp = 1;
            }
        }
        if(isItGotExp == 0){
            resultArr[count][0] = -arr2[i][0];
            resultArr[count][1] = arr2[i][1];
            count++;
        }
        isItGotExp = 0;
    }
    return resultArr;
}

double **SortArr(int size, double **arr){
    int i,j;
    int tempCoef;
    int tempExp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < (size - 1) - i; j++) {
            if (arr[j][1] < arr[j + 1][1]) {    // 버블 정렬 사용
                tempCoef = arr[j][0];
                tempExp = arr[j][1];
                arr[j][1] = arr[j + 1][1];
                arr[j][0] = arr[j + 1][0];
                arr[j + 1][0] = tempCoef;
                arr[j + 1][1] = tempExp;
            }
        }
    }
    return arr;
}

void ShowArr(double **resultArr, int size){ //정렬 후 보여줌
    int opCount = 0;
    resultArr = SortArr(size, resultArr);
    for(int b = 0 ; b < size ; b++){
        if(!(resultArr[b][0] == 0)){
            if(opCount == 0){
                printf("%0.1lfx^%d",resultArr[b][0], (int)resultArr[b][1]);
                opCount++;
            }
            else{
                printf(" + %0.1lfx^%d",resultArr[b][0], (int)resultArr[b][1]);
            }
        }
    }
    puts("");
}
