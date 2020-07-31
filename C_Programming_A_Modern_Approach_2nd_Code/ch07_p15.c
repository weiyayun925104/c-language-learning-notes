#include <stdio.h>

int main(int argc, char **argv)
{
    int i, n;
    long double fact = 1.0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = n; i > 1; i--)
    {
        fact *= i;
    }

    printf("Factorial of %d: %Lf\n", n, fact);

    return 0;
}
