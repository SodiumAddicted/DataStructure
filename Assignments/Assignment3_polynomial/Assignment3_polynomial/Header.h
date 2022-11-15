#ifndef Header_h
#define Header_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct polynomial{//연결리스트 구현
    struct polynomial *next;
    double coef; //계수
    int exp; //지수
}Poly;

int isEmpty(Poly *head);
int SizeofPoly(Poly *head);
int DoesPolyHaveExp(Poly *head, int exp);
Poly *AddupSameExp(Poly *head);
Poly *CreateAbsolPoly(double **arr, int count);
Poly *CreateNewHead(void);
Poly *AddFirst(Poly *head, double coef, int exp);
Poly *AddLast(Poly *head, double coef, int exp);
Poly *KillFirst(Poly *head);
Poly *KillLast(Poly *head);
Poly *KillAllZero(Poly *head);
void ShowPoly(Poly *head);
void SwapNode(Poly *a, Poly *b);
double GetResult(Poly *head, double n);
Poly *PolySort(Poly* head);
void PolyFree(Poly *head);
double *FindRoot(Poly *head, int start, int end, int div, int n);
double FindMin(Poly *head, int start, int end, int div);

Poly *PolySum(Poly *head1, Poly *head2);
Poly *PolySub(Poly *head1, Poly *head2);

double **InputNewArr(int size);
double **SumArr(int size1, int size2, double **arr1, double **arr2);
double **SubArr(int size1, int size2, double **arr1, double **arr2);
double **SortArr(int size, double **arr);
void ShowArr(double **resultArr, int size);
#endif /* Header_h */
