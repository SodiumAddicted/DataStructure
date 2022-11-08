#include "Matrix.h"

Matrix ToTransposition(Matrix *X){
    Matrix T;
    T.rows = X->cols;
    T.cols = X->rows;
    for(int i = 0 ; i < X->rows ; i++){
        for(int j = 0 ; j < X->cols ; j++){
            T.data[j][i] = X->data[i][j];
        }
    }
    
    return T;
}
