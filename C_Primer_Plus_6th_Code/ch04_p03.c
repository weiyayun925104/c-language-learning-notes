#include <stdio.h>

int main(int argc, char **argv)
{
    float n;

    printf("Please enter a floating-point number: ");
    scanf("%f", &n);
    printf("The input is %.1f or %.1e.\n", n, n);
    printf("The input is %+0.3f or %.3E.\n", n, n);
    return 0;
}
