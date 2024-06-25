#include "stdio.h"

typedef double afunc(double);

extern int same_sign(double, double);
extern double min(double, double), max(double, double);

double root(afunc *f, afunc *fp, afunc *g, afunc *gp, double a, double b, double eps1)
{
    double Fa = f(a) - g(a);
    double Fb = f(b) - g(b);
    double c1 = (a*Fb - b*Fa) / (Fb-Fa); // Точка получаемая методом хорд
    double d;
    if (same_sign(Fa, f((a+b)/2)-g((a+b)/2) - (Fa + Fb) / 2))
        d = b;
    else
        d = a;
    double c2 = d - (f(d)-g(d))/(fp(d)-gp(d)); // Точка получаемая методом касательных

    if (-eps1 <= c1 - c2 && c1 - c2 <= eps1)
        return ((c1+c2)/2);
    
    return root(f, fp, g, gp, min(c1, c2), max(c1, c2), eps1);
}