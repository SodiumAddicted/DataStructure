#include "Matrix.h"

Matrix ToSparseMatrix(Matrix *X){
    Matrix S;
    S.rows = 1; //두번째 행부터 채우기(첫번째 행은 인덱스)
    S.cols = 3;
    S.data = NULL;
    int count = 0;
    //필요한 행 수 연산
    for (int i = 0 ; i < X->rows ; i++){
        for (int j = 0 ; j < X->cols ; j++){
            if(X->data[i][j] != 0){
                count++;
            }
        }
    }
    S.data = (int**)calloc(count + 1, sizeof(int*));//행 동적할당
    for(int i = 0 ; i < count + 1 ; i++){//열 동적할당
        S.data[i] = (int*)calloc(3, sizeof(int));
    }
    //
    for (int i = 0 ; i < X->rows ; i++){
        for (int j = 0 ; j < X->cols ; j++){
            if(X->data[i][j] != 0){
                S.data[S.rows][0] = i;
                S.data[S.rows][1] = j;
                S.data[S.rows][2] = X->data[i][j];
                S.rows++; //다음 행으로(for문 종료시 S.rows = 총 행의 수)
            }
        }
    }
    //index 채우기
    S.data[0][0] = X->rows;
    S.data[0][1] = X->cols;
    S.data[0][2] = S.rows-1; //number of elements
    return S;
}
