#include "Matrix.h"


int arr1row, arr1col, arr2row, arr2col;
int main(int argc, const char * argv[]) {//HOW TO USE: ./a.out array1row array1col array2row array2col option(sparse)
    if(argc != 5 && argc != 6)
    {
        printf("USAGE : %s arr1row arr1col arr2row arr2col option(option can be omitted)\n", argv[0]);
        printf("OPTIONS : sparse");
    }
    srand((unsigned int)time(0)); //난수화
    
    //argument inputs
    sscanf(argv[1],"%d",&arr1row);
    sscanf(argv[2],"%d",&arr1col);
    sscanf(argv[3],"%d",&arr2row);
    sscanf(argv[4],"%d",&arr2col);
    
    //create matrix
    Matrix mat1;
    Matrix mat2;
    
    //optional array (sparse)
    if(argc == 6 && strcmp( argv[5], "sparse") == 0){ //argc == 6 먼저 검사하기 때문에 오류 해결
        mat1 = CreateRandSparseMatrix(arr1row, arr1col);
        mat2 = CreateRandSparseMatrix(arr2row, arr2col);
    }
    //normal array
    else{
        mat1 = CreateRandMatrix(arr1row, arr1col);
        mat2 = CreateRandMatrix(arr2row, arr2col);
    }
    
    //show matrix
    printf("Matrix1's detail\n");
    ShowMatrixDetail(&mat1);
    printf("Matrix2's detail\n");
    ShowMatrixDetail(&mat2);
    int userinput = 0;
    char option;
    Matrix result;
    while(1){
        printf("| 0 : 종료 | 1 : 덧셈 | 2 : 뺄셈 | 3 : 곱셈 | 4 : 나눗셈 |\n|  5 : 희소행렬형변환  |  6 : 전치행렬화  |  7 : 새로운행렬  |\n");
        printf("INPUT : ");
        scanf("%d", &userinput);
        clock_t start = clock();
        clock_t end;
        switch(userinput){
            case 0:
                printf("프로그램을 종료합니다.\n");
                //힙영역 메모리 해제
                free(mat1.data);
                free(mat2.data);
                free(result.data);
                return 0;
                break;
            case 1:
                result = MatSum(&mat1,&mat2);
                end = clock();
                printf("\nMatrix1 + Matrix2 = \n");
                ShowMatrixDetail(&result);
                break;
            case 2:
                result = MatSub(&mat1,&mat2);
                end = clock();
                printf("\nMatrix1 - Matrix2 = \n");
                ShowMatrixDetail(&result);
                break;
            case 3:
                result = MatMul(&mat1,&mat2);
                end = clock();
                printf("\nMatrix1 * Matrix2 = \n");
                ShowMatrixDetail(&result);
                break;
            case 4:
                result = MatDiv(&mat1,&mat2);
                end = clock();
                printf("\nMatrix1 / Matrix2 = \n");
                ShowMatrixDetaildouble(&result);
                break;
            case 5:
                result = ToSparseMatrix(&mat1);
                end = clock();
                printf("\nMatrix1's sparse formation\n");
                ShowMatrixDetail(&result);
                result = ToSparseMatrix(&mat2);
                printf("\nMatrix2's sparse formation\n");
                ShowMatrixDetail(&result);
                break;
            case 6:
                result = ToTransposition(&mat1);
                end = clock();
                printf("\nMatrix1's transposition formation\n");
                ShowMatrixDetail(&result);
                result = ToTransposition(&mat2);
                printf("\nMatrix2's transposition formation\n");
                ShowMatrixDetail(&result);
                break;
            case 7:
                printf("USAGE : arr1row arr1col arr2row arr2col\n");
                printf("INPUT : ");
                scanf("%d %d %d %d", &arr1row, &arr1col, &arr2row, &arr2col);
                printf("\nOPTIONS : s(sparse)\n");
                printf("any other key : no option\n");
                printf("option? : ");
                scanf("%s", &option);
                //optional array (sparse)
                if(option == 's'){
                    mat1 = CreateRandSparseMatrix(arr1row, arr1col);
                    mat2 = CreateRandSparseMatrix(arr2row, arr2col);
                }
                //normal array
                else{
                    mat1 = CreateRandMatrix(arr1row, arr1col);
                    mat2 = CreateRandMatrix(arr2row, arr2col);
                }

                //show matrix
                printf("Matrix1's detail\n");
                ShowMatrixDetail(&mat1);
                printf("Matrix2's detail\n");
                ShowMatrixDetail(&mat2);
                end = clock();
                break;
            default:
                printf("wrong number\n");
                end = clock();
                break;
                
        }
        printf("소요 시간: %lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    }

    return 0;
}
