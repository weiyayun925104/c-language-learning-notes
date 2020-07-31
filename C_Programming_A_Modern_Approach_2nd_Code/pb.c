#include <stdio.h>

void pb(int n);

int main(int argc, char **argv)
{
    int n;
    printf("Enter an integer to be translated to binary: ");
    scanf("%d", &n);

    pb(n);
    printf("\n");
    return 0;
}

void pb(int n)
{
    if (n != 0)
    {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}
