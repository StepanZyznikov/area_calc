#include "stdio.h"

typedef double afunc(double);

//Функция для удобного сравнения знаков
int same_sign(double a, double b)
{
    if ((a >= 0.0 && b >= 0.0) || (a <= 0.0 && b <= 0.0))
        return 1;
    else    
        return 0;
}

double min(double a, double b)
{
    if (a < b)
        return a;
    else
        return b;
}

double max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}

int root_test(afunc *f, afunc *fp, afunc *g, afunc *gp, double a, double b, double eps1, int counter)
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
        return counter;
    
    return root_test(f, fp, g, gp, min(c1, c2), max(c1, c2), eps1, counter+1);
}

//Функция для нахождения корня методом хорд (не используется)
double root_h(afunc *f, afunc *g, double a, double b, double eps1)
{
    double Fa = f(a) - g(a);
    double Fb = f(b) - g(b);
    if (-eps1 <= Fb-Fa && Fb-Fa <= eps1)
        return (a+b)/2;
    double c = (a*Fb - b*Fa) / (Fb-Fa);
    if (-eps1 <= f(c) - g(c) && f(c) - g(c) <= eps1)
        return c;
    if (same_sign(Fa, f((a+b)/2)-g((a+b)/2) - (Fa + Fb) / 2))
    {
        if (same_sign(f(c-eps1) - g(c-eps1), f(c) - g(c)))
            return root_h(f, g, c, b, eps1);
        else
            return c;
    }
    else
    {
        if (same_sign(f(c) - g(c), f(c+eps1) - g(c+eps1)))
            return root_h(f, g, a, c, eps1);
        else
            return c;
    }
}

//Функция для нахождения корня методом касательных (не используется)
double root_k(afunc *f, afunc *fp, afunc *g, afunc *gp, double a, double b, double eps1) 
{
    double Fa = f(a) - g(a);
    double Fb = f(b) - g(b);
    double d;
    if (same_sign(Fa, f((a+b)/2)-g((a+b)/2) - (Fa + Fb) / 2))
        d = b;
    else
        d = a;
    
    double c = d - (f(d)-g(d))/(fp(d)-gp(d));
    if (-eps1 <= f(c) - g(c) && f(c) - g(c) <= eps1)
        return c;
    if (same_sign(Fa, f((a+b)/2)-g((a+b)/2) - (Fa + Fb) / 2))
    {
        if (same_sign(f(c) - g(c), f(c+eps1) - g(c+eps1)))
            return root_k(f, fp, g, gp, a, c, eps1);
        else
            return c;
    }
    else
    {
        if (same_sign(f(c-eps1) - g(c-eps1), f(c) - g(c)))
            return root_k(f, fp, g, gp, c, b, eps1);
        else
            return c;
    }
    return 0.0;
}