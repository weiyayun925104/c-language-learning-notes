#include <stdio.h>

#define SIZE 8

int main(int argc, char **argv)
{
    int i;
    double fa[SIZE];   // first array
    double sa[SIZE];   // second array

    printf("Please enter eight numbers: ");
    for (i = 0; i < SIZE; i++)
    {
        scanf("%lf", &fa[i]);
    }

    sa[0] = fa[0];
    for (i = 1; i < SIZE; i++)
    {
        sa[i] = fa[i] + sa[i - 1];
    }

    for (i = 0; i < SIZE; i++)
    {
        printf("%9g ", fa[i]);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%9g ", sa[i]);
    }
    printf("\n");

    return 0;
}
