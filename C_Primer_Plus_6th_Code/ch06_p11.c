#include <stdio.h>

#define SIZE 8

int main(int argc, char **argv)
{
    int i, a[SIZE];

    printf("Please enter eight integers: ");
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = SIZE - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
