#include "Matrix.h"

Matrix *CreateRandMatrix(int rows, int cols){
    Matrix *newMatrix;
    newMatrix = (Matrix*)malloc(sizeof(Matrix));
    newMatrix -> rows = rows;
    newMatrix -> cols = cols;
    newMatrix -> data = NULL;
    newMatrix -> data = (int**)calloc(rows, sizeof(int*));//행 동적할당
    for(int i = 0 ; i < rows ; i++){//열 동적할당
        newMatrix -> data[i] = (int*)calloc(cols, sizeof(int));
    }
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            newMatrix -> data[i][j] = rand()%RAND_RANGE + 1; //1~10
        }
    }
    return newMatrix;
}

Matrix *CreateRandSparseMatrix(int rows, int cols){
    Matrix *newMatrix;
    newMatrix = (Matrix*)malloc(sizeof(Matrix));
    newMatrix -> rows = rows;
    newMatrix -> cols = cols;
    newMatrix -> data = NULL;
    newMatrix -> data = (int**)calloc(rows, sizeof(int*));//행 동적할당
    for(int i = 0 ; i < rows ; i++){//열 동적할당
        newMatrix -> data[i] = (int*)calloc(cols, sizeof(int));
    }
    
    int randnum;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            randnum = rand()%RAND_RANGE + 1; //1~10
            if (randnum > 3){
                randnum = 0;
            }

            newMatrix -> data[i][j] = randnum; //0,1,2,3 (0_70%)
        }
    }
    return newMatrix;
}
