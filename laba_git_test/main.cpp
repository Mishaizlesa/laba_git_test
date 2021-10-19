#include <iostream>
#include "mymath.h"
#include "p_table.h"
int main() {
    p values_m[10000];
    p *values=values_m;
    int choose=0;
    char ans='1';
    int l,n=0;
    double x,x1,eps;
    x=-10000;
    while(ans!='y' && ans!='n'){
        printf("do you prefer table output y/n? ");scanf("%c",&ans);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        printf("\n");
    }
    if (ans=='y'){
        while(!(choose>0 && choose<6)){
            printf("select the function\n1 exp(x)\n2 cos(x)\n3 sin(x)\n4 arcsin(x)\n5 arccos(x)\n");
            scanf("%d",&choose);
        }
        printf("min value of x=");scanf("%lf",&x);
        printf("max value of x=");scanf("%lf",&x1);
        printf("eps=");scanf("%lf",&eps);
        printf("number of elems in range=");scanf("%d",&l);
        if (choose==1) table(my_exp, x, x1, eps, n, l,choose,values);
        if (choose==2) table(my_cos, x, x1, eps, n, l,choose,values);
        if (choose==3) table(my_sin, x, x1, eps, n, l,choose,values);
        if (choose==4) {
            while(abs(x)>1 || abs(x1)>1){
                if (abs(x)>1) printf("incorrect value of x or x1\n");
                printf("min value of x=");scanf("%lf",&x);
                printf("max value of x=");scanf("%lf",&x1);
                printf("eps=");scanf("%lf",&eps);
                printf("number of elems in range=");scanf("%d",&l);
            }
            table(my_arcsin, x, x1, eps, n, l,choose,values);
        }
        if (choose==5){
            while(abs(x)>1 || abs(x1)>1){
                if (abs(x)>1) printf("incorrect value of x or x1\n");
                printf("min value of x=");scanf("%lf",&x);
                printf("max value of x=");scanf("%lf",&x1);
                printf("eps=");scanf("%lf",&eps);
                printf("number of elems in range=");scanf("%d",&l);
            }
            table(my_arccos, x, x1, eps, n, l,choose,values);
        }
    }
    else{
        while(!(choose>0 && choose<6)){
            printf("select the function\n1 exp(x)\n2 cos(x)\n3 sin(x)\n4 arcsin(x)\n5 arccos(x)\n");
            scanf("%d",&choose);
        }
        printf("x=");scanf("%lf",&x);
        printf("eps=");scanf("%lf",&eps);
        if (choose==1) printf("exp(x)=%lf\nnumber of iterations=%d\n",my_exp(x, eps, n),n);
        if (choose==2) printf("cos(x)=%lf\nnumber of iterations=%d\n",my_cos(x, eps, n),n);
        if (choose==3) printf("sin(x)=%lf\nnumber of iterations=%d\n",my_sin(x, eps, n),n);
        if (choose==4) {
            while(abs(x)>1){
                if (abs(x)>1) printf("incorrect value of x\n");
                printf("x=");scanf("%lf",&x);
                printf("eps=");scanf("%lf",&eps);
            }
            printf("arcsin(x)=%lf\nnumber of iterations=%d\n",my_arcsin(x, eps, n),n);
        }
        if (choose==5){
            while(abs(x)>1){
                if (abs(x)>1) printf("incorrect value of x\n");
                printf("x=");scanf("%lf",&x);
                printf("eps=");scanf("%lf",&eps);
            }
            printf("arccos(x)=%lf\nnumber of iterations=%d\n",my_arccos(x, eps, n),n);
        }
    }
}
