#include <stdio.h>

int main(int argc, char **argv)
{
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("Digits reversed: ");

    do
    {
        printf("%d", n % 10);
        n /= 10;
    }
    while (n != 0);

    printf("\n");

    return 0;
}
