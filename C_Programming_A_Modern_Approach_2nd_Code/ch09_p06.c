#include <stdio.h>

int polynomial (int x);
int power (int x, int n);

int main(int argc, char **argv)
{
    int x;

    printf("Enter an integer: ");
    scanf("%d", &x);
    printf("Result: %d\n", polynomial(x));

    return 0;
}

int polynomial(int x)
{
    return (3 * power (x, 5)) + (2 * power (x, 4)) - (5 * power (x, 3)) - (x * x) + (7 * x) - 6;
}
int power (int x, int n)
{
    return n == 0 ? 1 : x * power (x, n - 1);
}
