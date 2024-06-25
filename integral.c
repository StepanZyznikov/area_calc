#include "stdio.h"

typedef double afunc(double);

double integral(afunc *f, double a, double b, double eps2)
{
    double I, I2, h;

    for (int n = 10; !((n > 20) && ((I - I2) / 3 < eps2)); n*=2) //Два цикла собирает I и I2 для сравнения
    {
        h = (b - a) / n;
        I = I2;
        I2 = 0.0;
        for (int j = 0; j <= n; j++)
        {
            double F = f(a + j * h);
            if (j == 0 || j == n)
                I2 += F/2;
            else
                I2 += F;
        }
        I2 *= h;
    }
    return I2;
}