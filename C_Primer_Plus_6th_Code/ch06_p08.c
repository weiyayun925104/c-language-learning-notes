#include <stdio.h>

int main(int argc, char **argv)
{
    double a, b;
    double difference, product;

    printf("Please enter one pair floating-point numbers: ");
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        difference = a - b;
        product = a * b;
        printf("The value of their difference divided by their product is: %f\n", difference / product);
        printf("Please enter another pair floating-point numbers (q to quit): ");
    }
    printf("Done!\n");

    return 0;
}
