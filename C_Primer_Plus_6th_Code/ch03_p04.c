#include <stdio.h>

int main(void)
{
    double n;

    printf("Enter a floating-point value: ");
    scanf("%lf", &n);
    printf("fixed-point notation: %f\n", n);
    printf("exponential notation: %e\n", n);
    printf("p notation: %a\n", n);

    return 0;
}
