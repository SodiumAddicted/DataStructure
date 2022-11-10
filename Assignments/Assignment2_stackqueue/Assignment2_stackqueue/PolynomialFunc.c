#include "StackQueue.h"

int isEmpty(Poly *head){
    if(head -> next == NULL){
        return 1;
    }
    return 0;
}

Poly *CreateAbsolPoly(double arr[][2], int count){ //선형리스트를 인풋으로 받아 연결리스트 구현
    Poly *head = CreateNewHead();
    for(int i = 0 ; i < count ; i++){
        head = AddLast(head, arr[i][0], arr[i][1]);
    }
    PolySort(head);
    return head;
}

Poly *CreateNewHead(void){
    Poly *head = NULL;
    head = (Poly*)malloc(sizeof(Poly)); //구조체 동적할당
    head -> next = NULL;
    return head;
}

Poly *AddFirst(Poly *head, double coef, int exp){
    Poly *newpoly = NULL;
    newpoly = (Poly*)malloc(sizeof(Poly)); //구조체 동적할당
    newpoly -> coef = coef;
    newpoly -> exp = exp;
    newpoly -> next = head -> next;
    head -> next = newpoly;
    return head;
}

Poly *AddLast(Poly *head, double coef, int exp){
    Poly *newpoly = NULL;
    Poly *temp;
    newpoly = (Poly*)malloc(sizeof(Poly)); //구조체 동적할당
    newpoly -> coef = coef;
    newpoly -> exp = exp;
    temp = head;
    //마지막 셀로 이동
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newpoly;
    newpoly -> next = NULL;
    return head;
}

Poly *KillFirst(Poly *head){
    Poly *temp;
    if(isEmpty(head)){
        printf("Error : empty input\n");
    }
    else{
        temp = head -> next;
        head -> next = temp -> next;
        free(temp); //힙영역 메모리 해제
    }
    
    return head;
}

Poly *KillLast(Poly *head){
    Poly *target;
    Poly *temp;
    if(isEmpty(head)){
        printf("Error : empty input\n");
    }
    else{
        target = head;
        temp = target;
        while(target -> next != NULL){
            target = target -> next;
            if(target -> next == NULL){
                temp -> next = NULL;
                free(target);
            }
            else{
                temp = target;
            }
        }
    }
    
    return head;
}

void SwapNode(Poly *a, Poly *b){
    double ftemp = a->coef;
    a->coef = b->coef;
    b->coef = ftemp;
    int temp = a->exp;
    a->exp = b->exp;
    b->exp = temp;
}

Poly *PolySort(Poly* head){ //exp기준 정렬
    Poly *target;
    Poly *temp = NULL;
    if(isEmpty(head)){
        printf("Error : empty input\n");
    }
    else{
        int swapped = 0;
        do{
            swapped = 0;
            target = head -> next;
        
            while (target->next != temp){
                if (target->exp < target->next->exp){
                    SwapNode(target, target->next);
                    swapped = 1;
                }
                target = target->next;
            }
            temp = target;
        }while (swapped);
    }
    return head;
}

double GetResult(Poly *head, double n){
    double result = 0;
    Poly *temp;
    if(isEmpty(head)){
        printf("Error : Poly is empty\n");
    }
    else{
        temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
            result += temp -> coef * pow(n,temp -> exp);
        }
    }
    
    return result;
}

void ShowPoly(Poly *head){
    Poly *temp;
    temp = head;
    if(isEmpty(head)){
        printf("Error : Poly is empty\n");
    }
    else{
        printf("+::SHOW POLYNOMIAL::+\n");
        printf("f(x) = ");
        while(temp -> next != NULL){
            temp = temp -> next;
            //다항식 예쁘게
            if (temp -> next != NULL){
                if(temp -> exp == 1){
                    printf("%.1fx", temp -> coef);
                }
                else if(temp -> exp == 0){
                    printf("%.1f", temp -> coef);
                }
                else{
                    printf("%.1fx^%d", temp -> coef, temp -> exp);
                }
                if(temp -> next -> coef > 0){
                    printf(" +");
                }
                else{
                    printf(" ");
                }
            }
            else{
                if(temp -> exp == 1){
                    printf("%.1fx", temp -> coef);
                }
                else if(temp -> exp == 0){
                    printf("%.1f", temp -> coef);
                }
                else{
                    printf("%.1fx^%d", temp -> coef, temp -> exp);
                }
            }
        }
        printf("\n");
    }
}

void PolyFree(Poly *head){
    Poly *temp = head->next;
    while (temp != NULL)
    {
        Poly *next = temp->next;
        free(temp);
        temp = next;
    }
}

double *FindRoot(Poly *head, int start, int end, int div, int n){
    //다항식을 [start,end]구간에서 div수만큼 분리하여 검사하고 부호변화를 통해 f(x)=0에 가까운 x값을 최대 n개 리턴
    if(start >= end){
        printf("오류 : 세번째 인수의 값은 두번째 인수보다 커야합니다.\n");
        return 0;
    }
    double *result;
    result = (double*)calloc(n,sizeof(double));
    int count = 0;
    int sign; //-1음수 1양수
    if (GetResult(head, start) < 0){ //start값이 음수일경우
        sign = -1;
    }
    else{ //start값이 양수일경우
        sign = 1;
    }
    for(double i = start ; i < end ; i += (double)1/div){
        if(count < n){
            if(sign == -1){
                if(GetResult(head, i) > 0){
                    result[count] = i;
                    count++;
                    sign = 1;
                }
            }
            else{//sign == 1
                if(GetResult(head, i) < 0){
                    result[count] = i;
                    count++;
                    sign = -1;
                }
            }
        }
    }
    return result;
    
}

double FindMin(Poly *head, int start, int end, int div){
    //다항식을 [start,end]구간에서 div수만큼 분리하여 검사하고 부호변화를 통해 f(x)가 최소인 x값을 리턴
    if(start >= end){
        printf("오류 : 세번째 인수의 값은 두번째 인수보다 커야합니다.\n");
        return 0;
    }
    double result = GetResult(head, start);
    for(double i = start ; i < end ; i += (double)1/div){
        if(result > GetResult(head, i)){
            result = GetResult(head, i);
        }
    }
    return result;
    
}

