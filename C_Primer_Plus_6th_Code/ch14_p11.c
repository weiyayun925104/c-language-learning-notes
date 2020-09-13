#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define NUM 2

void transform(double source[], double target[], int num, double (* pf) (double) );

double halve(double x);
double triple(double x);

int main(int argc, char **argv)
{
    double source[NUM] = {3.14159265 / 6.0, 3.14159265 / 3.0};
    double target[NUM] = {0.0, 0.0};

    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
    {
        printf(" %.2f", target[i]);
    }
    printf ("\n");

    transform(source, target, NUM, sin);

    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
    {
        printf(" %.2f", target[i]);
    }
    printf ("\n");

    transform(source, target, NUM, cos);
    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
    {
        printf(" %.2f", target[i]);
    }
    printf ("\n");

    transform(source, target, NUM, halve);
    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
    {
        printf(" %.2f", target[i]);
    }
    printf ("\n");

    transform(source, target, NUM, triple);
    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
    {
        printf(" %.2f", target[i]);
    }
    printf ("\n");

    return 0;
}
void transform(double source[], double target[], int num, double (* pf) (double) )
{
    for (int i = 0; i < num; i++)
    {
        target[i] = (*pf)(source[i]);
    }
}

double halve(double x)
{
    return x / 2;
}

double triple(double x)
{
    return x * 3;
}
