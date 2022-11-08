#include "Matrix.h"

Matrix MatSum(Matrix *X, Matrix *Y){
    Matrix result;
    if(X->cols != Y->cols || X->rows != Y->rows){//둘 중 하나라도 다를 경우 강제종료
        printf("error : Two matrices do not have the same number of rows, columns\n");
        exit(1);
    }
    result.rows = X->rows;
    result.cols = X->cols;
    result.data = NULL;
    result.data = (int**)calloc(result.rows, sizeof(int*));//행 동적할당
    for(int i = 0 ; i < result.rows ; i++){//열 동적할당
        result.data[i] = (int*)calloc(result.cols, sizeof(int));
    }
    for(int i = 0 ; i < X->rows ; i++){
        for(int j = 0 ; j < X->cols ; j++){
            result.data[i][j] = X->data[i][j]+Y->data[i][j];
        }
    }
    return result;
}

Matrix MatSub(Matrix *X, Matrix *Y){
    Matrix result;
    if(X->cols != Y->cols || X->rows != Y->rows){//둘 중 하나라도 다를 경우 강제종료
        printf("error : Two matrices do not have the same number of rows, columns\n");
        exit(1);
    }
    result.rows = X->rows;
    result.cols = X->cols;
    result.data = NULL;
    result.data = (int**)calloc(result.rows, sizeof(int*));//행 동적할당
    for(int i = 0 ; i < result.rows ; i++){//열 동적할당
        result.data[i] = (int*)calloc(result.cols, sizeof(int));
    }
    for(int i = 0 ; i < X->rows ; i++){
        for(int j = 0 ; j < X->cols ; j++){
            result.data[i][j] = X->data[i][j]-Y->data[i][j];
        }
    }
    return result;
}

Matrix MatMul(Matrix *X, Matrix *Y){
    Matrix result;
    if(X->cols != Y->rows){//X의 열과  Y의 행 수가 다르면 연산 불가
        printf("error : Number of columns in the first matrix and number of rows in the second matrix are different\n");
        exit(1);
    }
    //연산 결과 rows = Xrows & 연산 결과 cols = Ycols
    result.rows = X->rows;
    result.cols = Y->cols;
    result.data = NULL;
    result.data = (int**)calloc(result.rows, sizeof(int*));//행 동적할당
    for(int i = 0 ; i < result.rows ; i++){//열 동적할당
        result.data[i] = (int*)calloc(result.cols, sizeof(int));
    }
    int other = X->cols; //p = Xcols = Yrows
    for(int i = 0 ; i < X->rows ; i++){
        for(int j = 0 ; j < Y->cols ; j++){
            for(int p = 0 ; p < other ; p++){
                result.data[i][j] += X->data[i][p] * Y->data[p][j];
            }
        }
    }
    return result;
}

Matrix MatDiv(Matrix *X, Matrix *Y){
    Matrix result;
    if(X->cols != Y->cols || X->rows != Y->rows){//둘 중 하나라도 다를 경우 강제종료
        printf("error : Two matrices do not have the same number of rows, columns\n");
        exit(1);
    }
    result.rows = X->rows;
    result.cols = X->cols;
    result.fdata = NULL;
    result.fdata = (double**)calloc(result.rows, sizeof(double*));//행 동적할당(double)
    for(int i = 0 ; i < result.rows ; i++){//열 동적할당(double)
        result.fdata[i] = (double*)calloc(result.cols, sizeof(double));
    }
    for(int i = 0 ; i < X->rows ; i++){
        for(int j = 0 ; j < X->cols ; j++){
            result.fdata[i][j] = (double)X->data[i][j]/(double)Y->data[i][j]; //강제형변환
        }
    }
    return result;
}
