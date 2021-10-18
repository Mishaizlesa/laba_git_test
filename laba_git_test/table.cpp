#include <stdio.h>
#include <stdlib.h>
struct p{
    double x;
    double value;
    int num;
};
void table(double (*func)(double,double,int&),double x,double x1,double eps,int &n,int l,int choose,
           p *&values){
    double step=abs(x1-x)/(l-1);
    char f[6][10]={"00000","exp(x)","cos(x)","sin(x)","arcsin(x)","arcocs(x)"};
    printf("|     value of x     | %-12s | number of terms\n",f[choose]);
    printf("___________________________________________________\n");
    for (int i=0;i<l;++i){
        printf("| %-18lf | %-12lf | %-16d\n",x,func(x,eps,n),n);
        values[i].x=x;
        values[i].value=func(x,eps,n);
        values[i].num=n;
        printf("___________________________________________________\n");
        x+=step;
    }
}
