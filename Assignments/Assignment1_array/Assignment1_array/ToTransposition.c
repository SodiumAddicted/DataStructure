#include "Matrix.h"

Matrix *ToTransposition(Matrix *X){
    Matrix *T;
    T = (Matrix*)malloc(sizeof(Matrix));
    T -> rows = X->cols;
    T -> cols = X->rows;
    T -> data = NULL;
    T -> data = (int**)calloc(T -> rows, sizeof(int*));//행 동적할당
    for(int i = 0 ; i < T -> rows ; i++){//열 동적할당
        T -> data[i] = (int*)calloc(T -> cols, sizeof(int));
    }
    for(int i = 0 ; i < X->rows ; i++){
        for(int j = 0 ; j < X->cols ; j++){
            T -> data[j][i] = X->data[i][j];
        }
    }
    
    return T;
}
