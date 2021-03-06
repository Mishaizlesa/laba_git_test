//
//  mymath.cpp
//  laba_git_test
//
//  Created by Михаил Козлов on 18.10.2021.
//

#include "mymath.h"
#include <stdlib.h>
#define pi 3.14159265359
double my_exp(double x, double eps,int &n) {
    double res = 0;
    n=1;
    double prev=1;
    while (prev>eps) {
        res+=prev;
        prev*=(x/n);
        n++;
    }
    return res;
}
double my_sin(double x,double eps,int &n){
    n=1;
    x-=double(int(x/(pi*2)))*pi*2;
    double res=0;
    double prev=x;
    while (abs(prev)>eps) {
        res+=prev;
        prev*=-1.0*x*x/((2*n)*(2*n+1));
        n++;
    }
    return res;
}
double my_arcsin(double x,double eps,int &n){
    n=1;
    double prev=x;
    double res=prev;
    while (abs(prev)>eps) {
        prev*=((x*x)*(2*n-1)*(2*n-1))/((2*n)*(2*n+1));
        res+=prev;
        n++;
    }
    return res;
}
double my_arccos(double x,double eps,int &n){
    return pi*0.5-my_arcsin(x, eps,n);
}
double my_cos(double x,double eps,int &n){
    return my_sin(pi*0.5-x, eps, n);
}

