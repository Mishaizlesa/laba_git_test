struct p{
    double x;
    double value;
    int num;
};
void table(double (*func)(double,double,int&),double x,double x1,double eps,int &n,int l,int choose,p *&values);

