//f(x) = 6.7x^4 + 3.2x^3 − x^2 + x − 2, 여기서 x ∈ [−10, 10]
#include <stdio.h>
#include <math.h>

double CalcFunction(double x){
    double result;
    result = 6.7*pow(x,4);
    result += 3.2*pow(x,3);
    result += -1*pow(x,2);
    result += x;
    result += -2;
    return result;
}
int main(int argc, const char * argv[]) {
    int v = 1;
    for(int i = -100 ; i <= 100 ; i++){
        if(CalcFunction(i*0.1) < 0 && v >0){
            v = -1;
            printf("sign changed at %.1f ~ %.1f!!\n", (i-1)*0.1, i*0.1);
        }
        else if(CalcFunction(i*0.1) >= 0 && v <0){
            v = 1;
            printf("sign changed at %.1f ~ %.1f!!\n", (i-1)*0.1, i*0.1);
        }
        printf("x = %.1f, f(x) = %f\n", i*0.1, CalcFunction(i*0.1));
    }
    return 0;
}
