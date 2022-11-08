#include "Matrix.h"

void ShowMatrixDetail(Matrix *X){
    printf("rows : %d, cols : %d \n", X->rows, X->cols);
    for(int i = 0 ; i < X->rows ; i++){
        for(int j = 0 ; j < X->cols ; j++){
            printf("%4d",X->data[i][j]);
        }
        puts("");
    }
    puts("");
}

void ShowMatrixDetaildouble(Matrix *X){
    printf("rows : %d, cols : %d \n", X->rows, X->cols);
    for(int i = 0 ; i < X->rows ; i++){
        for(int j = 0 ; j < X->cols ; j++){
            printf("%7.2f",X->fdata[i][j]);
        }
        puts("");
    }
    puts("");
}
