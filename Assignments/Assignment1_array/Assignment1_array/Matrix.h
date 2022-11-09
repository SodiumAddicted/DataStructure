
#ifndef Matrix_h
#define Matrix_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define RAND_RANGE 10
typedef struct matrix{
    int rows;
    int cols;
    int **data;
    double **fdata; //나눗셈을 위한 double형 데이터테이블
}Matrix;

extern int arr1row, arr1col, arr2row, arr2col;
Matrix *CreateRandMatrix(int rows, int cols);
Matrix *CreateRandSparseMatrix(int rows, int cols);
void ShowMatrixDetail(Matrix *X);
void ShowMatrixDetaildouble(Matrix *X);
Matrix *ToSparseMatrix(Matrix *X);
Matrix *ToTransposition(Matrix *X);
Matrix *MatSum(Matrix *X, Matrix *Y);
Matrix *MatSub(Matrix *X, Matrix *Y);
Matrix *MatMul(Matrix *X, Matrix *Y);
Matrix *MatDiv(Matrix *X, Matrix *Y);

#endif /* Matrix_h */
