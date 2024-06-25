#include "stdio.h"

typedef double afunc(double);

extern double f1(double), f1p(double);
extern double f2(double), f2p(double);
extern double f3(double), f3p(double);
extern double integral(afunc *f, double a, double b, double eps2);
extern double root(afunc *f, afunc *fp, afunc *g, afunc *gp, double a, double b, double eps1);
extern int root_test(afunc *f, afunc *fp, afunc *g, afunc *gp, double a, double b, double eps1, int counter);
extern double min(double, double), max(double, double);
extern int get_flags(int argc, char *argv);

int main(int argc, char *argv) 
{
    int flag = get_flags(argc, argv);
    if (flag == 0)
    {
        double x1, x2, x3;
        double eps1 = 0.000001, eps2 = 0.000001;

        x1 = root(f1, f1p, f2, f2p, 0.0, 1.0, eps1);
        x2 = root(f2, f2p, f3, f3p, -1.0, 0.0, eps1);
        x3 = root(f3, f3p, f1, f1p, -1.9, -1.0, eps1);
    
        double I = 0.0;
        I += integral(f1, min(x1, x3), max(x1, x3), eps2);
        I -= integral(f2, min(x1, x2), max(x1, x2), eps2);
        I -= integral(f3, min(x2, x3), max(x2, x3), eps2);

        printf("%lf\n", I);
    }
    if (flag == 1)
    {
        printf("-h --help           displays help\n");
        printf("-r --root           displays points of functions intersections\n");
        printf("-i --iterations     displays number of iteration done to reach needed precision of calculating roots\n");
        printf("-R --test-root      displays points of functions intersections\n");
        printf("-I --test-integral  displays help\n");
        printf("Coded not that well by Stepan Zyznikov\n");
    }
    if (flag == 2)
    {
        double x1, x2, x3;
        double eps1 = 0.000001;

        x1 = root(f1, f1p, f2, f2p, 0.0, 1.0, eps1);
        x2 = root(f2, f2p, f3, f3p, -1.0, 0.0, eps1);
        x3 = root(f3, f3p, f1, f1p, -1.9, -1.0, eps1);
        printf("f1 crosses f2 at x = %lf\nf2 crosses f3 at x = %lf\nf3 crosses f1 at x = %lf\n", x1, x2, x3);
    }
    if (flag == 3)
    {
        int ctr;
        double eps1 = 0.000001;

        ctr = root_test(f1, f1p, f2, f2p, 0.0, 1.0, eps1, 0);
        printf("Number of iterations for x1 = %d\n", ctr);
        ctr = root_test(f2, f2p, f3, f3p, -1.0, 0.0, eps1, 0);
        printf("Number of iterations for x2 = %d\n", ctr);
        ctr = root_test(f3, f3p, f1, f1p, -1.9, -1.0, eps1, 0);
        printf("Number of iterations for x3 = %d\n", ctr);
    }
    return 0;
}