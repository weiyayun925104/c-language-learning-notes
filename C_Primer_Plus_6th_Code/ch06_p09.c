#include <stdio.h>

double calculation(double a, double b);

int main(int argc, char **argv)
{
    double a, b;

    printf("Please enter one pair floating-point numbers: ");
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        printf("The value of their difference divided by their product is: %f\n", calculation(a, b));
        printf("Please enter another pair floating-point numbers (q to quit): ");
    }
    printf("Done!\n");

    return 0;
}

double calculation(double a, double b)
{
    double difference, product;

    difference = a - b;
    product = a * b;

    return (difference / product);
}
