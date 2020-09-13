#include <stdio.h>

void cube(double n);

int main(int argc, char **argv)
{
    double n;

    printf("Please enter a type double number: ");
    scanf("%lf", &n);
    cube(n);

    return 0;
}

void cube(double n)
{
    double cubed;

    cubed = (n * n * n);
    printf("The value of %e cubed is %e.\n", n, cubed);
}
