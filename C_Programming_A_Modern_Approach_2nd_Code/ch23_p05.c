#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    double a, p, r;
    int t;

    printf("Enter amount deposited: ");
    scanf("%lf", &p);
    printf("Enter interest rate: ");
    scanf("%lf", &r);
    printf("Enter number of years: ");
    scanf("%d", &t);

    r /= 100.0;
    a = p * exp(r * t);

    printf("Total compounded: $ %.2lf\n", a);

    return 0;
}
