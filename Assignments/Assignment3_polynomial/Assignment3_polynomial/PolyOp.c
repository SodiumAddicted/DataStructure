#include "Header.h"

Poly *PolySum(Poly *head1, Poly *head2){
    Poly *result;
    Poly *temp;
    int head1size = SizeofPoly(head1);
    int head2size = SizeofPoly(head2);
    PolySort(head1);
    PolySort(head2);
    result = (Poly*)malloc(sizeof(Poly*)*(head1size+head2size)); //head1, head2 합만큼 동적할당 (그게 최대이므로)
    
    temp = head1;
    while(temp -> next != NULL){
        temp = temp -> next;
        AddLast(result, temp -> coef, temp -> exp);
    }
    
    temp = head2;
    while(temp -> next != NULL){
        temp = temp -> next;
        AddLast(result, temp -> coef, temp -> exp);
    }
    
    AddupSameExp(result);
    KillAllZero(result);
    return result;
}

Poly *PolySub(Poly *head1, Poly *head2){
    Poly *result;
    Poly *temp;
    int head1size = SizeofPoly(head1);
    int head2size = SizeofPoly(head2);
    PolySort(head1);
    PolySort(head2);
    result = (Poly*)malloc(sizeof(Poly*)*(head1size+head2size)); //head1, head2 합만큼 동적할당 (그게 최대이므로)
    
    temp = head1;
    while(temp -> next != NULL){
        temp = temp -> next;
        AddLast(result, temp -> coef, temp -> exp);
    }
    
    temp = head2;
    while(temp -> next != NULL){
        temp = temp -> next;
        AddLast(result, -(temp -> coef), temp -> exp);
    }
    
    AddupSameExp(result);
    KillAllZero(result);
    return result;
}

