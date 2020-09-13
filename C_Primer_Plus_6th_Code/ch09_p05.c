#include <stdio.h>

void larger_of(double *i, double *j);

int main(int argc, char **argv)
{
    double i, j;

    printf("Please enter two numbers: ");
    while ( scanf("%lf %lf", &i, &j) == 2 )
    {
        larger_of(&i, &j);
        printf("i = %g, j = %g.\n", i, j);
        printf("Please enter two numbers (q to quit): ");
    }

    printf("Done.\n");

    return 0;
}

void larger_of(double *i, double *j)
{
    if ( (*i) > (*j) )
    {
        (*j) = (*i);
    }
    else
    {
        (*i) = (*j);
    }
}
