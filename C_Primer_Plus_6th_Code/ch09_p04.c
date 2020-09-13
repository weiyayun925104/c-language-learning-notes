#include <stdio.h>

double harmonic_mean(double i, double j);

int main(int argc, char **argv)
{
    double i, j;

    printf("Please enter two numbers: ");
    while ( scanf("%lf %lf", &i, &j) == 2 )
    {
        printf("The harmonic mean of %g and %g is %g.\n", i, j, harmonic_mean(i, j));
        printf("Please enter two numbers (q to quit): ");
    }

    printf("Done.\n");

    return 0;
}

double harmonic_mean(double i, double j)
{
    return ( 1 / ( ( (1 / i) + (1 / j) ) / 2 ) );
}
