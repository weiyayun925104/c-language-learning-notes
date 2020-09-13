#include <stdio.h>

double min(double a, double b);

int main(int argc, char **argv)
{
    double x, y;

    printf("Please enter two numbers (q to quit): ");
    while ( scanf("%lf %lf", &x, &y) == 2 )
    {
        printf("The smaller one is %g.\n", min(x, y));
        printf("Please enter two numbers (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

double min(double a, double b)
{
    return ( (a < b) ? a : b );
}
