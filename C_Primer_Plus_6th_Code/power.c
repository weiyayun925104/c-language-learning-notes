// power.c -- 计算数的整数幂

#include <stdio.h>

double power (double n, int p);

int main(int argc, char **argv)
{
    double x, xpow;
    int exp;

    printf ("Enter a number and the positive integer power or q to quit.\n");
    while (scanf ("%lf %d", &x, &exp) == 2)
    {
        xpow = power(x, exp);
        printf ("%.3g to the power %d is %.6g\n", x, exp, xpow);
        printf ("Enter next number and the positive integer power or q to quit.\n");
    }
    printf ("Hope you enjoyed this power trip -- bye!\n");

    return 0;
}
double power (double n, int p)
{
    double pow = 1.0;
    int i;

    for (i = 1; i <= p; i++)
    {
        pow *= n;
    }

    return pow;
}
