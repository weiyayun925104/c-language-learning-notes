#include <stdio.h>

double power (double n, int p);

int main(int argc, char **argv)
{
    double x, xpow;
    int exp;

    printf ("Enter a number and the integer power or q to quit.\n");
    while (scanf ("%lf %d", &x, &exp) == 2)
    {
        xpow = power(x, exp);
        printf ("%.3g to the power %d is %.6g\n", x, exp, xpow);
        printf ("Enter a number and the integer power or q to quit.\n");
    }
    printf ("Done.\n");

    return 0;
}
double power(double n, int p)
{
    double pow = 1.0;
    int i;

    if (p > 0)
    {
        for (i = 1; i <= p; i++)
        {
            pow *= n;
        }
        if (n == 0.0)
        {
            pow = 0.0;
        }
    }
    else if (p < 0)
    {
        for (i = -1; i >= p; i--)
        {
            pow /= n;
        }
        if (n == 0.0)
        {
            pow = 0.0;
        }
    }
    else if (p == 0 && n == 0.0)
    {
        printf("0 to the 0 is undefined, and it's using a value of 1.\n");
        pow = 1.0;
    }
    else
    {
        pow = 1.0;
    }

    return pow;
}
