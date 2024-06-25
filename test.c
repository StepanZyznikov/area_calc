#include "stdio.h"
#include "math.h"

typedef double afunc(double);

extern double integral(afunc *f, double a, double b, double eps2);
extern double root(afunc *f, afunc *fp, afunc *g, afunc *gp, double a, double b, double eps1);
extern double min(double, double), max(double, double);

double f1t(double x), f1tp(double x);
double f2t(double x), f2tp(double x);
double f3t(double x), f3tp(double x);


int main(int argc, char *argv) 
{
    double x1, x2, x3;
    double eps1 = 0.000001, eps2 = 0.000001;

    x1 = root(f1t, f1tp, f2t, f2tp, -0.9, 0.0, eps1);
    x2 = root(f2t, f2tp, f3t, f3tp, 0.0, 0.9, eps1);
    x3 = root(f3t, f3tp, f1t, f1tp, -0.5, 0.0, eps1);

    printf("f1t crosses f2t at x = %lf\nf2t crosses f3t at x = %lf\nf3t crosses f1t at x = %lf\n", x1, x2, x3);

    double I = 0.0;
    I += integral(f2t, min(x1, x2), max(x1, x2), eps2);
    I -= integral(f1t, min(x1, x3), max(x1, x3), eps2);
    I -= integral(f3t, min(x2, x3), max(x2, x3), eps2);

    printf("%lf\n", I);
    return 0;
}

double f1t(double x) {
    return x*x;
}
double f1tp(double x){
    return 2*x;
}
double f2t(double x){
    return sqrt(1 - x*x);
}
double f2tp(double x){
    return -x/sqrt(1 - x*x);
}
double f3t(double x){
    return sin(x+0.5);
}
double f3tp(double x){
    return cos(x+0.5);
}