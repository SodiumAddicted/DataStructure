#include "Header.h"




int main(int argc, const char * argv[]) {
    /*
    //-------------------------------------링크드리스트를 활용한 다항식의 덧셈과 뺄셈-------------------------------------
    int size;
    //다항식 입력부
    printf("항의 수 입력:");
    scanf("%d", &size);
    double **myArr1 = InputNewArr(size);
    Poly *head1 = CreateAbsolPoly(myArr1, size);
    
    printf("항의 수 입력:");
    scanf("%d", &size);
    double **myArr2 = InputNewArr(size);
    Poly *head2 = CreateAbsolPoly(myArr2, size);
    
    //다항식 출력부
    printf("첫번째 다항식\n");
    ShowPoly(head1);
    printf("두번째 다항식\n");
    ShowPoly(head2);
    
    Poly *sum = PolySum(head1, head2);
    printf("다항식 덧셈 결과:\n");
    ShowPoly(sum);
    
    Poly *sub = PolySub(head1, head2);
    printf("다항식 뺄셈 결과:\n");
    ShowPoly(sub);
    //----------------------------------------------------------------------------------------------------------
    */
    
    //-------------------------------------선형리스트만을 이용한 다항식의 덧셈과 뺄셈--------------------------------------
    //다항식 입력부
    int size1;
    int size2;
    printf("항의 수 입력:");
    scanf("%d", &size1);
    double **myArr_1 = InputNewArr(size1);
    
    printf("항의 수 입력:");
    scanf("%d", &size2);
    double **myArr_2 = InputNewArr(size2);
    
    printf("첫번째 다항식\n");
    ShowArr(myArr_1, size1);
    printf("두번째 다항식\n");
    ShowArr(myArr_2, size2);
    
    double **resultArr_Sum = SumArr(size1, size2, myArr_1, myArr_2);
    printf("다항식 덧셈 결과:\n");
    ShowArr(resultArr_Sum, size1 + size2);
    
    
    
    double **resultArr_Sub = SubArr(size1, size2, myArr_1, myArr_2);
    printf("다항식 뺄셈 결과:\n");
    ShowArr(resultArr_Sub, size1 + size2);
    
    //----------------------------------------------------------------------------------------------------------
    
    
    
    return 0;
}
